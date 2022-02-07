#include <iostream>
using namespace std;
#define s 5

int d[s],p[s],f[s];
char color[s];
int G[s][s];
int time=0;
int cycle=0;


char nodeconvertion(int n)
{
  return (char)(65+n);
}

void displayGraph(int G[][s])
{
 cout<<"  ";
 for(int i=0;i<s;i++)
 {
  cout<< nodeconvertion(i)<<" ";
 }
 cout<<endl;
 for(int i=0;i<s;i++)
 {
  cout<< nodeconvertion(i)<<" ";
  for(int j=0;j<s;j++)
  {
    cout<< G[i][j]<<" ";
  }
  cout<<endl;
 }
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


void dfs_visit(int u)
{
 color[u]='G';
 time= time+1;
 d[u]=time;
 for(int c=0;c<s;c++)
 {
  if(G[u][c]==1)
   {
    if(color[c]=='W')
    {
      dfs_visit(c);
    }
    if( color[c]=='G')
    {

      cycle++;

    }
   }
 }
 color[u]='B';
 time=time+1;
 f[u]=time;
}

void dfs(int G[][5])
{
 for(int u=0;u<s;u++)
 {
  color[u]='W';
  time=0;
 }

 for(int u=0;u<s;u++)
 {
  if(color[u]=='W')
  {
    dfs_visit(u);
  }
 }
}

void cycleDetection()
{
    if(cycle>=0)
    {
        cout<<"\nCycle Detected!"<<endl;
        cout<<"There are "<<cycle<<" cycle in this graph"<<endl;
    }
}


int main()
{

    initGraph(G);
    cout<<"Initial Graph :\n";
    displayGraph(G);
    cout<<endl;

    G[0][1]=1;
    G[1][2]=1;
    G[2][3]=1;
    G[2][3]=1;
    G[3][4]=1;
    G[4][0]=1;
    G[4][3]=1;
    //cout<<"Graph Adjacent Matrix :\n";
   // displayGraph(G);

    dfs(G);
    printAdjacent(G);
    cout<<endl;
    cout<<"\nTime for visiting Nodes :"<<endl;
    for(int i=0;i<s;i++)
    {
     cout<<"Node : "<<nodeconvertion(i)<<"   Start: "<<d[i]<<"   Finish : "<<f[i]<<endl;
    }
    cycleDetection();

    return 0;
}
