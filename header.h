#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include <map>
#include <stdlib.h>
#include <time.h>
using namespace std;
class Node
{
public:
        void get_coordinate()
        {
            cout<<"{"<<x<<", "<<y<<"}";
        }
        int get_x()
        {
            return x;
        }
        int get_y()
        {
            return y;
        }
        Node()
        {
            x=0;
            y=0;
        }
        Node(int a,int b)
        {
            x=a;
            y=b;
        }
        int x;
        int y;

};
template<typename T>
void Vpop_front(vector<T>&a)
{
    a.erase(a.begin()+0);
}
void Getinput (int &n,int &m,int &x, int &y, int** &mat, ifstream &fin, char*filename);
void level_one(int n,int m, int**mat, vector<Node>&res,vector<Node>&queuee,bool** &visited, int** prev,int &point, bool&far);
void level_two(int n,int m, int**mat, vector<Node>&res,vector<Node>&queuee,bool** &visited, int** prev,int &point, bool&far);
void level_three(int n, int m, int **mat,vector<Node>&res,int x,int y,int &point, bool &sudden, int** &maximum_step );
void level_four(int**mat, int px, int py, int gx, int gy,int n,int m, vector<Node>&path,int&point,bool&eatenbyghost,int**maximum_step);
void map_generate(vector<Node>path);
int Min_true_cost(vector<int>a);
void ghost_agent(int&gx,int&gy,int**mat, int px,int py,int n,int m);
void getdistance(int gx,int gy,int px, int py,int&difx, int&dify,int n,int m);
int find_true_cost(int x,int y, int n,int m, int**mat);
#endif // HEADER_H_INCLUDED
