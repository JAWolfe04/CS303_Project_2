#include "MorseCode.h"
#include "BTNode.h"
#include <iostream>
#include <fstream>

using namespace std;
MorseCode::MorseCode(std::string fileName)
{
	ifstream fin(fileName);
	char ch;
	string s;
	if (!fin)									//throw error if can't open file
		cout << "Error opening input file!";
	
	//BTNode<Item_Type>* root = NULL;
	
	while (!fin.eof())
	{
		fin >> ch;
		getline(fin,s);
		
		//Insert function to build the tree?
	}
	// Open the morse code data file using fileName (make sure to validate that it is opened correctly)
	// Populate the Encoder using bracket assignment from the data in the file extracting each line of the file
	// into a string variable and separating the string by the first character and the remaining substring
	// Make sure to close the file
	// Populate the decoder by setting the root of the tree using the createDecoder function.
	fin.close();
}

BTNode<char>* MorseCode::createDecoder()
{
	//localRoot = new BTNode<Item_Type>;

	// Create a null node for the root of the decoder tree. 
	// Replicate the tree in the project example. Using the root, use (->right) and (->left) to mark where 
	// each of the 26 letters of the alphabet is on that tree and assign it to the new node of that letter
	// Return the root
	return nullptr;
}

std::string MorseCode::encode(std::string message)
{
	// Create an empty string to hold the encoded message
	// For each letter in the message, get the code for each letter from the encoder and concatonate that to the 
	// string, followed by a space
	// Make sure to convert each letter of the message to lowercase before getting the code for the letter
	// Return the encoded message
	return std::string();
}

std::string MorseCode::decode(std::string message)
{
	// Create an empty string to hold the decoded message.
	// For each code segment from the message which is separated by spaces, concatonate the decoded 
	// message with the corresponding letter using the findLetter function
	// Return the decoded message 
	return std::string();
}

char MorseCode::findLetter(std::string code)
{
	// Get a pointer to the root of the decoder tree 
	// Check to make sure that the morse code string is at most the height of the tree ( <= 4 ). If not, return an error. 
	// For each character in the morse code string, check if it is a dot or dash. If it is a dot, move to the left tree. 
	// If it is a dash, move to the right tree.
	// If the node returned is not null, return the data at the node. Else, throw an error. 
	return 0;
}

