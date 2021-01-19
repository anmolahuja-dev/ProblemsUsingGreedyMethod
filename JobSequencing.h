#pragma once
#include<vector>
#include<string>
#include<map>
#include<iostream>
#include<algorithm>
using namespace std;

int getMax(vector<int>& v) {
	int max = -1;
	for (int i = 0; i < v.size(); i++) {
		if(v[i]>max){
			max = v[i];
		}
	}
	return max;
}

int JobSequencing(vector<string>&v,vector<int>&profits, vector<int>&deadlines) {
	multimap<int, pair<string,int>>m;
	vector<int>slot;
	int TotalProfit=0;
	for (int i = 0; i < profits.size(); i++) {
		m.insert(make_pair(profits[i], make_pair(v[i],deadlines[i])));
	}

	auto it = m.rbegin();

	/*Slot = 0 : Available else if 1 : occupied */
	//Slots have 1 based indexing
	
	int jobSlots = getMax(deadlines);

	for (int i = 0; i <= jobSlots; i++) {
		slot.push_back(0);
	}

	int i = 1;
	while (i<slot.size() && it!=m.rend())
	{
		if (it->second.second >= i) {
			slot[i] = 1;
			it->second.second = 0;
			i++; 
		}
		it++;
	}

	it = m.rbegin();
	cout << "Job Sequencing\n";
	while (it!=m.rend())
	{
		if (it->second.second == 0) {
			cout << it->second.first << " ";
			TotalProfit += it->first;
		}
		it++;
	}
	return TotalProfit;
}