from cyaron import *
_n=ati([10,25,100,25000,99999])
_m=ati([5,30,200,33333,99999])
_q=ati([10,30,200,33333,99999])
_w=ati([20,35,357,4583,99999])
for i in range(5):
    data=IO(file_prefix="a521_0",data_id=i)
    n=_n[i]
    m=_m[i]
    q=_q[i]
    data.input_writeln(n,m,q)
    for _ in range(m):
        l=randint(1,n)
        r=randint(l,n)
        w=randint(1,_w[i])
        data.input_writeln(l,r,w)
    for _ in range(q):
        l=randint(1,n)
        r=randint(l,n)
        data.input_writeln(l,r)
    data.output_gen("D:/cpp/testcase/a521/ans2.exe")

