import random

def generate_board(size):
    return [random.randint(0, size-1) for _ in range(size)]

def count_attacks(board):
    size = len(board)
    attacks = 0
    for i in range(size):
        for j in range(i+1, size):
            if board[i] == board[j] or abs(i - j) == abs(board[i] - board[j]):
                attacks += 1
    return attacks

def hill_climbing(size):
    current_board = generate_board(size)
    current_attacks = count_attacks(current_board)
    
    while current_attacks > 0:
        next_board = list(current_board)
        best_move = (current_attacks, current_board)
        
        for col in range(size):
            for row in range(size):
                if current_board[col] != row:
                    next_board[col] = row
                    new_attacks = count_attacks(next_board)
                    if new_attacks < best_move[0]:
                        best_move = (new_attacks, list(next_board))
                    next_board[col] = current_board[col] 
            next_board[col] = current_board[col]  
        
        if best_move[0] < current_attacks:
            current_attacks, current_board = best_move
        else:
            break
    
    return current_board
    
def print_board(board):
    size = len(board)
    for i in range(size):
        row = ['-'] * size
        row[board[i]] = 'Q'
        print(' '.join(row))

if __name__ == "__main__":
    N = 8 
    solution = hill_climbing(N)
    print("Solution found:")
    print_board(solution)