from cyaron import *
_n=ati([100,200,500,1000,5000,50000,99999,99999,100000,100000])
_q=ati([150,210,400,1700,7000,48700,99999,1,100000,100000])
for i in range(10):
    data=IO(file_prefix="a540_0",data_id=i)
    n=_n[i]
    q=_q[i]
    data.input_writeln(n,q)
    a=[]
    for _ in range(n):
        a.append(randint(-10**9,10**9))
    data.input_writeln(a)
    for _ in range(q):
        l=randint(1,n)
        r=randint(l,n)
        k=randint(1,r-l+1)
        data.input_writeln(l,r,k)
    data.output_gen("D:/CP/cpp/testcase/a540/a.exe")
