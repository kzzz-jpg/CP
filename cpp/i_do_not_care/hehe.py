print((lambda a,b: "At School" if a*60+b>=450 and a*60+b<1020 else "Off School")(*list(map(int,input().split()))))
