n=int(input())
if n==0:
    print("Happy Birthday!\n")
else:
    a=list(map(int,input().split()))
    for t in a:
        if t%11==0:
            print("How perfect this plate is!\n")
        else:
            print("Broken\n")

