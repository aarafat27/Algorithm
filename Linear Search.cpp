#include <iostream>

using namespace std;

int linearSearch(int a[], int n, int value)
{
 int i;
 for (i=0;i<n;i++)
  {
      if(a[i]==value)
       {
          return i;
       }
  }
 return -1;
}



int main()
{
  int a[] = {1,2,3,4,5,6,7,8,9};
  int n = sizeof(a)/ sizeof(a[0]);
  int value = 6;

  int p = linearSearch(a,n,value);

  if(p==-1)
    {
      cout<<value<<" is not present in this array."<<endl;
    }
  else
      cout<<value<<" is present at index: "<< p <<endl;


  return 0;
}
