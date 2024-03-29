#include "header.h"
using namespace std;
const double CLK_TCK = 1000.0;

int main()
{
    bool sudden=false;
    int point=10;
    char*filename="input.txt";
    int** mat;
    int level;
    int m,n,x,y;
    int gx,gy;
    bool far=false;
    ifstream fin;
    fin.open("level.txt");
    {
        fin>>level;
    }
    fin.close();
    Getinput(n,m,x,y,mat,fin,filename);

    bool** visited = new bool*[n];
    for(int i=0;i<n;i++)
    {
        visited[i] = new bool [m];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            visited[i][j]=false;
        }
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
    double total_time;
    clock_t start,endd;
    start =clock();
    switch (level)
    {
    case 1:
        {
            level_one(n,m,mat,result,queuee,visited,prev,point,far);
            endd=clock();
                if( result.size()>0)
    {
        if (far==false)
        {
            ofstream fout;
            fout.open("output.txt");
            {
                fout<<result.size()-1<<endl;
                for(int i=result.size()-1;i>=0;i--)
                {
                    fout<<"{"<<result[i].x<<","<<result[i].y<<"} ";
                }
                fout<<endl;
                fout<<point-10<<endl;
                total_time= ((double) (endd-start)) / CLK_TCK;
                fout<<"execution time: "<<total_time<<endl;
            }
            fout.close();
            map_generate(result);
        }
        else
        {
            ofstream fout;
            fout.open("output.txt");
            fout<<"food is too far away pacman decide to stop"<<endl;
            fout<<0<<endl;
            total_time= ((double) (endd-start)) / CLK_TCK;
            fout<<"execution time: "<<total_time<<endl;
            fout.close();
            fout.open("map.txt");
            fout<<0;
            fout.close();
        }
    }
    else
    {
        ofstream fout;
        fout.open ("output.txt");
        fout<<"can not get to food"<<endl;
        fout<<0<<endl;
        total_time= ((double) (endd-start)) / CLK_TCK;
        fout<<"execution time: "<<total_time<<endl;
        fout.close();
        fout.open("map.txt");
        fout<<0;
        fout.close();
    }
    break;
        }
    case 2:
        {
         level_two(n,m,mat,result,queuee,visited,prev,point,far);
         endd=clock();
         if( result.size()>0)
    {
        if (far==false)
        {
            ofstream fout;
            fout.open("output.txt");
            {
                fout<<result.size()-1<<endl;
                for(int i=result.size()-1;i>=0;i--)
                {
                    fout<<"{"<<result[i].x<<","<<result[i].y<<"} ";
                }
                fout<<endl;
                fout<<point-10<<endl;
                total_time= ((double) (endd-start)) / CLK_TCK;
                fout<<"execution time: "<<total_time<<endl;
            }
            fout.close();
            map_generate(result);
        }
        else
        {
            ofstream fout;
            fout.open("output.txt");
            fout<<"food is too far away pacman decide not to move"<<endl;
            fout<<0<<endl;
            total_time= ((double) (endd-start)) / CLK_TCK;
                fout<<"execution time: "<<total_time<<endl;
            fout.close();
            fout.open("map.txt");
            fout<<0;
            fout.close();
        }
    }
    else
    {
        ofstream fout;
        fout.open ("output.txt");
        fout<<"can not get to food"<<endl;
        fout<<0<<endl;
        total_time= ((double) (endd-start)) / CLK_TCK;
                fout<<"execution time: "<<total_time<<endl;
        fout.close();
        fout.open("map.txt");
        fout<<0;
        fout.close();
    }
    break;
        }
    case 3:
        {
        int** maximum_step = new int*[n];
        for(int i=0;i<n;i++)
        {
            maximum_step[i]= new int[m];
        }
        for(int i=0;i<n;i++)
        {
        for(int j=0;j<m;j++)
        {
            maximum_step[i][j]=0;
        }
        }
            level_three(n,m,mat,result,x,y,point,sudden,maximum_step);
            endd=clock();
            ofstream fout;
            if (sudden==true)
            {
                fout.open("output.txt");
                {
                    fout<<result.size()<<endl;
                    fout<<x<<","<<y<<" ";
                    for(int i=0;i<result.size();i++)
                    {
                        fout<<result[i].x<<","<<result[i].y<<" ";
                    }
                    fout<<endl;
                    fout<<point-10<<endl;
                    fout<<"pacman decide to stop"<<endl;
                    total_time= ((double) (endd-start)) / CLK_TCK;
                fout<<"execution time: "<<total_time<<endl;
                }
                fout.close();
                fout.open("map.txt");
                {
                    fout<<result.size()<<endl;
                    for(int i=0;i<result.size();i++)
                    {
                        fout<<result[i].x<<" "<<result[i].y<<endl;
                    }
                }
                fout.close();
            }
            else
            {
                fout.open("output.txt");
                {
                    fout<<result.size()<<endl;
                    for(int i=0;i<result.size();i++)
                    {
                        fout<<result[i].x<<","<<result[i].y<<" ";
                    }
                    fout<<endl;
                    fout<<point-10<<endl;
                    total_time= ((double) (endd-start)) / CLK_TCK;
                fout<<"execution time: "<<total_time<<endl;
                }
                fout.close();
                fout.open("map.txt");
                {
                    fout<<result.size()<<endl;
                    for(int i=0;i<result.size();i++)
                    {
                        fout<<result[i].x<<" "<<result[i].y<<endl;
                    }
                }
                fout.close();
            }
    for(int i=0;i<m;i++)
    {
        delete [] maximum_step[i];
    }
    delete[] maximum_step;
    break;
            }

    case 4:
        {
            int** maximum_step = new int*[n];
        for(int i=0;i<n;i++)
        {
            maximum_step[i]= new int[m];
        }
        for(int i=0;i<n;i++)
        {
        for(int j=0;j<m;j++)
        {
            maximum_step[i][j]=0;
        }
        }
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(mat[i][j]==3)
                    {
                        gx=i;
                        gy=j;
                    }
                }
            }
            bool eatenbyghost=false;
            level_four(mat,x,y,gx,gy,n,m,result,point,eatenbyghost,maximum_step);
            endd=clock();
            ofstream fout;
            if(eatenbyghost==true)
            {
                fout.open("output.txt");
                fout<<"ghost eat pacman"<<endl;
                for(int i=0;i<result.size();i++)
            {
                fout<<result[i].x<<","<<result[i].y<<" ";
            }
                fout<<endl<<point-10<<endl;
                total_time= ((double) (endd-start)) / CLK_TCK;
                fout<<"execution time: "<<total_time<<endl;
                fout.close();
            }
            else
            {
                fout.open("output.txt");
                fout<<"pac man eat all food"<<endl;
                for(int i=0;i<result.size();i++)
            {
                fout<<result[i].x<<" "<<result[i].y<<endl;
            }
                fout<<point-10<<endl;
                total_time= ((double) (endd-start)) / CLK_TCK;
                fout<<"execution time: "<<total_time<<endl;
                fout.close();
            }

            fout.open("map.txt");
            fout<<result.size()<<endl;
            for(int i=0;i<result.size();i++)
            {
                fout<<result[i].x<<" "<<result[i].y<<endl;
            }
            fout.close();
             for(int i=0;i<m;i++)
    {
        delete [] maximum_step[i];
    }
    delete[] maximum_step;
                break;
        }
    default: break;
    }


  /*  if( result.size()>0)
    {
        if (far==false)
        {
            ofstream fout;
            fout.open("output.txt");
            {
                fout<<result.size()-1<<endl;
                for(int i=result.size()-1;i>=0;i--)
                {
                    fout<<"{"<<result[i].x<<","<<result[i].y<<"} ";
                }
                fout<<endl;
                fout<<point-10;
            }
            fout.close();
            map_generate(result);
        }
        else
        {
            ofstream fout;
            fout.open("output.txt");
            fout<<"food is too far away pacman decide to stop"<<endl;
            fout<<0;
            fout.close();
            fout.open("map.txt");
            fout<<0;
            fout.close();
        }
    }
    else
    {
        ofstream fout;
        fout.open ("output.txt");
        fout<<"can not get to food"<<endl;
        fout<<0;
        fout.close();
        fout.open("map.txt");
        fout<<0;
        fout.close();
    }
    */
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
