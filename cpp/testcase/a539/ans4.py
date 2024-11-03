n,k=map(int,input().split())
a=[int(x) for x in input().split()]
def getn(x):
    ret=0
    for _ in a:
        if _ <= x:
            ret+=1
    return ret
l=int(-1e9)
r=int(1e9)
while(l<r):
    mid=(l+r)>>1
    if(getn(mid)<k):
        l=mid+1
    else:
        r=mid
for i in range(n):
    if a[i] == l:
        print(l,i+1)
        break
