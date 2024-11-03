from cyaron import *
_n=ati([30,50,80,100,1000,1e4,1e5,158844,2e5,2e5])
for i in range(10):
    data=IO(file_prefix="a539_0",data_id=i)
    n=_n[i]
    k=randint(1,n)
    data.input_writeln(n,k)
    a=[]
    for _ in range(n):
        a.append(randint(-1000000000,1000000000))
    data.input_writeln(a)
    data.output_gen("D:/CP/cpp/testcase/a539/a.exe")
