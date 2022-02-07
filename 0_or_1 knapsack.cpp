#include <iostream>

using namespace std;
#define s 4
#define ks 5


void printTakenItem(int a[s+1][ks+1],int w[], int b[])
{
 int t=s;
 int p=ks;
 cout<<"\nItem Taken For The Knapsack :"<<endl;
 while (t != 0)
 {
  if (a[t][p] != a[t-1][p])
  {
   cout<<"Item: " << t << " Weight = " << w[t - 1] <<", Benefit = " << b[t - 1]<<endl;
   p = p - w[t-1];
  }
  t--;
 }
}


int knapsack(int w[], int b[])
{
 int arr[s+1][ks+1];
 int i=0,j=0;

 for (int i=0; i<=s; i++)
 {
  for (int j=0; j<=ks; j++)
    {
     arr[i][j] = 0;
    }
 }

 for (int i = 1; i <= s; i++)
 {
  for (int j = 0; j <= ks; j++)
  {
    arr[i][j] = arr[i - 1][j];

    if ((j >= w[i-1]) && (arr[i][j] < arr[i - 1][j - w[i - 1]] + b[i - 1]))
     {
      arr[i][j] = arr[i - 1][j - w[i - 1]] + b[i - 1];
     }
    else if (w[i]>ks)
     {
      arr[i][j]=arr[i-1][j];
     }
  }
 }

 cout<<"Optimal 01 Knapsack Total Benefit : "<<arr[s][ks]<<endl;

 printTakenItem(arr,w,b);

}



int main()
{
 int weights[s]={2,3,4,5};
 int benefits[s]={3,4,5,6};

 knapsack(weights,benefits);

}
