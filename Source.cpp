// #include <iostream>
// #include <fstream>
// #include <sstream>
// #include <time.h>
// #include <unistd.h>
// using namespace std;

// #include "myNode.h"
// #include "myGraph.h"
// #include <oauthlib.h>
// #include <twitcurl.h>

// // FILE _iob[] = { *stdin, *stdout, *stderr };
// // extern "C" FILE * __cdecl __iob_func(void) { return _iob; }
// // extern "C" void __imp__set_output_format(void) {};

// void setupTwitterAPI(twitCurl &twitter);

// void textCleanUp(string &text);

// int main()
// {
// 	//Get the file and the time spacing between tweets
// 	string filePath;
// 	int minutes;
// 	cout << "Enter the path to text file you want to use as a source: ";
// 	cin >> filePath;
// 	cout << "-------------------------------------------------------------------------------------------------------------" << endl;
// 	cout << "Enter the number of minutes between tweets (must be greater than 10, no one likes a spamer;) ";
// 	cin >> minutes;

// 	if (!cin)
// 	{
// 		cout << "YOU MUST ENTER AND INTEGER FOR THE NUMBER OF MINUTES." << endl;
// 		return -1;
// 	}

// 	if (minutes < 10)
// 	{
// 		cout << "Since you couldn't follow directions the number of minutes has been auto set to 10 minuets." << endl;
// 		minutes = 10;
// 	}


// 	//Open the file and convert it to a string
// 	ifstream file(filePath);

// 	if (!file.is_open())
// 	{
// 		cout << "ERROR OPENING THE TEXT FILE." << endl;
// 		return -1;
// 	}

// 	string text((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());

// 	cout << "Processing the text file..." << endl;
// 	//Clean the text input from the file
// 	textCleanUp(text);

// 	//Generate a graph from the text
// 	Graph graph(text);

// 	//Create a twitcurl object and go through the authentication process
// 	twitCurl twitter;
// 	setupTwitterAPI(twitter);

// 	int nextTweetTime = clock() / CLOCKS_PER_SEC;

// 	while (1)
// 	{


// 		// if ((clock()/CLOCKS_PER_SEC)>=nextTweetTime)
// 		// {
// 			string tweetString = graph.getTweet();
// 			string replyMsg = "";

// 			cout << "------------------------------------------------" << endl;
// 			cout << tweetString << endl;

// 			if (!twitter.statusUpdate(tweetString))
// 			{
// 				twitter.getLastCurlError(replyMsg);
// 				cout << replyMsg << endl;
// 			}

// 			nextTweetTime = (clock() / CLOCKS_PER_SEC) + (60 * minutes);
			
// 			usleep(60 * minutes*1000000);
			
// 		// }
// 	}

// }


// void setupTwitterAPI(twitCurl &twitter)
// {

// 	// twitter.getOAuth().setConsumerKey("z1H4uvVAkwAm269Tpb5PHLWs0");
// 	// twitter.getOAuth().setConsumerSecret("UeR3fx9enThFcPR7wLZAZfE2Qs0RBFSfHLiKDODFqK3EEm5EaE");
// 	string consumerKey, consumerSecret;


// 	string userName, password;
// 	cout << "User Name: ";
// 	cin >> userName;
// 	cout << "Password: ";
// 	cin >> password;
// 	twitter.setTwitterUsername(userName);
// 	twitter.setTwitterPassword(password);

// 	string link;
// 	twitter.oAuthRequestToken(link);
// 	twitter.oAuthHandlePIN(link);

// 	twitter.oAuthAccessToken();
	
	
// 		twitter.getOAuth().getOAuthConsumerKey(consumerKey);
// 		twitter.getOAuth().getOAuthConsumerSecret(consumerSecret);
// 		twitter.get

// 	string tokenKey, tokenSecret;
// 	twitter.getOAuth().getOAuthTokenKey(tokenKey);
// 	twitter.getOAuth().getOAuthTokenSecret(tokenSecret);

// 	twitter.getOAuth().setOAuthTokenKey(tokenKey);
// 	twitter.getOAuth().setOAuthTokenSecret(tokenSecret);


// 	ofile << tokenKey;
// 	ofile << '\n';
// 	ofile << tokenSecret;

// }



// void textCleanUp(string &text)
// {
// 	for (int index = 0; index < text.size(); index++)
// 	{
// 		char currentChar = text.at(index);

// 		//Check if its a character you want to remove
// 		if (currentChar == '"' || currentChar == ',' || currentChar == '\n' || currentChar == '\r')
// 		{
// 			text.erase(text.begin() + index);
// 			//Since a character was removed move the index back by one
// 			index -= 2;//Subtract 2 to go back and look for repeated spaces
// 		}
// 		//Check if its a character you want to replace with a space
// 		else if (currentChar == '\t')
// 		{
// 			text.at(index) = ' ';
// 			index -= 2;//Subtract 2 to go back and look for repeated spaces
// 		}


