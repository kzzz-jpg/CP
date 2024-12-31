n=int(input())
A=list()
while n>0:
    m=n%10
    A.append(m)
    n=n//10
k=int(sum(x**len(A) for x in A))
print(k)