todigit = {}
def change(s: str, radix: int)->int:
    ret = 0
    for i in s:
        if todigit[ord(i)]>=radix:
            return -1
        ret = ret * radix + todigit[ord(i)]
    return ret

a,b,c,d = input().split()
if c == 2:
    a, b = b, a
a = change(a, int(d))

for i in range(2,37):
    if(change(b,i)==a):
        print(i)
        exit(0)
print("Impossible")
exit(0)
