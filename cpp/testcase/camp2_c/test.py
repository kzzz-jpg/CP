from cyaron import *


# subtask 1 : L=1
for i in range(4):
    data = IO(data_id=i)
    n = randint(10, 200000)
    l = 1
    k = randint(0, 10**9)
    data.input_writeln(n, l, k)
    a = [randint(0, 10**9) for _ in range(n)]
    data.input_writeln(a)
    b = [randint(0, 10**9) for _ in range(n)]
    data.input_writeln(b)
    data.output_gen("~/code/github/CP/cpp/testcase/camp2_c/a.out")

#
for i in range(4,8):
    data = IO(data_id=i)
    n = randint(10, 200000)
    l = randint(1,n)
    k = randint(0, 10**9)
    data.input_writeln(n, l, k)
    a = [randint(0, 10**9) for _ in range(n)]
    data.input_writeln(a)
    b = [randint(0, 10**9) for _ in range(n)]
    data.input_writeln(b)
    data.output_gen("~/code/github/CP/cpp/testcase/camp2_c/a.out")


for i in range(8,16):
    data = IO(data_id=i)
    n = 20000
    l = randint(100,n)
    k = randint(0, 10**9)
    data.input_writeln(n, l, k)
    a = [randint(0, 100) for _ in range(n)]
    data.input_writeln(a)
    b = [randint(0, 100) for _ in range(n)]
    data.input_writeln(b)
    data.output_gen("~/code/github/CP/cpp/testcase/camp2_c/a.out")

data_special_1=IO(data_id=16)
n_1=
