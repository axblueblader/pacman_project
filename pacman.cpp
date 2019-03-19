#include "header.h"
void map_generate(vector<Node>path)
{
    ofstream fout;
    fout.open("map.txt");
    {
        fout<<path.size()<<endl;

        for(int i=path.size()-1;i>=0;i--)
        {
            fout<<path[i].x<<" "<<path[i].y<<endl;
        }
    }
    fout.close();
}
void Getinput (int &n,int &m,int &x, int &y, int** &mat, ifstream &fin, char*filename)
{
    fin.open(filename);
    bool Mapsize=false;
    bool input =false;
    bool init = false;
    char inp;
    int conv=0;
    // read from file//
    while(!fin.eof())
    {
        // get number of node and create NxM matrix
        if (Mapsize==false)
        {
            int check=0;
            int dec=0;

            while (check<2)
            {
                fin.get(inp);
                while(inp>= '0' && inp <='9'&& !fin.eof() )
            {
                conv = conv *int(pow(10,float(dec))) + (int)inp - 48 ;
                dec++;
                fin.get(inp);
            }
            if (check==0)
            {
                n = conv;
                check++;
                dec=0;
                conv=0;
            }
            else if (check==1)
            {
                m=conv;
                check++;
                dec=0;
                conv=0;
            }
            }
            mat=new int*[n];
            for (int i=0;i<n;i++)
            {
                mat[i]=new int [m];
            }
            Mapsize=true;
            conv=0;
            }
        // get start, end, type of search//

        // get matrix value //
        else if (input==false)
        {
            int dec=0;
            for(int i=0;i<n;i++)
            {
                for (int j=0;j<m;j++)
                {

                    fin.get(inp);
                    while(inp>= '0' && inp <='9' && !fin.eof() )
                    {
                        conv = conv* pow(10,dec) + int(inp) - 48 ;
                        dec++;
                        fin.get(inp);
                    }
                    mat[i][j]=conv;

                    conv=0;
                    dec=0;
                }

            }
            input=true;
        }
        else if (init==false)
        {
            int check=0;
            int dec=0;
            while (check<2)
            {
                fin.get(inp);
                while(inp>= '0' && inp <='9' && !fin.eof() )
                    {
                        conv = conv* pow(10,dec) + int(inp) - 48 ;
                        dec++;
                        fin.get(inp);
                    }
                if(check==0)
                {
                    x = conv;
                    conv=0;
                    dec=0;
                    check++;
                }
                else if (check==1)
                {
                    y = conv;
                    conv=0;
                    dec=0;
                    check++;
                }
            }
            init = true;
        }
    }
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
