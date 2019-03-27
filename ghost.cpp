#include "header.h"
void getdistance(int gx,int gy,int px, int py,int&difx, int&dify)
{
  difx=abs(px-gx);
  dify=abs(py-gy);
}
void ghost_agent(int&gx,int&gy,int**mat, int px,int py,int n,int m)
{
    int tmpx,tmpy,difx,dify;
    int bestx,besty,tmpdis;
    vector<Node> evalue;
if((gx-1)>=0   )
{
    if (mat[gx-1][gy]!=1)
    {
    tmpx=gx-1;
    getdistance(tmpx,gy,px,py,difx,dify);
    Node tmp(difx,dify);
    evalue.push_back(tmp);
    }
}
else
{
    Node tmp(n*m,n*m);
    evalue.push_back(tmp);
}
if((gx+1)<n )
{
    if(mat[gx+1][gy]!=1)
    {
    tmpx=gx+1;
    getdistance(tmpx,gy,px,py,difx,dify);
    Node tmp(difx,dify);
    evalue.push_back(tmp);
    }

}
if((gy-1)>=0 )
{
    if( mat[gx][gy-1]!=1)
    {
    tmpy=gy-1;
    getdistance(gx,tmpy,px,py,difx,dify);
    Node tmp(difx,dify);
    evalue.push_back(tmp);
    }

}
if((gy+1)<m )
{
    if(mat[gx][gy+1]!=1)
    {
    tmpy=gy+1;
    getdistance(gx,tmpy,px,py,difx,dify);
    Node tmp(difx,dify);
    evalue.push_back(tmp);
    }
}
if(evalue.size()==1)
{
    gx=evalue[0].x;
    gy=evalue[0].y;
}
else
{
    int step=0;
   tmpdis=evalue[0].x+evalue[0].y;
   for(int i=1;i<evalue.size()-1;i++)
   {
       if((evalue[i].x + evalue[i].y)<tmpdis)
        {
            tmpdis=evalue[i].x+evalue[i].y;
            step=i;
        }
   }

if(step!=-1)
    {
        if((evalue[step].x+evalue[step].y)!=(n*m))
        {
        if(step==0)
        {
            gx=gx-1;
        }
        if(step==1)
        {
            gx=gx+1;
        }
        if(step==2)
        {
            gy=gy-1;
        }
        if(step==3)
        {
            gy=gy+1;
        }
        }
    }
}
return;
}
