
#include <iostream>
#include <queue>
using namespace std;
#define k 10

int totalChanges[k];

int print(int a[],int b)
{
    cout<<"Type of total Coins Needed for the changes: ";
    for(int i=0;i<b;i++)
    {
        cout<<a[i]<<",";
    }
}

int minimumCoins(int coins[], int size, int changes)
{
  int i, j =0;
  for(i=0;i<size;i++)
  {
      if (changes==0)
      {
          break;
      }
     while (changes >= coins[i])
     {
         changes = changes- coins[i];
         totalChanges[j]= coins[i];
         j++;

     }
  }
  print(totalChanges, j);
}



int main()
{
    int coins[]={25,10,5,1};
    int changes = 73;
    int n = sizeof(coins)/sizeof(coins[0]);
    cout<<"Chnages need for: "<<changes<<endl;
    minimumCoins(coins,n,changes);

}
