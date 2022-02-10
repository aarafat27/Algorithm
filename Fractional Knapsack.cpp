//priority_queue in C++

#include <iostream>
#include <queue>
using namespace std;
#define Num 5

class Item {
public:
    string productName;
	double benefit;
	float weight;
	double benefitPerUnit;
	Item(string productName,double benefit, float weight, double benefitPerUnit){
        this->productName = productName;
        this->benefit = benefit;
        this->weight=weight;
        this-> benefitPerUnit=benefitPerUnit;
	}
    bool operator < (const Item &I) const
    {
        return benefitPerUnit < I.benefitPerUnit;
    }
};

void displayPQ(priority_queue<Item> Items){
    while (!Items.empty()) {
            Item I = Items.top();
            Items.pop();
            cout <<"Item Name : "<<I.productName<<", Benefit : "<<I.benefit<<", Weight : "<< I.weight<<", BenefitPerUnit: "<<I.benefitPerUnit<<"\n";
    }
}

int main()
{

	priority_queue<Item> Items;

	string ProductNames[Num] = {"AA","BB","CC","DD","EE"};
    double benefits[Num] = {100,1500,600,1400,2000};
    float weights[Num] = {5,10,6,8,5};


	for (int i = 0; i < Num; ++i)
    {
      Item I(ProductNames[i],benefits[i], weights[i],benefits[i]/weights[i]);
      Items.push(I);
	}

	displayPQ(Items);

	int knapSize = 10,takenSize = 0,j=0;
	float takenWeight=0,benefitForWeight=0,totalBenefit=0,itemWeight=0;
	string itemName;
	string ItemNames[Num];
    float ItemWeights[Num];
    float ItemCost[Num];

	while(takenSize<knapSize)
    {
     Item A = Items.top();
     Items.pop();

     if(A.weight < knapSize-takenSize)
      {
       takenWeight = A.weight;
       itemName= A.productName;
       itemWeight= takenWeight;
      }
     else
      {
       takenWeight = knapSize-takenSize;
       itemName= A.productName;
       itemWeight=takenWeight;
      }

     benefitForWeight = A.benefit * (takenWeight/A.weight);
     totalBenefit += benefitForWeight;
     takenSize += takenWeight;

     ItemCost[j]= benefitForWeight;
     ItemNames[j]= itemName;
     ItemWeights[j]=itemWeight;
     j++;
    }

    cout<<"\nKnapsack Size :"<<knapSize<<endl;
    cout<<"\nTotal Benefit Using Greedy Algorithm for Knapsack : "<<totalBenefit<<endl;

    cout<<"\n*** Weight & cost per item taken for knapsack ***\n"<<endl;
    for(int i=0;i<j;i++)
    {
     cout<<"Taken Item Name: "<<ItemNames[i]<<"  Taken Item Weight :"<<ItemWeights[i]<<" Taken Item Cost :"<<ItemCost[i]<<endl;
    }

    return 0;
}
