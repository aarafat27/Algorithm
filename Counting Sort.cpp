#include <iostream>

using namespace std;

int findmaxvalue(int a[],int n)
{
 int i=0;
 int maxvalue=a[i];
 for(i=1;i<n;i++)
 {
  if(maxvalue<a[i])
    maxvalue= a[i];
 }
 return maxvalue;
}

int result(int b[],int n)
{
 for(int i=0;i<n;i++)
 {
  cout<<b[i]<<",";
 }
}

int countingSort(int a[], int n)
{
 int k= findmaxvalue(a,n);

 int i=0;
 int b[n] ;
 int count[k+1];


 for(i=0;i<=k;i++)
 {
  count[i]=0;
 }
 for(i=0;i<n;i++)
 {
  count[a[i]]= count[a[i]]+1;
 }


 for(i=1;i<=k;i++)
 {
  count[i]= count[i]+count[i-1];
 }


 for(i=n-1; i>=0;i--)
 {
  b[count[a[i]]-1] = a[i];
  count[a[i]]= count[a[i]]-1;
 }

 cout<<"\nSorted Array :";
 result(b,n);

}

int main()
{
 int a[]= {0,3,2,5,9,2,1,0,0,4,3,1};
 int n = sizeof(a)/sizeof(a[0]);
 cout<<"Main array : ";
 result(a,n);

 countingSort(a, n);

 return 0;
}
