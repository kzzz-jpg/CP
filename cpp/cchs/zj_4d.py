a,b,c=map(int,input().split(','))
d=b**2-4*a*c
if d < 0:
    print("No real root")
elif d == 0:
    print("Two same roots")
    print(int((-b+d**0.5)/(2*a)))
else:
    print("Two different roots")
    print(int((-b+d**0.5)/(2*a)))
    print(int((-b-d**0.5)/(2*a)))
