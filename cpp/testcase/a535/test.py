from cyaron import *
_op=[1,1,2,2,3,3,4,4,5,5,6,6,7,7]
_n=[randint(2,1000),randint(2,1000),randint(2,1000),randint(2,1000),randint(2,1000),randint(2,1000),randint(2,100),randint(2,100),randint(2,100),randint(2,100),randint(2,100),randint(2,100),randint(2,100),randint(2,100)]
_m=[randint(2,1000),randint(2,1000),randint(2,1000),randint(2,1000),randint(2,1000),randint(2,1000),randint(2,100),randint(2,100),randint(2,100),randint(2,100),randint(2,100),randint(2,100),_n[12],_n[13]]
for i in range(14):
    data=IO(file_prefix="a535_0",data_id=i)
    op=_op[i]
    n=_n
    m=_m
    data.input_writeln(op,n,m)
    for _ in range(n):
        a=[]
        for __ in range(m):
            a.append(randint(-40000,40000))
        data.input_writeln(a)
    if op == 1 or op == 2:
        data.input_writeln(randint(-40000,40000))
    elif op == 3:
        data.input_writeln(randint(2,40000))
    elif op == 4 or op == 5:
        for _ in range(n):
            a=[]
            for __ in range(m):
                a.append(randint(-40000,40000))
            data.input_writeln(a)
    elif op == 6:
        p=m
        q=randint(2,100)
        data.input_writeln(p,q)
        for _ in range(p):
            a=[]
            for __ in range(q):
                a.append(randint(-40000,40000))
            data.input_writeln(a)
    else:
        k=randint(1,100000000000000)
        p=randint(2,1000000007)
        data.input_writeln(k,p)
    data.output_gen("D:/CP/cpp/testcase/a535/a.exe")
