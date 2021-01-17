#include<iostream>
#include<vector>
#include"KnapsackProblem.h"
#include<iomanip>
using namespace std;

int main() {
	int ch;
	do {
		cout << "Problems using Greedy Algorithms" << "\n";
		cout << "\nEnter the problem, you want to solve\n" << endl;
		cout << "[1] - Knapsack Problem\n";
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
		else if (ch == 0) {
			cout << "\nThanks for using the program\n";
		}
	} while (ch != 0);
}