// 		//Check for repeated spaces and remove them
// 		while ( currentChar == ' ' && (index + 1) < text.size() && text.at(index+1) == ' ')
// 		{
// 			text.erase(text.begin() + index);
// 		}
// 	}
// }





#include <iostream>
#include <fstream>
#include <sstream>
#include <time.h>
#include <unistd.h>
using namespace std;

#include "myNode.h"
#include "myGraph.h"
#include <oauthlib.h>
#include <twitcurl.h>

// FILE _iob[] = { *stdin, *stdout, *stderr };
// extern "C" FILE * __cdecl __iob_func(void) { return _iob; }
// extern "C" void __imp__set_output_format(void) {};

void setupTwitterAPI(twitCurl &twitter);

void textCleanUp(string &text);

int main()
{
	//Get the file and the time spacing between tweets
	string filePath;
	int minutes;
	cout << "Enter the path to text file you want to use as a source: ";
	cin >> filePath;
	cout << "-------------------------------------------------------------------------------------------------------------" << endl;
	cout << "Enter the number of minutes between tweets (must be greater than 10, no one likes a spamer;) ";
	cin >> minutes;

	if (!cin)
	{
		cout << "YOU MUST ENTER AND INTEGER FOR THE NUMBER OF MINUTES." << endl;
		return -1;
	}

	if (minutes < 10)
	{
		cout << "Since you couldn't follow directions the number of minutes has been auto set to 10 minuets." << endl;
		minutes = 10;
	}


	//Open the file and convert it to a string
	ifstream file(filePath);

	if (!file.is_open())
	{
		cout << "ERROR OPENING THE TEXT FILE." << endl;
		return -1;
	}

	string text((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());

	cout << "Processing the text file..." << endl;
	//Clean the text input from the file
	textCleanUp(text);

	//Generate a graph from the text
	Graph graph(text);

	//Create a twitcurl object and go through the authentication process
	twitCurl twitter;
	setupTwitterAPI(twitter);

	int nextTweetTime = clock() / CLOCKS_PER_SEC;

	while (1)
	{


		// if ((clock()/CLOCKS_PER_SEC)>=nextTweetTime)
		// {
			string tweetString = graph.getTweet();
			string replyMsg = "";

			cout << "------------------------------------------------" << endl;
			cout << tweetString << endl;

			if (!twitter.statusUpdate(tweetString))
			{
				twitter.getLastCurlError(replyMsg);
				cout << replyMsg << endl;
			}

			nextTweetTime = (clock() / CLOCKS_PER_SEC) + (60 * minutes);
			
			usleep(60 * minutes*1000000);
			
		// }
	}

}


void setupTwitterAPI(twitCurl &twitter)
{
	string userName, password, consumerKey, consumerSecret;
	cout << "User Name: ";
	cin >> userName;
	cout << "Password: ";
	cin >> password;
	cout<<"Enter your Consumer Key: ";
	cin>>consumerKey;
	cout<<"Enter you Consumer Secret: ";
	cin>>consumerSecret;
	twitter.setTwitterUsername(userName);
	twitter.setTwitterPassword(password);
	twitter.getOAuth().setConsumerKey(consumerKey);
	twitter.getOAuth().setConsumerSecret(consumerSecret);

	string link;
	twitter.oAuthRequestToken(link);
	twitter.oAuthHandlePIN(link);

	twitter.oAuthAccessToken();

	string tokenKey, tokenSecret;
	twitter.getOAuth().getOAuthTokenKey(tokenKey);
	twitter.getOAuth().getOAuthTokenSecret(tokenSecret);

	twitter.getOAuth().setOAuthTokenKey(tokenKey);
	twitter.getOAuth().setOAuthTokenSecret(tokenSecret);

}



void textCleanUp(string &text)
{
	for (int index = 0; index < text.size(); index++)
	{
		char currentChar = text.at(index);

		//Check if its a character you want to remove
		if (currentChar == '"' || currentChar == ',' || currentChar == '\n' || currentChar == '\r')
		{
			text.erase(text.begin() + index);
			//Since a character was removed move the index back by one
			index -= 2;//Subtract 2 to go back and look for repeated spaces
		}
		//Check if its a character you want to replace with a space
		else if (currentChar == '\t')
		{
			text.at(index) = ' ';
			index -= 2;//Subtract 2 to go back and look for repeated spaces
		}


		//Check for repeated spaces and remove them
		while ( currentChar == ' ' && (index + 1) < text.size() && text.at(index+1) == ' ')
		{
			text.erase(text.begin() + index);
		}
	}
}











