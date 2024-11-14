from cyaron import *
for i in range(10):
    data=IO(file_prefix="a550_",data_id=i)
    n=randint(10,5000)
    m=randint(1,5000)
    data.input_writeln(n,m)
    data.output_gen("C:/Users/admin/Desktop/code/CP/cpp/testcase/a550/a.exe")
