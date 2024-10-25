from cyaron import *
_n=ati([10,25,100,25000,99999])
_m=ati([5,30,200,33333,99999])
for i in range(5):
    data=IO(file_prefix="a520_0",data_id=i)
    n=_n[i]
    m=_m[i]
    data.input_writeln(n,m)
    for i in range(m):
        l=randint(1,n)
        r=randint(l,n)
        w=randint(1,n+m)
        data.input_writeln(l,r,w)
    data.output_gen("D:/cpp/testcase/a520/ans.exe")

