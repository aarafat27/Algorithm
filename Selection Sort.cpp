#include <iostream>

using namespace std;
void swap(int *x,int *y)
{
    int t= *x;
    *x=*y;
    *y= t;

}
void selectionSort(int a[],int n)
{

 int minvalueat,i,j;
 for(i=0;i<n-1;i++)
 {
     minvalueat=i;
     for(j=i+1;j<n;j++)
     {

         if(a[j]<a[minvalueat])
         {
             minvalueat=j;

         }

     }

     swap(&a[i], &a[minvalueat]);
    // int temp = a[i];
    // a[i]= a[minvalueat];
     //a[minvalueat]= temp;
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
    int a[]= {6,8,2,9,1,0,3,4,7,5};
    int n= sizeof(a)/sizeof(a[0]);
    printarray(a,n);
    selectionSort(a,n);
    cout<<"After Sorted:";
    printarray(a,n);

    return 0;
}
