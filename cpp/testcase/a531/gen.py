from cyaron import *
_n=ati([100,2500,5000,60000,70000,99999,100000,150000,200000])
_m=ati([350,5000,12000,75000,120000,130000,150000,230000,400000])
for _ in range(9):
    data=IO(file_prefix="a531_0",data_id=_)
    n=_n[_]
    m=_m[_]
    data.input_writeln(n,m)
    for __ in range(m):
        op=randint(1,2)
        x=randint(1,n)
        y=randint(1,n)
        data.input_writeln(op,x,y)
    data.output_gen("D:/CP/cpp/testcase/a531/a.exe")
data=IO(file_prefix="a531_10")
n=200000
m=399999
data.input_writeln(n,m)
for _ in range(1,n):
    data.input_writeln(1,_,_+1)
for _ in range(n,0,-1):
    data.input_writeln(2,_,_)
data.output_gen("D:/CP/cpp/testcase/a531/a.exe")
