#include "myNode.h"
#include <random>
#include <time.h>



Node::Node(string nodeName) : nodeName(nodeName), connectionNames()
{
	srand(time(0));
}


Node::~Node()
{
}


void Node::addConnection(string connectionName)
{
	connectionNames.push_back(connectionName);
	return;
}

//void Node::addConnection(string connectionName)
//{
//	int length = (int)connectionNames.size();
//	int location = -1;
//
//
//	//See if you can the name is in the list already
//	for (int index = 0; index < length; index++)
//	{
//		if (connectionNames.at(index) == connectionName)
//		{
//			location = index;
//			break;
//		}
//	}
//
//	//if the location is still -1 then the connectionName seaarched for was not found in the list
//	if (location == -1)
//	{
//		//Both of the vectors should ALWAYS grow together and be the same size
//		connectionNames.push_back(connectionName);
//		connectionCount.push_back(1.0);
//	}
//	else
//	{
//		connectionCount.at(location) = connectionCount.at(location) + 1;
//	}
//
//	return;
//}

string Node::nextNode()
{
	int randomIndex = rand() % (int)connectionNames.size();

	return connectionNames.at(randomIndex);
}


string Node::getName()
{
	return nodeName;
}
