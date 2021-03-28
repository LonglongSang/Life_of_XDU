n=int(input())
unbe=-1212323
dp=[unbe for i in range(6)]
dp[0]=0
tsum=0
touch=0
ans=-1

for i in input().split():
    val=int(i)
    tsum=tsum+val
    if dp[(tsum%6+6)%6]==unbe: 
        dp[(tsum%6+6)%6]=tsum
    else:
        if touch==0:
            touch=1
            ans=tsum-dp[(tsum%6+6)%6]
        else:
            if tsum-dp[(tsum%6+6)%6]>ans:
                ans=tsum-dp[(tsum%6+6)%6]
            dp[(tsum%6+6)%6]=min(dp[(tsum%6+6)%6],tsum)
print(ans)

tsum-dp[(tsum%6+6)%6]
    