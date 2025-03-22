from cyaron import *
dir="~/storage/CP/cpp/testcase/a498/a.out"
_n=[20,50,100,100,100,200,200,200]

for i in range(8):
    data=IO(file_prefix="a498_0",data_id=i);
    n=_n[i]
    data.input_writeln(n)
    a=[]
    for _ in range(n):
        a.append(2**randint(0,25))
    data.input_writeln(a)
    data.output_gen(dir)

data8=OI(file_prefix="a498_0",data_id=8)
data8.input_writeln(200)
data8.input_writeln([1]*200)
data8.output_gen(dir)

data9=OI(file_prefix="a498_0",data_id=8)
data.input_writeln()

