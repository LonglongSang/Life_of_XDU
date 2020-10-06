def big_pow(x,y):
    ans = 1
    dev = 10000000
    while y:
        if y % 2 == 1:
            ans = (ans * x) % dev
        x = (x * x) % dev
        y >>= 1
    return ans
print(big_pow(2,10))