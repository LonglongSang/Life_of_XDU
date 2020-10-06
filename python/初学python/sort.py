import functools
class node:
    def __init__(self,a,b):
        self.a=a
        self.b=b
a = [ node(random.randint(1,20),random.randint(1,20)) for i in range(20)]
a.sort(key = lambda x:(x.a,-x.b))
#先按node中a升序排序，若a相同，则按b降序排序
for i in a: print(i.a,i.b)