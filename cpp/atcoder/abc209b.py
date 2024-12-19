n,k=map(int,input().split())
a=list(map(int,input().split()))
if k<sum(a)-n//2:
    print("No")
else :
    print("Yes")

