n,m=map(int,input().split())
a=[int(_) for _ in input().split()]
for i in range(1,n):
    a[i]+=a[i-1]
for i in range(m):
    l,r=map(int,input().split())
    l-=1
    r-=1
    if l == 0:
        print(a[r]%10009)
    else:
        print((a[r]-a[l-1])%10009)