import random
from cyaron import *
_n=[135,5415,1981,45884,5468,18184,12333,46599,79999,99999]
def generate_test_cases(n):
    operations = []
    current_values = set()
    min_value = float('inf')
    max_value = float('-inf')

    for _ in range(100):
            x = random.randint(-10**7, 10**7)
            operations.append((1, x))
            current_values.add(x)
            min_value = min(min_value, x)
            max_value = max(max_value, x)
    for _ in range(n-100):
        opt = random.randint(1, 6)  # 随机选择操作
        if opt == 2:
            if randint(1,100)%4 == 0:
                opt=random.randint(1,6)
        if opt == 1:  # 插入操作
            x = random.randint(-10**7, 10**7)
            operations.append((opt, x))
            current_values.add(x)
            min_value = min(min_value, x)
            max_value = max(max_value, x)

        elif opt == 2:  # 删除操作
            if current_values:  # 确保当前值集合不为空
                x = random.choice(list(current_values))
                operations.append((opt, x))
                current_values.remove(x)
                if not current_values:  # 如果删除后集合为空，重置最大最小值
                    min_value = float('inf')
                    max_value = float('-inf')
            else:
                x = random.randint(-10**7, 10**7)
                operations.append((1, x))
                current_values.add(x)
                min_value = min(min_value, x)
                max_value = max(max_value, x)

        elif opt == 3:  # 查询排名
            x = random.randint(-10**7, 10**7)
            operations.append((opt, x))

        elif opt == 4:  # 查询排名为 x 的数
            x = random.randint(1, len(current_values)) if current_values else 1
            operations.append((opt, x))

        elif opt == 5:  # 前驱查询
            if min_value < float('inf'):
                x = random.randint(min(current_values) + 1, 10**7)
                operations.append((opt, x))
            else:
                print("err")
                x = random.randint(-10**7, 10**7)
                operations.append((opt, x))  # 随机生成一个 x

        elif opt == 6:  # 后继查询
            if max_value > float('-inf'):
                x = random.randint(-10**7, max(current_values)-1)
                operations.append((opt, x))
            else:
                print("err")
                x = random.randint(-10**7, 10**7)
                operations.append((opt, x))  # 随机生成一个 x

    return operations

def main():
    for i in range(10):
        data=IO(file_prefix="a536_0",data_id=i)
        n = _n[i]  # 这里可以修改操作的个数
        data.input_writeln(n)
        test_cases = generate_test_cases(n)
        for operation in test_cases:
            data.input_writeln(operation)
        data.output_gen("D:/CP/cpp/testcase/a536/a.exe")

if __name__ == "__main__":
    main()
