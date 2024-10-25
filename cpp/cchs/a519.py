n,m = map(int,input().split())
v = [int(0) for _ in range(n+1)]
for i in range(m):
    l,r,c=map(int,input().split())
    for _ in range(l,r+1):
        v[_]=c;
vs = [int(0) for _ in range(3050)]
ans=0
for i in v:
    if i!=0 and vs[i]==0:
        ans=ans+1
    vs[i]=vs[i]+1
print(ans)
