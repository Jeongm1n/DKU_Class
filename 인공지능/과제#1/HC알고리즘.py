# 언덕오르기 알고리즘
class State:
    def __init__(self, board, goal):
        self.board = board
        self.goal = goal
        
    def get_new_board(self, i1, i2):
        new_board = self.board[:]
        new_board[i1], new_board[i2] = new_board[i2], new_board[i1]
        return State(new_board, self.goal)
    
    def expand(self):
        result = []
        i = self.board.index(0)
        if not i in [0, 1, 2]:
            result.append(self.get_new_board(i, i-3))
        if not i in [0, 3, 6]:
            result.append(self.get_new_board(i, i-1))
        if not i in [2, 5, 8]:
            result.append(self.get_new_board(i, i+1))
        if not i in [6, 7, 8]:
            result.append(self.get_new_board(i, i+3))
        return result

    def h(self):
        return self.manhattan_distance() + self.hamming_distance()
    
    def manhattan_distance(self):
        distance = 0
        goal = [1,2,3,4,5,6,7,8,0]
        for i in range(1,9):
            xs, ys = self.__i2pos(self.board.index(i))
            xg, yg = self.__i2pos(goal.index(i))
            distance += abs(xs-xg) + abs(ys-yg)
        return distance

    def hamming_distance(self):
        distance = 0
        goal = [1,2,3,4,5,6,7,8,0]
        for i in range(9):
            if goal[i] != self.board[i]: distance += 1
        return distance

    def __str__(self):
        return "------------------ h(n)=" + str(self.h()) +"\n"+\
        str(self.board[:3]) +"\n"+\
        str(self.board[3:6]) +"\n"+\
        str(self.board[6:]) +"\n"+\
        "------------------"
    
    def __i2pos(self, index):
        return (int(index / 3), index % 3)

puzzle = [2, 4, 3,
          1, 0, 6,
          7, 5, 8]

goal = [1, 2, 3,
        4, 5, 6,
        7, 8, 0]

stack = [State(puzzle, goal)]

while stack:
    current = stack.pop()
    print(current)
    if current.board == goal:
        print("탐색 성공")
        break

    next_state = False
    h_val=current.h()
    for state in current.expand():
        h_val_next=state.h()
        print(h_val, h_val_next)
        if h_val_next < h_val:
            next_state = state
            stack.append(next_state)
            break
            
    if not next_state:
        print("탐색 실패")