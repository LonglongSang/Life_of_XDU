"""
这个py文件演示了如何使用jupyter notebook
每个juypter的cell由三个符号标识#%%
"""
#%%
print("ok")
class node:
    def __init__(self,val):
        self.arr = [val+i for i in range(10)]
        print("build1")
    def __iter__(self):
        self.cnt = 0
        return self
    def __next__(self):
        if self.cnt == len(self.arr):
            return StopIteration
        else:
            self.cnt += 1
            return self.arr[self.cnt - 1]
a = node(1)
it = iter(a)
while 1:
    b = next(it)
    if b == StopIteration:
        break
    else:
        print(b)
# %%
c = input()
print(c)

# %%
d=5.0
s=3.2
print("直径为{0:.2f}为{1:.3f}圣诞节傻".format(d,s))