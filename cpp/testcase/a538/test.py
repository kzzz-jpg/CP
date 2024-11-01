from cyaron import *
_n=ati([50,80,1656,15656,1e5,1e5,1e5,1e5,1e5,1e5])
_m=ati([70,120,2013,21505,2e5,2e5,2e5,2e5,2e5,2e5])
for i in range(10):
    data=IO(file_prefix="a538_0",data_id=i)
    n=_n[i]
    m=_m[i]
    data.input_writeln(n)
    g=Graph.DAG(n,m)
    a=[[] for _ in range(n)]
    for ed in g.iterate_edges():
        a[ed.start-1].append(ed.end)
    for nd in a:
        data.input_writeln(len(nd),nd)
    data.output_gen("D:/CP/cpp/testcase/a538/a.exe")
