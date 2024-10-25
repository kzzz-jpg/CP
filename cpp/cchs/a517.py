n,m=map(int,input().split())
a=[int(_) for _ in input().split()]
for i in range(m):
    l,r=map(int,input().split())
    ans=0
    for _ in range(l,r+1):
        ans= ans+a[_-1]
    print(ans%10009)

