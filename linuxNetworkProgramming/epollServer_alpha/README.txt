编译服务端:
	g++ main.cpp serverA.cpp -lpthread -o main
	
启动服务端：
	./main 5005
	
编译客户端：
	g++ client.cpp -lpthread -o client
	
启动客户端：
	./client 127.0.0.1 5005