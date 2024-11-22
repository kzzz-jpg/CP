import sys
n=int(input())
cin=list(map(int,sys.stdin.readlines()))
for i in range(n):
    a=cin[i]
    l=1
    r=50
    while(l<r):
        mid=(l+r)>>1
        if(1<<(mid)>=a):
            r=mid
        else:
            l=mid+1
    print(l)
