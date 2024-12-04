while True:
    try:
        x=int(input())
        y=list(str(input()))
        z=int(input())
        bb=0
        cc=[]
        for i in range(z):
            aa=int(input())
            try:
                y[aa-1]='1'
            except:
                aa=1
        for i in y:
            if i=='1':
                bb=bb+1
            else:
                if bb>0:
                    cc.append(bb)
                bb=0
        if bb>0:
            cc.append(bb)
        gg=max(cc)
        kk=min(cc)
        #if kk==gg:
        #    print(kk)
        #else:
        print(kk)
        print(gg)
    except EOFError:
        break