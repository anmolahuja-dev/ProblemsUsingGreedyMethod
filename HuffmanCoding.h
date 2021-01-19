#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;

struct minHeapNode {
	char data;
	int frequency;
	minHeapNode* left, * right;

	minHeapNode(char data, int frequency) {
		this->data = data;
		this->frequency = frequency;
		this->left = nullptr;
		this->right = nullptr;
	}
};

//this compare function is used to compare the frequencies in order to crete a custom sorting function for priority queue
struct compare
{
	bool operator()(minHeapNode* l, minHeapNode* r)
	{
		return (l->frequency > r->frequency);
	}
};

//This function build min Heap for the given data in O(n) time
priority_queue <minHeapNode* ,vector<minHeapNode*>, compare> buildMinHeap(vector<char>& data, vector<int>& frequency) {
	priority_queue <minHeapNode*,vector<minHeapNode*>,compare> minHeap;
	
	for (int i = 0; i < data.size(); i++) {
		minHeap.push(new minHeapNode(data[i],frequency[i]));
	}
	
	return minHeap;
}

struct minHeapNode* buildHuffmanTree(vector<char>&data,vector<int>&frequency){
	struct minHeapNode* left, * right, * top;	//these min heap nodes are used to create a new node 'top' from left and right lowest frequencies min Heap nodes
	top = nullptr;
	priority_queue <minHeapNode*, vector<minHeapNode*>, compare> minHeap;		//this is used to create a 
	minHeap = buildMinHeap(data, frequency);									// min heap of minHeapNode type

	while (minHeap.size() != 1) {
		left = minHeap.top();
		minHeap.pop();

		right = minHeap.top();
		minHeap.pop();

		top = new minHeapNode('$', left->frequency + right->frequency);	 //'$' symbol is added to identify the non leaf node while printing
		top->left = left;
		top->right = right;

		minHeap.push(top);
	}

	return top;
}

//this fuction takes the root/top node of Huffman tree and an empty string
// "" , if the data of a node is not '$' it prints the character and its code
//else it goes to left and add 0 to the string and then it goes to the right and add 1 to the string

void DecodeHuffmanTree(minHeapNode* root,string str) {
	if (!root)return;

	if (root->data != '$') {
		cout << root->data << " : " << str << "\n";
	}

	DecodeHuffmanTree(root->left, str + "0");
	DecodeHuffmanTree(root->right, str + "1");
}

void HuffmanCoding(vector<char>& data, vector<int>& frequency) {
	minHeapNode* root;
	root = buildHuffmanTree(data, frequency);
	DecodeHuffmanTree(root, "");
}