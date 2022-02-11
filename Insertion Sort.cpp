#include <iostream>

using namespace std;

void insertionSort(int a[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = a[i];
        j = i - 1;


        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
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
  int a[] ={5,9,8,2,7,4,3,0,1,6};
  int n = sizeof(a)/sizeof(a[0]);
  cout << "Hello world!\n" << endl;

  cout<<"Unsorted Array:"<<endl;
  printarray(a,n);

  insertionSort(a,n);

  cout<<"Sorted Array:"<<endl;
  printarray(a,n);


  return 0;
}
