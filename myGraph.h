#include <string>
#include "myNode.h"
using namespace std;


#pragma once
class Graph
{
public:
	Graph(string text);
	~Graph();

	string getTweet();
	void addText(string text);

private:
	vector<Node> nodes;
	Node currentNode;


};

