n,q=map(int,input().split())
a=list(map(int,input().split()))
nw=sum(a)
ans=[]
for i in range(q):
    pos,val=map(int,input().split())
    nw-=a[pos-1]
    a[pos-1]=val
    nw+=val
    ans.append(nw)
print("\n".join(str(i) for i in ans))