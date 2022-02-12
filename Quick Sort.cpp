#include <iostream>

using namespace std;
int partition(int a[], int start, int end)
{
    int i= start;
    int piv= a[start];
    for(int j= start+1;j<=end;j++)
    {
        if(a[j]<piv)
        {
            i++;
            swap(a[i],a[j]);
        }

    }
    swap(a[start], a[i]);
    return i;

}

int quickSort(int a[], int start, int end)
{
    if(start<end)
    {
        int piv_pos= partition(a,start,end);
        quickSort(a,start,piv_pos-1);
        quickSort(a,piv_pos+1,end);

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
    int a[]= {15,8,1,9,5,3,7,2,0,6,4};
    int n = sizeof(a)/sizeof(a[0]);
    int start = 0;
    int end = n-1;
    quickSort(a,start,end);
    result(a,n);

}
