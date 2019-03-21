import os
import click
import time

points = 0

def wait():
    input("Press ENTER key to continue");

def readFile():
  script_dir = os.path.dirname(__file__)
  file_path = os.path.join(script_dir, './input.txt')
  print(file_path)
  fin = open(file_path, 'r')

  m_n = fin.readline().split(' ')
  m = int(m_n[0])
  n = int(m_n[1])

  ma = []
  print(m,n)
  for i in range(m):
    line = fin.readline().split(' ')
    tmp = []
    for j in line:
      tmp.append(int(j))
    ma.append(tmp)
  
  print(ma)
  tmp = fin.readline().split(' ')
  start_node ={}
  start_node['x'] = int(tmp[0])
  start_node['y'] = int(tmp[1])
  print(start_node)
  fin.close()

  file_path = os.path.join(script_dir, './map.txt')
  print(file_path)
  fin = open(file_path, 'r')

  moves_num = int(fin.readline())
  print(moves_num)
  if (moves_num == 0):
    print('No path to food or pacman chose to stand still')
    exit()

  moves = []
  moves.append(start_node)
  for i in range(moves_num):
    line = fin.readline().split(' ')
    tmp = {}
    tmp['x'] = int(line[0])
    tmp['y'] = int(line[1])
    moves.append(tmp)
  
  fin.close()
  print(moves)
  moves.reverse()

  return ma,start_node,moves

def draw(state,pacman_pos):
  global points
  for i in range(len(state)):
    for j in range(len(state[i])):
      if (pacman_pos['x'] == i and pacman_pos['y'] == j):
        print('p',end=' ')
        continue
      if (state[i][j] == 0):
        print('.',end=' ')
      if (state[i][j] == 1):
        print('x',end=' ')
      if (state[i][j] == 2):
        print('o',end=' ')
    print('')

def animate(mapp,start,moves):
  global points
  click.clear()
  pos = moves.pop()
  if (mapp[pos['x']][pos['y']] == 2):
    points = points + 10
  print(pos)
  print(points)
  draw(mapp,pos)
  points = points - 1

def manual(mapp,start,moves):
  while moves:
    animate(mapp,start,moves)
    wait()
  print('END')

def auto(mapp,start,moves):
  while moves:
    animate(mapp,start,moves)
    time.sleep(1)
  print('END')

def level_menu():
  level = -1
  while not(1 <= level <= 3):
    level = int(input('Choose level (1-3): '))

  script_dir = os.path.dirname(__file__)
  file_path = os.path.join(script_dir, './level.txt')
  print(file_path)
  with open(file_path, 'w+') as fout:
  #fout.write(str(level))
    print(level,file=fout)
  #fout.close()
  print('Wrote %s to level.txt'%level)

def visualize_menu():
  return 0

def main():
  level_menu()
  mapp,start,moves = readFile()
  #visualize_menu()
  wait()
  manual(mapp,start,moves)
  auto(mapp,start,moves)

main()

