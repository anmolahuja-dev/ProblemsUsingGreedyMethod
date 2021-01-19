#pragma once
struct Node {
	int data;
	int cost;
	Node* next;

	Node(int data, int cost) {
		this->cost = cost;
		this->data = data;
		next = nullptr;
	}
};