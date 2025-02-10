from cyaron import *
import numpy as np

def is_valid(board, row, col, num):
    """檢查 num 放在 (row, col) 是否符合數獨規則"""
    for i in range(9):
        if board[row][i] == num or board[i][col] == num:
            return False

    start_row, start_col = (row // 3) * 3, (col // 3) * 3
    for i in range(3):
        for j in range(3):
            if board[start_row + i][start_col + j] == num:
                return False

    return True

def solve(board):
    """使用回溯法填充數獨"""
    for row in range(9):
        for col in range(9):
            if board[row][col] == 0:
                np.random.shuffle(numbers)
                for num in numbers:
                    if is_valid(board, row, col, num):
                        board[row][col] = num
                        if solve(board):
                            return True
                        board[row][col] = 0
                return False
    return True

def generate_sudoku():
    board = np.zeros((9, 9), dtype=int)
    global numbers
    numbers = np.arange(1, 10)
    solve(board)
    return board

for i in range(1,9):
    data=IO(file_prefix="",data_id=i)
    sudoku=generate_sudoku()
    sudoku[randint(0,8)][randint(0,8)]=0
    for x in sudoku:
        data.input_writeln(list(x))
    data.output_gen("D:/CP/cpp/testcase/camp_2_b/ans.exe")
for i in range(9,21):
    data=IO(file_prefix="",data_id=i)
    sudoku=generate_sudoku()
    if randint(1,3) > 1:
        sudoku[randint(0,8)][randint(0,8)]=0
    else:
        for _ in range(randint(1,10)):
            sudoku[randint(0,8)][randint(0,8)]=randint(1,9)
        sudoku[randint(0,8)][randint(0,8)]=0
    for x in sudoku:
        data.input_writeln(list(x))
    data.output_gen("D:/CP/cpp/testcase/camp_2_b/ans.exe")