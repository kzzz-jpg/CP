import numpy as np
from cyaron import *
def is_valid_18x18(board, row, col, num):
    if np.count_nonzero(board[row] == num) >= 2 or np.count_nonzero(board[:, col] == num) >= 2:
        return False

    start_row, start_col = (row // 6) * 6, (col // 6) * 6
    subgrid = board[start_row:start_row + 6, start_col:start_col + 6]
    if np.count_nonzero(subgrid == num) >= 4:
        return False

    return True

def solve_18x18(board):
    for row in range(18):
        for col in range(18):
            if board[row][col] == 0:
                np.random.shuffle(numbers)
                for num in numbers:
                    if is_valid_18x18(board, row, col, num):
                        board[row][col] = num
                        if solve_18x18(board):
                            return True
                        board[row][col] = 0
                return False
    return True

def generate_sudoku():
    board = np.zeros((18, 18), dtype=int)
    global numbers
    numbers = np.arange(1, 10)
    solve_18x18(board)
    return board

for i in range(1,9):
    data=IO(file_prefix="",data_id=i)
    sudoku=generate_sudoku()
    sudoku[randint(0,17)][randint(0,17)]=0
    for x in sudoku:
        data.input_writeln(list(x))
    data.output_gen("D:/CP/cpp/testcase/camp_2_b/ans2.exe")
for i in range(9,21):
    data=IO(file_prefix="",data_id=i)
    sudoku=generate_sudoku()
    if randint(1,3) > 1:
        sudoku[randint(0,8)][randint(0,8)]=0
    else:
        for _ in range(randint(1,10)):
            sudoku[randint(0,17)][randint(0,17)]=randint(1,9)
        sudoku[randint(0,17)][randint(0,17)]=0
    for x in sudoku:
        data.input_writeln(list(x))
    data.output_gen("D:/CP/cpp/testcase/camp_2_b/ans2.exe")