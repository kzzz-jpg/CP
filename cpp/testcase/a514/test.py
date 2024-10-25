from cyaron import *
_n=ati([10,20,50,100,300])
_m=ati([60,120,340,3800,42357])
_q=ati([10,60,600,9000,19999])
for i in range(5):
    data_case=IO(file_prefix="a516_0",data_id=i)
    n=_n[i]
    m=_m[i]
    q=_q[i]
    data_case.input_writeln(n,m,q)
    my_graph = Graph.graph(n,m,weight_limit = n+m)
    for edges in my_graph.iterate_edges():
        data_case.input_writeln(edges)
    for _ in range(q):
        x=randint(1,n)
        y=randint(1,n)
        data_case.input_writeln(x,y)
    data_case.output_gen("D:/cpp/testcase/a514/ans.exe")