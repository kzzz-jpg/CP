from cyaron import *
_q=ati([20,500,300,40000,90000,1e5,1e5,1e5,1e5,1e5])
for i in range(10):
    data=IO(file_prefix="a559_0",data_id=i)
    q=_q[i]
    data.input_writeln(q)
    for _ in range(q):
        k=randint(1,1000000000000000)
        data.input_writeln(k)
    data.output_gen("C:/Users/admin/Desktop/code/CP/cpp/testcase/a559/a.exe")
