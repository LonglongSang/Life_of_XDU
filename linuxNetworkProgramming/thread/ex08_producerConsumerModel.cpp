#include <unistd.h>

#include <cstdlib>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>

static const int bufSize = 10; // Item buffer size.
static const int ProNum = 20;   // How many items we plan to produce.

struct resource {
	int buf[bufSize]; // 产品缓冲区, 配合 read_pos 和 write_pos 模型环形队列.
	size_t read_pos; // 消费者读取产品位置.
	size_t write_pos; // 生产者写入产品位置.
	std::mutex mtx; // 互斥量,保护产品缓冲区
	std::condition_variable not_full; // 条件变量, 指示产品缓冲区不为满.
	std::condition_variable not_empty; // 条件变量, 指示产品缓冲区不为空.
} instance; // 产品库全局变量, 生产者和消费者操作该变量.

typedef struct resource resource;


void Producer(resource *ir, int item)
{
	std::unique_lock<std::mutex> lock(ir->mtx);
	while (((ir->write_pos + 1) % bufSize)
		== ir->read_pos) { // item buffer is full, just wait here.
		std::cout << "Producer is waiting for an empty slot...\n";
		(ir->not_full).wait(lock); // 生产者等待"产品库缓冲区不为满"这一条件发生.
	}

	(ir->buf)[ir->write_pos] = item; // 写入产品.
	(ir->write_pos)++; // 写入位置后移.

	if (ir->write_pos == bufSize) // 写入位置若是在队列最后则重新设置为初始位置.
		ir->write_pos = 0;

	(ir->not_empty).notify_all(); // 通知消费者产品库不为空.
}

int Consumer(resource *ir)
{
	int data;
	std::unique_lock<std::mutex> lock(ir->mtx);
	// item buffer is empty, just wait here.
	while (ir->write_pos == ir->read_pos) {
		std::cout << "Consumer is waiting for items...\n";
		(ir->not_empty).wait(lock); // 消费者等待"产品库缓冲区不为空"这一条件发生.
	}

	data = (ir->buf)[ir->read_pos]; // 读取某一产品
	(ir->read_pos)++; // 读取位置后移

	if (ir->read_pos >= bufSize) // 读取位置若移到最后，则重新置位.
		ir->read_pos = 0;

	(ir->not_full).notify_all(); // 通知消费者产品库不为满.

	return data; // 返回产品.
}


void ProducerTask() // 生产者任务
{
	for (int i = 1; i <= ProNum; ++i) {
		// sleep(1);
		std::cout << "Produce the " << i << "^th item..." << std::endl;
		Producer(&instance, i); // 循环生产 ProNum 个产品.
	}
}

void ConsumerTask() // 消费者任务
{
	static int cnt = 0;
	while (1) {
		sleep(1);
		int item = Consumer(&instance); // 消费一个产品.
		std::cout << "Consume the " << item << "^th item" << std::endl;
		if (++cnt == ProNum) break; // 如果产品消费个数为 ProNum, 则退出.
	}
}

void Initresource(resource *ir)
{
	ir->write_pos = 0; // 初始化产品写入位置.
	ir->read_pos = 0; // 初始化产品读取位置.
}

int main()
{
	Initresource(&instance);
	std::thread producer(ProducerTask); // 创建生产者线程.
	std::thread consumer(ConsumerTask); // 创建消费之线程.
	producer.join();
	consumer.join();
}
