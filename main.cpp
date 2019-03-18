#include "header.h"
using namespace std;

int main()
{
    int point=10;
    char*filename="input.txt";
    int** mat;
    int m,n,x,y;
    ifstream fin;
    Getinput(n,m,x,y,mat,fin,filename);
    bool** visited = new bool*[n];
    for(int i=0;i<n;i++)
    {
        visited[i] = new bool [m];
    }
    int **prev = new int*[n];
    /*
        0 = x-1
        1 = y+1
        2 = x+1
        3 = y-1
*/
    for(int i =0;i<n;i++)
    {
        prev[i] = new int [m];
    }
    prev[x][y]=-1;
    cout<<"size of map: ";
    cout<<n<<" "<<m<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"pacman start position: "<<x<<" "<<y<<endl;
    vector<Node> result;
    vector<Node> queuee;
    Node tmp(x,y);
    queuee.push_back(tmp);
    level_one(n,m,mat,result,queuee,visited,prev,point);
    for(int i=result.size()-1;i>=0;i--)
    {
        result[i].get_coordinate();
        cout<<", ";
    }
    cout<<endl;
    cout<<point<<endl;
    for(int i = 0; i < m; ++i) {
    delete [] mat[i];
    }
    delete [] mat;
    for(int i = 0; i < m; ++i) {
    delete [] prev[i];
    }
    delete [] prev;
    for(int i = 0; i < m; ++i) {
    delete [] visited[i];
    }
    delete [] visited;


}
