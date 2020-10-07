import functools
import random
a = [random.randint(1,100) for i in range(100)]
print(reduce(lambda x,y:x+y,a))
print(sum(a))
#翻转字符串
s = "0000111122223333"
print(reduce(lambda x,y:y+x,s))
        
