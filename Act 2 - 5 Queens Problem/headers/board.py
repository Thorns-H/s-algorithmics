import time
import os

def dif_between(a: int, b: int):
    if a < b:
        return b - a
    else:
        return a - b

class Table:
    def __init__(self, queens: int) -> None:
        self.table: list = []
        self.length: int = queens
        
        for i in range(1, queens + 1):
            self.table.append([i, 1])

    def __str__(self) -> str:

        table: str = '\n\t\t\t\t'
        
        for queen in self.table:
            for i in range(1, self.length + 1):
                if queen[1] != i:
                    table = table + "- "
                else:
                    table = table + "♕ "
            table = table + '\n\t\t\t\t'

        output: str = f'\t\t\t       Chess Board{table}\n   • Positions: '

        for position in self.table:
            output = output + '♕ (' + str(position[0]) + ', ' + str(position[1]) + ') - '

        output = output[:-3]
        output = output + f'\n   • Queens: {self.length}'

        return output

    def start(self) -> None:
        
        game_finished: bool = False
        horizontal: bool = True
        last_case: list = [[1,5], [2,5], [3,5], [4,5], [5,5]]
        iterations: int = 1
        solutions: int = 0

        while not game_finished:

            if self.table[self.length - 1][1] > 4:
                self.table[self.length - 2][1] += 1
                self.table[self.length - 1][1] = 1
            else:
                self.table[self.length - 1][1] += 1

            if self.table[self.length - 2][1] > 5:
                self.table[self.length - 2][1] = 1
                self.table[self.length - 3][1] += 1

            if self.table[self.length - 3][1] > 5:
                self.table[self.length - 3][1] = 1
                self.table[self.length - 4][1] += 1

            if self.table[self.length - 4][1] > 5:
                self.table[self.length - 4][1] = 1
                self.table[self.length - 5][1] += 1

            if self.table == last_case:
                game_finished = True

            iterations += 1
            
            time.sleep(0.02)
            os.system("cls")
            print(f'{self}\n   • Counter: {iterations}, Solutions Found: {solutions}')
            print(f'   • Vertical: {self.check_vertical()}, Diagonal: {self.check_diagonal()}, Horizontal: {horizontal}')

            if horizontal and self.check_diagonal() and self.check_vertical():
                solutions += 1
                input()
            
    def check_vertical(self) -> bool:

        vertical: bool = False
        vertical_cmp: list = []
        position: int = 1

        for i in range(self.length):
            vertical_cmp.append(self.table[i][1])

        for i in range(self.length, 0, -1):
            vertical_cmp.remove(self.table[i - 1][1])
            if not self.table[i - 1][1] in vertical_cmp:
                vertical_cmp.append(self.table[i - 1][1])
                position += 1
                if position == self.length:
                    vertical = True
            else:
                return False

        return vertical

    def check_diagonal(self) -> bool:

        diagonal_cmp: list = []
        iteration_right: int = 0
        iteration_left: int = 0

        for queen in self.table:

            for i in range(self.length):
                if not self.table[i] == queen:
                    diagonal_cmp.append(self.table[i].copy())

            for piece in diagonal_cmp:
                if queen[0] < piece[0]:
                    if piece[1] - dif_between(queen[0], piece[0]) == queen[1]:
                        return False
                else:
                    if piece[1] + dif_between(queen[0], piece[0]) == queen[1]:
                        return False

                iteration_right += 1
                    
            for piece in diagonal_cmp:
                if queen[0] < piece[0]:
                    if piece[1] + dif_between(queen[0], piece[0]) == queen[1]:
                        return False
                else:
                    if piece[1] - dif_between(queen[0], piece[0]) == queen[1]:
                        return False
                    
                iteration_left += 1
                    
            diagonal_cmp.clear()

        if iteration_right >= len(diagonal_cmp) * 4 and iteration_left >= len(diagonal_cmp) * 4:
            return True