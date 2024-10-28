from cyaron import *
_n=ati([3541,68485,15688,99999,1325588,894111,1784938,1999999,5964187,9999999])
for i in range(10):
    data=IO(file_prefix="a534_0",data_id=i)
    data.input_writeln(_n[i])
    data.output_gen("D:/CP/cpp/testcase/a534/a.exe")
