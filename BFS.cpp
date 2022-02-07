#include <iostream>
#include <queue>

using namespace std;
#define s 5
queue<int> xyz;

char color[s];
int G[s][s],d[s];
int time=0;


char nodeconvertion(int n)
{
  return (char)(65+n);
}


void initGraph(int G[][s])
{
 for(int i=0;i<s;i++)
 {
  for(int j=0;j<s;j++)
    {
      G[i][j]=0;
    }
 }
}


void printAdjacent(int G[][s])
{
 cout<<"\nEdges are : ";
 for(int r=0;r<s;r++)
 {
  for(int c=0;c<s;c++)
  if(G[r][c]==1)
  {
    cout<<"("<< nodeconvertion(r)<<":"<<nodeconvertion(c)<<"),";
  }
 }
}



void bfs(int a)
{
 for(int x=0;x<s;x++)
 {
  color[x]='W';
 }
  xyz.push(a);
 // d[a]=time;
 cout<< nodeconvertion(a);
  while (!xyz.empty())
  {

     xyz.pop();

     int u =a;

     a++;
     for(int c=0;c<s;c++)
     {
       if(G[u][c]==1)
      {
        if(color[c]=='W')
         {
           color[c]='G';
           d[c]=d[u+1];
           xyz.push(c);

           cout<<"-->"<<nodeconvertion(c);
         }
       }

     }
    color[u]= 'B';

  }
}


int main()
{

    initGraph(G);

    G[0][1]=1;
    G[0][3]=1;
    G[1][2]=1;
    G[1][4]=1;
    G[3][1]=1;
    G[3][4]=1;
    G[4][2]=1;

    printAdjacent(G);
    cout<<"\nGraph visited : ";
    bfs(0);
    printAdjacent(G);


    return 0;
}
