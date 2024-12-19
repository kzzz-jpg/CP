n=int(input())
a=list(map(int,input().split()))
P=int(1e9+7)
a.sort()
ans=1
for i in range(n):
    ans=(ans*(a[i]-i))%P
print(ans)

