from cyaron import *
_q=ati([10,300,5000,7000,90000,1e5,1e5,1e5,1e5,1e5])
for i in range(10):
    data=IO(file_prefix="a558_0",data_id=i)
    q=_q[i]
    data.input_writeln(q)
    for _ in range(q):
        a=randint(1,100000)
        b=randint(1,100000)
        k=randint(1,1000000000)
        data.input_writeln(a,b,k)
    data.output_gen("C:/Users/admin/Desktop/code/CP/cpp/testcase/a558/a.exe")
