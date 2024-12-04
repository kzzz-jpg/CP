from cyaron import *
data=IO(file_prefix="cf172")
data.input_writeln(1)
data.input_writeln(199999,1000000000)
a=str("1")
for i in range(200000//2-1):
    a+="10"
data.input_writeln(a)
