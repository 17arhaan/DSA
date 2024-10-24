import random

class WumpusWorld:
    def __init__(self, size):
        self.size = size
        self.grid = [['-' for _ in range(size)] for _ in range(size)]
        self.player_position = (0, 0)
        self.wumpus_position = (random.randint(0, size - 1), random.randint(0, size - 1))
        self.hazard_position = [(random.randint(0, size - 1), random.randint(0, size - 1)) for _ in range(size)]
        self.gold_position = (random.randint(0, size - 1), random.randint(0, size - 1))

    def print_grid(self):
        for i in range(self.size):
            for j in range(self.size):
                if (i, j) == self.player_position:
                    print("P", end="")
                elif (i, j) == self.wumpus_position:
                    print("W", end="")
                elif (i, j) in self.hazard_position:
                    print("H", end="")
                elif (i, j) == self.gold_position:
                    print("G", end="")
                else:
                    print("-", end="")
            print()

    def move(self, direction):
        x, y = self.player_position
        if direction.lower() == 'up' and x > 0 and (x - 1, y) not in self.hazard_position:
            self.player_position = (x - 1, y)
        elif direction.lower() == 'down' and x < self.size - 1 and (x + 1, y) not in self.hazard_position:
            self.player_position = (x + 1, y)
        elif direction.lower() == 'left' and y > 0 and (x, y - 1) not in self.hazard_position:
            self.player_position = (x, y - 1)
        elif direction.lower() == 'right' and y < self.size - 1 and (x, y + 1) not in self.hazard_position:
            self.player_position = (x, y + 1)
        else:
            print("Invalid Move")

    def sense(self):
        x, y = self.player_position
        game_over = False
        if (x, y) == self.wumpus_position:
            print("You smell a terrible stench!!")
            print("Game Over , better luck next time")
            game_over = True
        nearby_hazards = [(x - 1, y), (x + 1, y), (x, y - 1), (x, y + 1)]
        for pos in nearby_hazards:
            if pos in self.hazard_position:
                print("You feel a draft...")
        if (x, y) == self.gold_position:
            print("You found the gold! You win!")
            game_over = True
        return game_over

if __name__ == "__main__":
    size = 5
    world = WumpusWorld(size)
    print("Moves: Up | Down | Left | Right")
    while True:
        world.print_grid()
        move = input("Enter Your Move: ")
        if move.lower() == 'quit':
            print("Game over. Thanks for playing!")
            break
        world.move(move)
        if world.sense():
            break