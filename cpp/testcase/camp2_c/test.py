from cyaron import *


# subtask 1 : L=1
for i in range(1,5):
    data = IO(file_prefix="",data_id=i)
    n = randint(10, 200000)
    l = 1
    k = randint(0, 10**12)
    data.input_writeln(n, l, k)
    a = [randint(0, 10**6) for _ in range(n)]
    data.input_writeln(a)
    b = [randint(0, 10) for _ in range(n)]
    data.input_writeln(b)
    data.output_gen("D:/CP/cpp/testcase/camp2_c/ans.exe")

#
for i in range(5,9):
    data = IO(file_prefix="",data_id=i)
    n = randint(10, 200000)
    l = randint(1,n)
    k = randint(0, 10**12)
    data.input_writeln(n, l, k)
    a = [randint(0, 10**6) for _ in range(n)]
    data.input_writeln(a)
    b = [randint(0, 10) for _ in range(n)]
    data.input_writeln(b)
    data.output_gen("D:/CP/cpp/testcase/camp2_c/ans.exe")


for i in range(9,17):
    data = IO(file_prefix="",data_id=i)
    n = 20000
    l = randint(100,n)
    k = randint(0, 10**12)
    data.input_writeln(n, l, k)
    a = [randint(0, 1000) for _ in range(n)]
    data.input_writeln(a)
    b = [randint(0, 10) for _ in range(n)]
    data.input_writeln(b)
    data.output_gen("D:/CP/cpp/testcase/camp2_c/ans.exe")

data_special_1=IO(file_prefix="",data_id=17)
n_1=200000
l_1=100000
k_1=10**12
data_special_1.input_writeln(n_1, l_1, k_1)
data_special_1.input_writeln([0 for _ in range(n_1)])
data_special_1.input_writeln([1 for _ in range(n_1)])
data_special_1.output_gen("D:/CP/cpp/testcase/camp2_c/ans.exe")

data_special_2=IO(file_prefix="",data_id=18)
n_2=200000
l_2=100000
k_2=0
data_special_2.input_writeln(n_2, l_2, k_2)
data_special_2.input_writeln([1 for _ in range(n_2)])
data_special_2.input_writeln([1 for _ in range(n_2)])
data_special_2.output_gen("D:/CP/cpp/testcase/camp2_c/ans.exe")

data_special_3=IO(file_prefix="",data_id=19)
n_3=200000
l_3=100000
k_3=10**12
data_special_3.input_writeln(n_3, l_3, k_3)
data_special_3.input_writeln([0 for _ in range(n_3)])
data_special_3.input_writeln([0 for _ in range(n_3)])
data_special_3.output_gen("D:/CP/cpp/testcase/camp2_c/ans.exe")

data_special_4=IO(file_prefix="",data_id=20)
n_4=1
l_4=1
k_4=10**12
data_special_4.input_writeln(n_4, l_4, k_4)
data_special_4.input_writeln([0 for _ in range(n_4)])
data_special_4.input_writeln([1 for _ in range(n_4)])
data_special_4.output_gen("D:/CP/cpp/testcase/camp2_c/ans.exe")