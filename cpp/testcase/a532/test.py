from cyaron import *
_n=ati([100,500,6848,9999,99999,199999,299999,399999,499999,500000])
for i in range(10):
    data=IO(file_prefix="a532_0",data_id=i)
    n=_n[i]
    data.input_writeln(n)
    a=[]
    for _ in range(n):
        a.append(randint(1,999999999))
    data.input_writeln(a)
    data.output_gen("D:/CP/cpp/testcase/a532/a.exe")
