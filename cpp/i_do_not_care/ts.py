x=int(input())
y=list(map(int,input().split(" ")))
friend=[0]*x #0表還沒
gg=0
for i in range(x):
  if friend[i]==0:
    have_friend=i
    while friend[have_friend]==0:
        friend[have_friend]=1 #1表有了
        have_friend=y[have_friend]
    gg=gg+1
print(gg)