#include <iostream>
#include <queue>
#define Num 11

using namespace std;
class Action
{
 public:
  int  start;
  int end;

  Action(int start, int end)
   {
      this->start = start;
      this->end = end;
   }

   bool operator < (const Action &A) const
    {
        return end > A.end;
    }

};

void displayPQ(priority_queue<Action> Activity){

    int i=1;
    Action A = Activity.top();

             Activity.pop();
            cout <<"Activity 1 : "<<"Start: "<<A.start<<", End :"<<A.end<<endl;

    while (!Activity.empty()) {
            Action B = Activity.top();

             Activity.pop();

            if(B.start>=A.end)
            {
                i++;
             cout <<"Activity "<< i <<" : "<< "Start: "<<B.start<<", End :"<<B.end<<endl;
             A.end = B.end;

            }

    }

}




int main()
{
    priority_queue<Action> Activity;

    int starting[Num] = {1,5,0,3,6,5,3,12,8,2,8};
    int ending[Num] = {4,7,6,5,10,9,9,16,12,14,11};

	for (int i = 0; i < Num; ++i)
    {
      Action A(starting[i],ending[i]);
      Activity.push(A);
	}

	displayPQ(Activity);

    return 0;
}
