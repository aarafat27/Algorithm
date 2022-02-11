#include <iostream>

using namespace std;

int merge(int a[], int p, int q, int r)
{
 int n1 = q-p+1;
 int n2 = r-q;
 int L[n1];
 int R[n2];
 int i=0,j=0;
 for(i=0;i<=n1;i++)
 {
     L[i]= a[p+i-1];
 }


 for(j=0;j<=n2;j++)
 {
     R[j]=a[q+j];
 }

L[n1+1]= INT_MAX;
R[n2+1]= INT_MAX;


i=1;
j=1;
int k;
for(k=p;k<=r;k++)
    {
        if(L[i]<=R[j])
        {
            a[k]=L[i];
            i++;
        }
        else
        {
            a[k]=R[j];
            j++;
        }
    }


}



int mergeSort(int a[], int p, int r)
{
  if(p<r)
  {
      int q = (p+r)/2;
      mergeSort(a,p,q);
      mergeSort(a,q+1,r);
      merge(a,p,q,r);

  }

}

int result(int a[], int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<",";
    }
}



int main()
{
    int a[]= {9,0,5,2,7,4,6};
    int n= sizeof(a)/sizeof(a[0]);
    cout<<"\nUnsorted Array : ";
    result(a,n);
    mergeSort(a,0,n-1);
    cout<<"\nSorted Array : ";
    result(a,n);
}
