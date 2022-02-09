#include <iostream>

using namespace std;
int recursion(int x)
{
    if(x <= 1)
        return 1;
    else
        return x * recursion(x-1);
}

int main()
{
    int x=5;
    int y = recursion(x);
    cout<<"Factorial of "<<x<<" is: "<<y<<endl;
    return 0;
}
