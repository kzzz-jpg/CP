from cyaron import *
_n=ati([100,1000,10000,1e5,1e5,1e5,1e5,1e5,1e5,1e5])
_m=ati([151,5611,64161,3e5,4e5,5e5,5e5,5e5,5e5,5e5])
for i in range(10):
    data=IO(file_prefix="a537_0",data_id=i)
    n=_n[i]
    m=_m[i]
    data.input_writeln(n,m)
    g=Graph.graph(n,m)
    for ed in g.iterate_edges():
        data.input_writeln(ed.start,ed.end)
    data.output_gen("D:/CP/cpp/testcase/a537/a.exe")
