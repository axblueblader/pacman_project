import os
import click
import time
import shutil

points = 0
script_dir = os.path.dirname(__file__)
def wait():
    input("Press ENTER key to continue");

def readFile():
  global script_dir
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
      if (state[i][j] == 3):
        print('#',end=' ')
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

def map_menu():
  file_path = input('File to test (e.g: ./tests/level1/input1.txt): ')
  assert os.path.exists(file_path), "I did not find the file at, "+str(file_path)
  return file_path

def copy_input(file_path):
  src_path = os.path.normpath(file_path)  
  dest_path = os.path.join(script_dir, './input.txt')  
  shutil.copyfile(src_path,dest_path)

def level_menu():
  global script_dir
  level = -1
  while not(1 <= level <= 3):
    level = int(input('Choose level (1-3): '))

  file_path = os.path.join(script_dir, './level.txt')
  print(file_path)
  with open(file_path, 'w+') as fout:
  #fout.write(str(level))
    print(level,file=fout)
  #fout.close()
  print('Wrote %s to level.txt'%level)

def visualize_menu():
  choice = -1
  print('')
  while not(1 <= choice <= 2):
    choice = int(input('Choose draw method (1-auto,2-manual):'))
  return choice

def main():
  global script_dir
  input_file = map_menu()
  copy_input(input_file)
  level_menu()
  print('Running agent')
  bin_path = os.path.join(script_dir,'./bin/Pac_man')
  os.system(bin_path)  
  mapp,start,moves = readFile()
  choice = visualize_menu()
  if choice == 2:
    manual(mapp,start,moves)
  if choice == 1:
    auto(mapp,start,moves)

main()

