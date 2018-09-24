#pragma once

#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;

class Node
{
public:
	Node(string nodeName);
	~Node();

	void addConnection(string connectionName);
	string nextNode();
	string getName();

private:
	string nodeName;
	vector<string> connectionNames;
};

