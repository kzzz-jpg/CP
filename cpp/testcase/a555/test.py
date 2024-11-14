from cyaron import *
for i in range(10):
    data=IO(file_prefix="a555_0",data_id=i)
    a=randint(1,10000)
    b=randint(0,2*a+100)
    data.input_writeln(a,b)
    data.output_gen("D:/CP/cpp/testcase/a555/a.exe")
for i in range(10):
    data=IO(file_prefix="a555_1",data_id=i)
    a=randint(1,10000)
    b=randint(0,2*a+100)
    data.input_writeln(a,b)
    data.output_gen("D:/CP/cpp/testcase/a555/a.exe")
