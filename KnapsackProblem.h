#pragma once
#include<vector>
#include<algorithm>
using namespace std;

int Max(vector<float>& v) {
	auto max=v.begin();
	max = max_element(v.begin(), v.end());
	int i = 0;
	for (; i < v.size(); i++) {
		if (v[i] == *max) {
			break;
		}
	}
	return i;
}

//This Method takes O(n2) time to calculate. It can be reduced to O(nlogn) by using quickSort 
//or we can use data structure called map to reduce
float knapsack(vector<int>& profit, vector<int>& weights,int w) {
	vector<float>ppw,x;  //profit per weight;
	
	int knapsackweight=0;
	float Totalprofit=0;

	for (int i = 0; i < profit.size(); i++) {
		x.push_back(0);
	}

	for (int i = 0; i < profit.size(); i++) {
		ppw.push_back((float)profit[i] / (float)weights[i]);
	}

	for (int i = 0; i < ppw.size(); i++) {
	
		int maxElementIndex = Max(ppw);
		ppw[maxElementIndex] = 0;

		if (knapsackweight != w) {
			if (weights[maxElementIndex]+knapsackweight <= w) {
				knapsackweight += weights[maxElementIndex];
				x[maxElementIndex] = 1;
			}
			else {
				int wgt = weights[maxElementIndex];
				while (knapsackweight + wgt != w) {
					wgt--;
				}
				knapsackweight += wgt;
				x[maxElementIndex] = (float)wgt /(float) weights[maxElementIndex];
			}
		}
		else {
			break;
		}
		
	}

	for (int i = 0; i < profit.size(); i++) {
		Totalprofit += x[i] * (float) profit[i];
	}

	
	return Totalprofit;
}