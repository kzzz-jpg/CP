from cyaron import *

_n=ati([10,50,3000,5000,9999])
_m=ati([15,75,2500,6500,9999])
_q=ati([20,70,2687,3456,9999])

for i in range(5):
    data=IO(file_prefix="a520_0",data_id=i)
    n=_n[i]
    m=_m[i]
    q=_q[i]
    data.input_writeln(n,m,q)
    tm=m
    tq=q
    for i in range(m+q):
        op=randint(1,2)
        if tm == 0:
            op = 2
        if tq == 0:
            op =1
        if op == 1:
            x=randint(1,n)
            y=randint(x,n)
            w=randint(1,n+m)
            data.input_writeln(1,x,y,w)
        else:
            x=randint(1,n)
            y=randint(x,n)
            data.input_writeln(2,x,y)
    data.output_gen("~/code/a520/a.out")
