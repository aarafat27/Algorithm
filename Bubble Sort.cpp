#include <iostream>

using namespace std;

void bubbleSort(int a[],int n)
{
    int i,j,temp,ok;
    for(i=0;i<n;i++)
    {
        ok=0;
        for(j=0;j<n-1-i;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j+1];
                a[j+1]=a[j];
                a[j]=temp;
                ok=1;

            }
        }

        if(ok==0)
            break;
    }

}

int printarray(int a[], int n)
{

  for (int i=0; i<n; i++)
   {
      cout<<a[i]<<",";
   }
   cout<<"\n"<<endl;
}


int main()
{
    int a[]= {4,5,0,9,1,6,2,8,3};
    int n = sizeof(a)/sizeof(a[0]);
    bubbleSort(a,n);
    cout<<"After Sorted:";
    printarray(a,n);

    return 0;
}
