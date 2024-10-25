from cyaron import *
_n=ati([10,200,3000,40000,99999])
_k=ati([5,80,2760,16778,88888])
for i in range(5):
    n=_n[i]
    k=_k[i]
    data=IO(file_prefix="a528_0",data_id=i)
    data.input_writeln(n,k)
    a=Vector.random(n,[(1,n*10)])
    b=Vector.random(n,[(1,n*10)])
    data.input_writeln(a)
    data.input_writeln(b)
    data.output_gen("D:/cpp/testcase/a528/ans.exe")