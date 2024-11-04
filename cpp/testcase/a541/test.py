from cyaron import *
'''
_n = ati([50,100,1000,10000,1e5,1e5,1e5,1e5,1e5,1e5])
_k = ati([30,80,800,12000,15000,80000,1e5,2e5,2e5,2e5])
for i in range(10):
    data=IO(file_prefix="a541_0",data_id=i)
    n=_n[i]
    k=_k[i]
    data.input_writeln(n,k)
    for _ in range(n):
        x=randint(1,k)
        y=randint(1,k)
        z=randint(1,k)
        data.input_writeln(x,y,z)
    data.output_gen("D:/CP/cpp/testcase/a541/a.exe")
'''
data=IO(file_prefix="a541_16")
n=int(1e5)
k=2
data.input_writeln(n,k)
for i in range(n):
    x=randint(1,k)
    y=randint(1,k)
    z=randint(1,k)
    data.input_writeln(x,y,z)
data.output_gen("D:/CP/cpp/testcase/a541/a.exe")
