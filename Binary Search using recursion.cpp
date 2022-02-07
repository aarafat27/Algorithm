#include <iostream>

using namespace std;
int binarySearch(int a[],int value,int low,int high)
{

    if(low <= high)
    {
        int mid =(low+high)/2;

        if(a[mid]==value)
        {
          return mid;
        }

        if(a[mid]>value)
        {
          return binarySearch(a, value, low, mid-1);
        }
        else
        {
            return binarySearch(a, value, mid+1, high);
        }
    }

    return -1;
}

int main()
{
    int a[]={1,2,3,4,5,6,7,8,9,10,11};
    int value= 6;
    int n= sizeof(a)/sizeof(a[0]);
    int p = binarySearch(a,value,0,n-1);

    if(p==-1)
        cout<<value<<" is not found in this array!"<<endl;
    else
        cout<<value<<" is at index : "<<p<<endl;

    return 0;
}
