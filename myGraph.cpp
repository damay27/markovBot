#include "myGraph.h"
#include <sstream>
#include <vector>
#include <time.h>
#include <stdlib.h>



Graph::Graph(string text) : currentNode(""), nodes()
{
	addText(text);
}


Graph::~Graph()
{
}

void Graph::addText(string text)
{
	//Split the text at the spaces
	stringstream stream;
	stream << text;
	string tempWord;
	vector<string> words;

	while (getline(stream, tempWord, ' '))
	{
		words.push_back(tempWord);
	}

	int numberWords = words.size();

	for (int count = 0; count < numberWords - 1; count++)
	{
		string word = words.at(count);

		int index = -1;

		for (unsigned int i = 0; i < nodes.size(); i++)
		{

			if (word == nodes.at(i).getName())
			{
				index = i;
				break;
			}
		}


		//Check if a node was found for the current word
		if (index == -1)
		{
			nodes.push_back(Node(word));
			index = nodes.size() - 1;
		}


		string nextWord = words.at(count + 1);
		nodes.at(index).addConnection(nextWord);

	}
}


string Graph::getTweet()
{
	string tweet;

	srand(time(0));

	int startIndex = rand() % nodes.size();

	Node node = nodes.at(startIndex);
	tweet += node.getName() + ' ';

	while (tweet.size() < 240)
	{
		string nextNode = node.nextNode();

		for (int index = 0; index < nodes.size(); index++)
		{
			if (nextNode == nodes.at(index).getName())
			{
				node = nodes.at(index);
				break;
			}
		}

		tweet += node.getName() + ' ';
	}

	return tweet;
}