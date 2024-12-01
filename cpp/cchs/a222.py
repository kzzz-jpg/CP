a=int(float(input())*1000)
b=int(float(input())*1000)
c=int(float(input())*1000)
d=int(float(input())*1000)
e=int(float(input())*1000)
f=int(float(input())*1000)
g=int(float(input())*1000)
h=int(float(input())*1000)
ans=(a+b+c)*4+(d+e+f)*2+(g+h)
ans//=20
if ans%1000==0:
    print(a//1000)
else:
    print(ans/1000)
