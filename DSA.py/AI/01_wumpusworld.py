import random

class WumpusWorld:
    def __init__(self, size):
        self.size = size
        self.grid = [[0 for _ in range(size)] for _ in range(size)]
        self.player_position = (0, 0)
        self.wumpus_position = (random.randint(0, size - 1), random.randint(0, size - 1))
        self.hazard_positions = [(random.randint(0, size - 1), random.randint(0, size - 1)) for _ in range(size)]

    def print_grid(self):
        for i in range(self.size):
            for j in range(self.size):
                if (i, j) == self.player_position:
                    print("P", end=" ")
                elif (i, j) == self.wumpus_position:
                    print("W", end=" ")
                elif (i, j) in self.hazard_positions:
                    print("H", end=" ")
                else:
                    print("-", end=" ")
            print()

    def move(self, direction):
        x, y = self.player_position
        if direction == 'up' and x > 0:
            self.player_position = (x - 1, y)
        elif direction == 'down' and x < self.size - 1:
            self.player_position = (x + 1, y)
        elif direction == 'left' and y > 0:
            self.player_position = (x, y - 1)
        elif direction == 'right' and y < self.size - 1:
            self.player_position = (x, y + 1)
        else:
            print("Invalid move!")

    def sense(self):
        x, y = self.player_position
        if (x, y) == self.wumpus_position:
            print("You smell a terrible stench!")
        nearby_hazards = [(x-1, y), (x+1, y), (x, y-1), (x, y+1)]
        for pos in nearby_hazards:
            if pos in self.hazard_positions:
                print("You feel a draft!")

size = 5
world = WumpusWorld(size)
while True:
    world.print_grid()
    move = input("Enter your move (up/down/left/right): ")
    world.move(move)
    world.sense()
