#include "header.h"
void map_generate(vector<Node>path)
{
    ofstream fout;
    fout.open("map.txt");
    {
        fout<<path.size()-1<<endl;

        for(int i=path.size()-2;i>=0;i--)
        {
            fout<<path[i].x<<" "<<path[i].y<<endl;
        }
    }
    fout.close();
}
void Getinput (int &n,int &m,int &x, int &y, int** &mat, ifstream &fin, char*filename)
{
    fin.open(filename);
    fin>>n>>m;
    mat=new int*[n];
    for(int i=0;i<n;i++)
    {
        mat[i]=new int[m];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            fin>>mat[i][j];
        }
    }
    fin>>x>>y;
    fin.close();
}
void level_one(int n,int m, int**mat, vector<Node>&res,vector<Node>&queuee,bool** &visited, int** prev,int &point,bool&far)
{
bool eaten=false;
int x;
int y;
int x_start = queuee[0].get_x();
int y_start = queuee[0].get_y();
int xx,yy;
while (queuee.size()>0 && eaten == false )
{
x = queuee[0].get_x();
y = queuee[0].get_y();
Vpop_front(queuee);
int step=0;
while(step <4 && eaten==false)
    {
        switch(step)
        {
        case 0:
            {
                if((x-1)>=0)
                {
                    xx=x-1;
                if(mat[xx][y]!=1 && visited[xx][y]==false)
                {
                    visited[xx][y]=true;
                    Node tmp(xx,y);
                    if(mat[xx][y]==2)
                    {
                        point+=10;
                        eaten=true;
                        res.push_back(tmp);
                    }
                    queuee.push_back(tmp);
                    prev[xx][y]=0;
                }
                }
                step++;
                break;
            }
        case 1:
            {
                if((y+1)<m)
                {
                    yy=y+1;
                if(mat[x][yy]!=1 && visited[x][yy]==false)
                {
                    visited[x][yy]=true;
                    Node tmp(x,yy);
                    if(mat[x][yy]==2)
                    {
                        point+=10;
                        eaten=true;
                        res.push_back(tmp);
                    }
                    queuee.push_back(tmp);
                    prev[x][yy]=1;
                }
                }
                step++;
                break;
            }
        case 2:
            {
            if((x+1)<n)
                {
                    xx=x+1;
                if(mat[xx][y]!=1 && visited[xx][y]==false)
                {
                    visited[xx][y]=true;
                    Node tmp(xx,y);
                    if(mat[xx][y]==2)
                    {
                        point+=10;
                        eaten=true;
                        res.push_back(tmp);
                    }
                    queuee.push_back(tmp);
                    prev[xx][y]=2;
                }
                }
                step++;
                break;
            }
        case 3:
        {
          if((y-1)>=0)
            {
                yy=y-1;
            if(mat[x][yy]!=1 && visited[x][yy]==false)
            {
                visited[x][yy]=true;
                Node tmp(x,yy);
                if(mat[x][yy]==2)
                {
                    point+=10;
                    eaten=true;
                    res.push_back(tmp);
                }
                queuee.push_back(tmp);
                prev[x][yy]=3;
            }
            }
            step++;
            break;
        }
        default: break;
        }
    }

}


if (eaten==true)
{
    xx = res[0].get_x();
    yy = res[0].get_y();
    int tmpx=xx;
    int tmpy=yy;
    while (tmpx != x_start || tmpy != y_start )
    {
        if (prev[tmpx][tmpy]==0)
        {
            tmpx=tmpx+1;
            Node tmp(tmpx,tmpy);
            res.push_back(tmp);
        }
        else if(prev[tmpx][tmpy]==1)
        {
            tmpy=tmpy-1;
            Node tmp(tmpx,tmpy);
            res.push_back(tmp);
        }
        else if(prev[tmpx][tmpy]==2)
        {
            tmpx=tmpx-1;
            Node tmp(tmpx,tmpy);
            res.push_back(tmp);
        }
        else if(prev[tmpx][tmpy]==3)
        {
            tmpy=tmpy+1;
            Node tmp(tmpx,tmpy);
            res.push_back(tmp);
        }
        point--;
    }
}
if(point<=10) far=true;
return;
}
void level_two(int n,int m, int**mat, vector<Node>&res,vector<Node>&queuee,bool** &visited, int** prev,int &point, bool&far)
{
bool eaten=false;
int x;
int y;
int x_start = queuee[0].get_x();
int y_start = queuee[0].get_y();
int xx,yy;
while (queuee.size()>0 && eaten == false )
{
x = queuee[0].get_x();
y = queuee[0].get_y();
Vpop_front(queuee);
int step=0;
while(step <4 && eaten==false)
    {
        switch(step)
        {
        case 0:
            {
                if((x-1)>=0)
                {
                    xx=x-1;
                if(mat[xx][y]!=1 && visited[xx][y]==false && mat[xx][y]!=3)
                {
                    visited[xx][y]=true;
                    Node tmp(xx,y);
                    if(mat[xx][y]==2)
                    {
                        point+=10;
                        eaten=true;
                        res.push_back(tmp);
                    }
                    queuee.push_back(tmp);
                    prev[xx][y]=0;
                }
                }
                step++;
                break;
            }
        case 1:
            {
                if((y+1)<m)
                {
                    yy=y+1;
                if(mat[x][yy]!=1 && visited[x][yy]==false && mat[x][yy]!=3)
                {
                    visited[x][yy]=true;
                    Node tmp(x,yy);
                    if(mat[x][yy]==2)
                    {
                        point+=10;
                        eaten=true;
                        res.push_back(tmp);
                    }
                    queuee.push_back(tmp);
                    prev[x][yy]=1;
                }
                }
                step++;
                break;
            }
        case 2:
            {
            if((x+1)<n)
                {
                    xx=x+1;
                if(mat[xx][y]!=1 && visited[xx][y]==false && mat[xx][y]!=3 )
                {
                    visited[xx][y]=true;
                    Node tmp(xx,y);
                    if(mat[xx][y]==2)
                    {
                        point+=10;
                        eaten=true;
                        res.push_back(tmp);
                    }
                    queuee.push_back(tmp);
                    prev[xx][y]=2;
                }
                }
                step++;
                break;
            }
        case 3:
        {
          if((y-1)>=0)
            {
                yy=y-1;
            if(mat[x][yy]!=1 && visited[x][yy]==false && mat[x][yy]!=3)
            {
                visited[x][yy]=true;
                Node tmp(x,yy);
                if(mat[x][yy]==2)
                {
                    point+=10;
                    eaten=true;
                    res.push_back(tmp);
                }
                queuee.push_back(tmp);
                prev[x][yy]=3;
            }
            }
            step++;
            break;
        }
        default: break;
        }
    }

}


if (eaten==true)
{
    xx = res[0].get_x();
    yy = res[0].get_y();
    int tmpx=xx;
    int tmpy=yy;
    while (tmpx != x_start || tmpy != y_start )
    {
        if (prev[tmpx][tmpy]==0)
        {
            tmpx=tmpx+1;
            Node tmp(tmpx,tmpy);
            res.push_back(tmp);
        }
        else if(prev[tmpx][tmpy]==1)
        {
            tmpy=tmpy-1;
            Node tmp(tmpx,tmpy);
            res.push_back(tmp);
        }
        else if(prev[tmpx][tmpy]==2)
        {
            tmpx=tmpx-1;
            Node tmp(tmpx,tmpy);
            res.push_back(tmp);
        }
        else if(prev[tmpx][tmpy]==3)
        {
            tmpy=tmpy+1;
            Node tmp(tmpx,tmpy);
            res.push_back(tmp);
        }
        point--;
    }
}
if(point<=10) far=true;
return;
}
void level_three(int n, int m, int **mat,vector<Node>&res,int x,int y,int &point, bool &sudden, int** &maximum_step)
{
    int mapsize=(m*n)/2;
    srand(time(NULL));
    int random= rand() % mapsize + mapsize;
    int step=0;
    int moveable;
    int prevx=-1;
    int prevy=-1;
    int random_step;
    vector<Node> next_move;
    while(step<=random)
    {
        moveable=4;
        if((x-1) <0 || mat[x-1][y]==1 || mat[x-1][y]==3 || maximum_step[x-1][y]==2)
        {
            moveable--;
        }
        else
        {
            Node tmp((x-1),y);
            next_move.push_back(tmp);
        }
        if((x+1)>=n || mat[x+1][y]==1 || mat[x+1][y]==3 || maximum_step[x+1][y]==2)
        {
            moveable--;
        }
        else
        {
            Node tmp((x+1),y);
            next_move.push_back(tmp);
        }
        if((y-1) <0 || mat[x][y-1]==1 || mat[x][y-1]==3 || maximum_step[x][y-1]==2)
            {
              moveable--;
            }
        else
        {
            Node tmp(x,(y-1));
            next_move.push_back(tmp);
        }
        if((y+1)>=m || mat[x][y+1]==1 || mat[x][y+1]==3 || maximum_step[x][y+1]==2)
        {
          moveable--;
        }
        else
        {
            Node tmp(x,(y+1));
            next_move.push_back(tmp);
        }
        if(moveable==0)
        {
            sudden=true;
            return;
        }
        bool moved=false;
        while(moved!=true)
        {
        if((x-1)>=0)
        {
            if (mat[x-1][y]==2)
            {
            prevx=x;
            prevy=y;
            x=x-1;
            Node tmp(x,y);
            res.push_back(tmp);
            mat[x][y]=0;
            maximum_step[x][y]++;
            point+=10;
            moved=true;
            break;
            }
        }
        if(x+1<n)
        {
            if(mat[x+1][y]==2)
            {
            prevx=x;
            prevy=y;
            x=x+1;
            Node tmp(x,y);
            res.push_back(tmp);
            mat[x][y]=0;
            maximum_step[x][y]++;
            point +=10;
            moved=true;
            break;
            }
        }
        if((y-1)>=0)
        {
            if(mat[x][y-1]==2)
            {
            prevx=x;
            prevy=y;
            y=y-1;
            Node tmp(x,y);
            res.push_back(tmp);
            mat[x][y]=0;
            maximum_step[x][y]++;
            point+=10;
            moved=true;
            break;
            }
        }
        if((y+1)<m)
        {
            if(mat[x][y+1]==2 )
            {
            prevx=x;
            prevy=y;
            y=y+1;
            Node tmp(x,y);
            res.push_back(tmp);
            mat[x][y]=0;
            maximum_step[x][y]++;
            point+=10;
            moved=true;
            break;
            }
        }
        bool valid=false;
        while (valid !=true)
            {
                srand(time(NULL));
                random_step = rand() % moveable;
            if (next_move[random_step].x!=prevx || next_move[random_step].y!=prevy)
            {
                prevx=x;
                prevy=y;
                x=next_move[random_step].x;
                y=next_move[random_step].y;
                Node tmp(x,y);
                res.push_back(tmp);
                valid=true;
                maximum_step[x][y]++;
                point--;
                moved=true;
            }
            else if(moveable==1)
            {
                prevx=x;
                prevy=y;
                x=next_move[random_step].x;
                y=next_move[random_step].y;
                Node tmp(x,y);
                res.push_back(tmp);
                maximum_step[x][y]++;
                valid=true;
                point--;
                moved=true;
            }
            }
        }

    // choose next move//

        next_move.clear();
        step++;
    }
}
int find_true_cost(int x,int y, int n,int m, int**mat)
{
    bool** visited = new bool*[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=new bool [m];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            visited[i][j]=false;
    }
    int**prev = new int*[n];
    for(int i=0;i<n;i++)
    {
        prev[i]=new int [m];
    }
   bool eaten=false;
   int x_start=x;
   int y_start=y;
vector<Node> res;
vector<Node> queuee;
Node tmp(x,y);
queuee.push_back(tmp);
int xx,yy;
while (queuee.size()>0 && eaten == false )
{
x = queuee[0].get_x();
y = queuee[0].get_y();
Vpop_front(queuee);
int step=0;
while(step <4 && eaten==false)
    {
        switch(step)
        {
        case 0:
            {
                if((x-1)>=0)
                {
                    xx=x-1;
                if(mat[xx][y]!=1 && visited[xx][y]==false )
                {
                    visited[xx][y]=true;
                    Node tmp(xx,y);
                    if(mat[xx][y]==2)
                    {
                        eaten=true;
                        res.push_back(tmp);
                    }
                    queuee.push_back(tmp);
                    prev[xx][y]=0;
                }
                }
                step++;
                break;
            }
        case 1:
            {
                if((y+1)<m)
                {
                    yy=y+1;
                if(mat[x][yy]!=1 && visited[x][yy]==false)
                {
                    visited[x][yy]=true;
                    Node tmp(x,yy);
                    if(mat[x][yy]==2)
                    {
                        eaten=true;
                        res.push_back(tmp);
                    }
                    queuee.push_back(tmp);
                    prev[x][yy]=1;
                }
                }
                step++;
                break;
            }
        case 2:
            {
            if((x+1)<n)
                {
                    xx=x+1;
                if(mat[xx][y]!=1 && visited[xx][y]==false)
                {
                    visited[xx][y]=true;
                    Node tmp(xx,y);
                    if(mat[xx][y]==2)
                    {
                        eaten=true;
                        res.push_back(tmp);
                    }
                    queuee.push_back(tmp);
                    prev[xx][y]=2;
                }
                }
                step++;
                break;
            }
        case 3:
        {
          if((y-1)>=0)
            {
                yy=y-1;
            if(mat[x][yy]!=1 && visited[x][yy]==false)
            {
                visited[x][yy]=true;
                Node tmp(x,yy);
                if(mat[x][yy]==2)
                {
                    eaten=true;
                    res.push_back(tmp);
                }
                queuee.push_back(tmp);
                prev[x][yy]=3;
            }
            }
            step++;
            break;
        }
        default: break;
        }
    }
}
if (eaten==true)
{
    xx = res[0].get_x();
    yy = res[0].get_y();
    int tmpx=xx;
    int tmpy=yy;
    while (tmpx != x_start || tmpy != y_start )
    {
        if (prev[tmpx][tmpy]==0)
        {
            tmpx=tmpx+1;
            Node tmp(tmpx,tmpy);
            res.push_back(tmp);
        }
        else if(prev[tmpx][tmpy]==1)
        {
            tmpy=tmpy-1;
            Node tmp(tmpx,tmpy);
            res.push_back(tmp);
        }
        else if(prev[tmpx][tmpy]==2)
        {
            tmpx=tmpx-1;
            Node tmp(tmpx,tmpy);
            res.push_back(tmp);
        }
        else if(prev[tmpx][tmpy]==3)
        {
            tmpy=tmpy+1;
            Node tmp(tmpx,tmpy);
            res.push_back(tmp);
        }

    }
    for(int i = 0; i < m; ++i) {
    delete [] prev[i];
    }
    delete [] prev;
    for(int i = 0; i < m; ++i) {
    delete [] visited[i];
    }
    delete [] visited;
    return res.size()-1;
}
else
{
     for(int i = 0; i < m; ++i) {
    delete [] prev[i];
    }
    delete [] prev;
    for(int i = 0; i < m; ++i) {
    delete [] visited[i];
    }
    delete [] visited;
    return n*m;

}

}

