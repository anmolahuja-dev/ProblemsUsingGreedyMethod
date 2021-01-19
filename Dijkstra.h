#pragma once
#include<iostream>
#include<vector>
#include"Node.h"
using namespace std;

void printShortestPath(vector<int>& dist) {
	cout << "\n";
	cout << "Vertex" << "          " << "Distance from Source\n";
	for (int i = 1; i < dist.size(); i++) {
		cout << "  " << i << "            " << "             " << dist[i] << "\n";
	}
}

int minDist(vector<int>&dist,vector<bool>&visited) {
	int min = INT16_MAX;
	for (int i = 0; i < dist.size(); i++) {
		if (dist[i] < min && visited[i]!=true) {
			min = dist[i];
		}
	}
	int j = 0;
	for (; j < dist.size(); j++)
		if (dist[j] == min)break;

	return j;
}

void Dijkstra(vector<Node*>graph, int source) {
	Node * v;
	//first make the two arrays distance and visited Nodes array to keep track of em
	vector<int>dist(graph.size(),INT16_MAX);
	vector<bool>visitedNodes(graph.size(),false);
	
	visitedNodes[0] = true;
	dist[source] = 0;
	visitedNodes[source] = true;
	
	Node* p = graph[source];
	while (p) {
		dist[p->data] = p->cost;
		p = p->next;
	}

	for (int i = 1; i < graph.size(); i++) {
		int u = minDist(dist,visitedNodes);
		p = graph[u];
		while (p) {
			v = p;
			if (dist[u] + p->cost < dist[v->data]) {
				dist[p->data] = dist[u] + v->cost;
			}
			p = p->next;
		}
		visitedNodes[u] = true;
	}

	printShortestPath(dist);
}

