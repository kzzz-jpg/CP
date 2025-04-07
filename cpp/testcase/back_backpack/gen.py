from cyaron import *

_n = [10, 100, 298, 229, 327, 189, 1000, 1000, 1000, 1000]
_x = [27, 390, 123, 380, 21, 598, 3050, 4121, 2104, 10]

for i in range(10):
    data = IO(file_prefix="random_0", data_id=i)
    n = _n[i]
    x = _x[i]
    data.input_writeln(n, x)
    w = [randint(1, x) for tmp in range(n)]
    data.input_writeln(w)
    data.output_gen("./a.out")