void level_four(int**mat, int px, int py, int gx, int gy,int n,int m, vector<Node>&path,int &point,bool&eatenbyghost,int**maximum_step)
{
    int prevx,prevy;
    int distance;
    int tmp;
    int step;
    vector<int>true_cost;
    int num_food=0;
    for(int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            if(mat[i][j]==2) num_food++;
        }
    }
while (((px!=gx)||(py!=gy))&&num_food!=0&&eatenbyghost==false)
{
    prevx=px;
    prevy=py;
    if((px-1)>=0)
    {
        if(mat[px-1][py]!=1 && mat[px-1][py]!=3)
        {
            distance=abs(px-1-gx)+abs(py-gy);
            if(distance<=2 || maximum_step[px-1][py]==2) tmp=n*m;
            else tmp=find_true_cost(px-1,py,n,m,mat);
            true_cost.push_back(tmp);
        }
        else
    {
        tmp=n*m;
        true_cost.push_back(tmp);
    }
    }
    else
    {
        tmp=n*m;
        true_cost.push_back(tmp);
    }
    if((px+1)<n)
    {
        if(mat [px+1][py]!=1 && mat[px+1][py]!=3)
        {
            distance=abs(px+1-gx)+abs(py-gy);
            if(distance<=2 || maximum_step[px+1][py]==2) tmp=n*m;
            else tmp=find_true_cost(px+1,py,n,m,mat);
            true_cost.push_back(tmp);
        }
        else
    {
        tmp=n*m;
        true_cost.push_back(tmp);
    }
    }
    else
    {
        tmp=n*m;
        true_cost.push_back(tmp);
    }
    if((py-1)>=0)
    {
        if(mat[px][py-1]!=1 && mat[px][py-1]!=3)
        {
            distance=abs(px-gx)+abs(py-1-gy);
            if(distance<=2 || maximum_step[px][py-1]==2) tmp=n*m;
            else tmp=find_true_cost(px,py-1,n,m,mat);
            true_cost.push_back(tmp);
        }
        else
    {
        tmp=n*m;
        true_cost.push_back(tmp);
    }
    }
    else
    {
        tmp=n*m;
        true_cost.push_back(tmp);
    }
    if((py+1)<m)
    {
        if(mat[px][py+1]!=1 && mat[px][py+1]!=3)
        {
            distance=abs(px-gx)+abs(py+1-gy);
            if(distance<=2 || maximum_step[px][py+1]==2) tmp=n*m;
            else tmp=find_true_cost(px,py+1,n,m,mat);
            true_cost.push_back(tmp);
        }
        else
    {
        tmp=n*m;
        true_cost.push_back(tmp);
    }
    }
    else
    {
        tmp=n*m;
        true_cost.push_back(tmp);
    }
    step=Min_true_cost(true_cost);
    if(step!=-1)
    {
        if(true_cost[step]!=(n*m))
        {
            if(step==0)
        {
            px=px-1;
            Node tmp(px,py);
            maximum_step[px][py]++;
            path.push_back(tmp);
            point--;
        }
        if(step==1)
        {
            px=px+1;
            Node tmp(px,py);
            maximum_step[px][py]++;
            path.push_back(tmp);
            point--;
        }
        if(step==2)
        {
            py=py-1;
            Node tmp(px,py);
            maximum_step[px][py]++;
            path.push_back(tmp);
            point--;
        }
        if(step==3)
        {
            py=py+1;
            Node tmp(px,py);
            maximum_step[px][py]++;
            path.push_back(tmp);
            point--;
        }
        }
        else eatenbyghost=true;

    }
    if(mat[px][py]==2)
    {
        point+=10;
        num_food--;
        mat[px][py]=0;
    }
    ghost_agent(gx,gy,mat,px,py,n,m);
    true_cost.clear();
}
if((px==gx)&& (py==gy)) eatenbyghost=true;
}
int Min_true_cost(vector<int> a)
{
    if (a.size()==0) return -1;
    int j=0;
    int min_cost=a[0];
    for(int i=1;i<a.size();i++)
    {
        if (a[i]<min_cost)
        {
            min_cost=a[i];
            j=i;
        }
    }
    return j;
}
