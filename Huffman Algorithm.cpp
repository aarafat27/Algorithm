#include <bits/stdc++.h>
using namespace std;

class MinHeapNode {
public:
	char data;
	int freq;
	MinHeapNode *left, *right;

	MinHeapNode(char data, int freq)
	{
		left = right = NULL;
		this->data = data;
		this->freq = freq;
	}
};

class compare {
public:
	bool operator()(MinHeapNode* l, MinHeapNode* r)
	{
		return (l->freq > r->freq);
	}
};

void printCodes(MinHeapNode* root, string str)
{
    if (root==NULL)
     {
        return;
     }


    if (root->data != '$')
     {
       cout << root->data << ": " << str << "\n";
     }


    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");

}

void HuffmanCodes(char data[], int freq[], int size)
{
    MinHeapNode *left, *right, *top;
	priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;

	for (int i = 0; i < size; ++i)
		minHeap.push(new MinHeapNode(data[i], freq[i]));


	while (minHeap.size() != 1) {
        
        left = minHeap.top();
        minHeap.pop();
        right = minHeap.top();
        minHeap.pop();
        top = new MinHeapNode('$', left->freq + right->freq);

        top->left = left;
        top->right = right;

        minHeap.push(top);
	}

	printCodes(minHeap.top(), "");
}

int main()
{

	char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
	int freq[] = { 45, 16, 12, 13, 6, 5 };

	int size = sizeof(arr) / sizeof(arr[0]);

	HuffmanCodes(arr, freq, size);

	return 0;
}
