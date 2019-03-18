#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include <map>
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
private:
        int x;
        int y;

};
template<typename T>
void Vpop_front(vector<T>&a)
{
    a.erase(a.begin()+0);
}
void Getinput (int &n,int &m,int &x, int &y, int** &mat, ifstream &fin, char*filename);
void level_one(int n,int m, int**mat, vector<Node>&res,vector<Node>&queuee,bool** &visited, int** prev,int &point);
#endif // HEADER_H_INCLUDED
