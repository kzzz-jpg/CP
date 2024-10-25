from cyaron import *


_n=ati([7,200,50,100,1500])
_m=ati([7,200,100,84,1500])
_q=ati([5,100,70,56,99999])

for i in range(0,5):
    test_data = IO(file_prefix="a513_0",data_id=i)

    n=_n[i]
    m=_m[i]
    test_data.input_writeln(n,m)
    for _ in range(n):
        v=Vector.random(m,[(1,n*m)])
        test_data.input_writeln(v)
    q=_q[i]
    test_data.input_writeln(q)
    for _ in range(q):
        x1=randint(1,n-1)
        x2=randint(x1,n)
        y1=randint(1,m-1)
        y2=randint(y1,m)
        test_data.input_writeln(x1,y1,x2,y2)
    test_data.output_gen("D:/cpp/testcase/ans.exe")

