#include<iostream>
#include<vector>
#include"KnapsackProblem.h"
#include"JobSequencing.h"
#include"HuffmanCoding.h"
#include"Node.h"
#include<iomanip>
#include"Dijkstra.h"
using namespace std;



int main() {
	int ch;
	do {
		cout << "Problems using Greedy Algorithms" << "\n";
		cout << "\nEnter the problem, you want to solve\n" << endl;
		cout << "[1] - Knapsack Problem\n";
		cout << "[2] - Job Sequencing Problem\n";
		cout << "[3] - Huffman Coding Problem\n";
		cout << "[4] - Dijkstra Shortest Path Problem\n";
		cout << "[0] - Quit\n";
		cout << "\nEnter your choice : ";
		cin >> ch;

		if (ch == 1) {
			vector<int>profits, weights;
			int n,w,x;
			float TotalProfit;
			cout << "Enter the number of objects : ";
			cin >> n;
			for (int i = 0; i < n; i++) {
				cout << "Enter Profit of Object " << i + 1 << " : ";
				cin >> x;
				profits.push_back(x);
				cout << "Enter Weight of Object " << i + 1 << " : ";
				cin >> x;
				weights.push_back(x);
			}

			cout << "Enter Knapsack Capacity : ";
			cin >> w;

			TotalProfit= knapsack(profits, weights, w);
			cout <<setprecision(2)<< "Total Maximum Profit : " << TotalProfit << "\n";
		}
		else if (ch == 2) {
			vector<int>profits, deadlines;
			vector<string>v;
			string s;
			int n,  x;
			int TotalProfit;

			cout << "Enter the number of Jobs : ";
			cin >> n;
			for (int i = 0; i < n; i++) {
				cout << "Enter Job ID " << i + 1 << " : ";
				cin >> s;
				v.push_back(s);
				cout << "Enter Profit of Job " << i + 1 << " : ";
				cin >> x;
				profits.push_back(x);
				cout << "Enter deadline of Job " << i + 1 << " : ";
				cin >> x;
				deadlines.push_back(x);
			}

			TotalProfit = JobSequencing(v, profits, deadlines);
			cout << "\nTotal Profit : " << TotalProfit << "\n";
		}
		else if (ch == 3) {
			vector<char>data{ 'A','B','C','D','E' };
			vector<int>freq{ 3,5,6,4,2 };
			HuffmanCoding(data, freq);
		}
		else if (ch == 4) {
			int n;
			cout << "Enter the number of vertices in a graph : ";
			cin >> n;
			vector<Node*>graph(n+1,nullptr);
			cout << "\nEnter -1 when you want to stop adding nodes connected to any vertex\n";

			for (int i = 1; i <= n; i++) {
				Node* temp=nullptr,*tempnxt=nullptr;
				int x=0,c;
				
				while (x != -1) {
					cout << "Enter the node connected to " << i  << " : ";
					cin >> x;
					if (x != -1) {
						cout << "Enter the distance or cost of the edge from " << i << " to " << x << " : ";
						cin >> c;
						temp = new Node(x, c);
						if (!graph[i]) {
							graph[i] = temp;
						}
						if (tempnxt) {
							tempnxt->next = temp;
						}
						tempnxt = temp;
					}
				}
			}
			Dijkstra(graph, 1);
		}
		else if (ch == 0) {
			cout << "\nThanks for using the program\n";
		}
	} while (ch != 0);
}