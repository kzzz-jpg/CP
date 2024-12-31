n=int(input())
ans=0
for i in range(1,n+1):
    for j in range(1,n+1):
        if i*j>k:
            break
        for k in  range(1,n+1):
            if i*j*k>n:
                break
            ans+=1
print(ans)
