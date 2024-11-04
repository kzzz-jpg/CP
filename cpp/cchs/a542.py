t=int(input())
for __ in range(t):
    a,b,c=map(int,input().split())
    i=1
    while c*i <= a and b > 0:
        b-=1
        a-=c*i
        i+=1
    if b == 0:
        print(a)
    else:
        print(b-1)