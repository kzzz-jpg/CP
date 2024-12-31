from cyaron import *
alp=['L','R','U','D']
cppdir="D:/CP/cpp/testcase/apcsc13B/ans.exe"
for i in range(1,5):
    data=IO(file_prefix="",data_id=i)
    n=randint(1,30)
    m=randint(1,30)
    k=1
    t=randint(0,30)
    data.input_writeln(n,m,k,t)
    x=randint(1,n)
    y=randint(1,m)
    data.input_writeln(x,y)
    op=""
    for _ in range(t):
        op+=alp[randint(0,3)]
    data.input_writeln(op)
    data.output_gen(cppdir)
for i in range(5,9):
    data=IO(file_prefix="",data_id=i)
    n=randint(1,30)
    m=randint(1,30)
    k=randint(1,30)
    t=0
    data.input_writeln(n,m,k,t)
    for _ in range(k):
        x=randint(1,n)
        y=randint(1,m)
        data.input_writeln(x,y)
        data.input_writeln("")
    data.output_gen(cppdir)
for i in range(9,15):
    data=IO(file_prefix="",data_id=i)
    n=randint(1,30)
    m=randint(1,30)
    k=randint(1,30)
    t=randint(0,30)
    data.input_writeln(n,m,k,t)
    for _ in range(k):
        x=randint(1,n)
        y=randint(1,m)
        data.input_writeln(x,y)
        op=""
        for j in range(t):
            op+=alp[randint(0,3)]
        data.input_writeln(op)
    data.output_gen(cppdir)
for i in range(15,21):
    data=IO(file_prefix="",data_id=i)
    n=randint(20,30)
    m=randint(20,30)
    k=randint(20,30)
    t=randint(20,30)
    data.input_writeln(n,m,k,t)
    for _ in range(k):
        x=randint(1,n)
        y=randint(1,m)
        data.input_writeln(x,y)
        op=""
        for j in range(t):
            op+=alp[randint(0,3)]
        data.input_writeln(op)
    data.output_gen(cppdir)
