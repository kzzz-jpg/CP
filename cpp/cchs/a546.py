n=int(input())
ans=1
nw=9
while n>0:
    if n&1==1:
        ans=(ans*nw)%100
    nw=(nw*nw)%100
    n>>=1
print(ans)
