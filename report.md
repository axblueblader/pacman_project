# PACMAN PROJECT

# Authors
- Lê Trung Kiên <ltkien@apcs.vn>
- Nguyễn Quốc Việt <nqviet@apcs.vn>

## INPUT
- The user will provide the maps with N M, position of elements and pacman starting position in a text file named "input.txt"
- User will be able to choose which level to execute the program from a console screen.

## OUTPUT
- After the program finish, the user can view a graphical representation of how Pacman moves on the console screen.
- User can also view additional information in a file named "output.txt"
- The level chosen will also be written to a "level.txt" file

## TOOlS
- We wrote our main business logic using C++ and output results to files
- For the console driver application we used Python instead. The user will mainly interact with this program.

## IDEAS

### Level 1

#### Algorithm
- Since we know everything on the map and the cost of moving is constant, we can use Breadth First Search to figure out the shortest way to reach the food.
- However, if the food is too far away, the cost overweights the profit, we will choose to stand still and not move at all.
#### Results

#### Pros
- Easy implementation
#### Cons
- High memory cost
