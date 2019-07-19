#include "MorseCode.h"
#include "BTNode.h"
#include <iostream>
#include <fstream>
#include <map>
using namespace std;
MorseCode::MorseCode(std::string fileName)
{
   ifstream fin(fileName);
    char letter;
    string morse;
    if (!fin)									//throw error if can't open file
        cout << "Error opening input file!";
	
    while (!fin.eof())

    {
        fin >> letter;
        getline(fin,morse);
		
        //createDecoder(ch, s);
        encoder.insert(pair<char, string>(letter, morse)); //inserting the values read in, into a map
	}
    // Open the morse code data file using fileName (make sure to validate that it is opened correctly)
    // Populate the Encoder using bracket assignment from the data in the file extracting each line of the file
    // into a string variable and separating the string by the first character and the remaining substring
    // Make sure to close the file
    // Populate the decoder by setting the root of the tree using the createDecoder function.
    fin.close();
    decoder.setRoot(createDecoder());
}

BTNode<char>* MorseCode::createDecoder()
{
    BTNode<char>* root = new BTNode<char>(' ', new BTNode<char>('e'), new BTNode<char>('t')); //created binary tree
    root->left->left = new BTNode<char>('i', new BTNode<char>('s'), new BTNode<char>('u'));
    root->left->left->left->left = new BTNode<char>('h');
    root->left->left->left->right = new BTNode<char>('v');
    root->left->left->right->left = new BTNode<char>('f');
    root->left->right = new BTNode<char>('a', new BTNode<char>('r'), new BTNode<char>('w'));
    root->left->right->left->left = new BTNode<char>('l');
    root->left->right->right->left = new BTNode<char>('p');
    root->left->right->right->right = new BTNode<char>('j');
    root->right->left = new BTNode<char>('n', new BTNode<char>('d'), new BTNode<char>('k'));
    root->right->left->left->left = new BTNode<char>('b');
    root->right->left->left->right = new BTNode<char>('x');
    root->right->left->right->left = new BTNode<char>('c');
    root->right->left->right->right = new BTNode<char>('y');
    root->right->right = new BTNode<char>('m', new BTNode<char>('g'), new BTNode<char>('o'));
    root->right->right->left->left = new BTNode<char>('z');
    root->right->right->left->right = new BTNode<char>('q');

    // Create a null node for the root of the decoder tree. 
    // Replicate the tree in the project example. Using the root, use (->right) and (->left) to mark where 
    // each of the 26 letters of the alphabet is on that tree and assign it to the new node of that letter
    // Return the root
    return root;
}

std::string MorseCode::encode(std::string message)
{
    
	string morse = "";

	//Convert each character in message to lowercase and find and find it in the map
	for (int i = 0; i < message.length(); i++) {
		char currChar = tolower(message[i]);
		map<char, string>::iterator itr = encoder.find(currChar);

		//Add morse code corresponding to the character to the morse code string, followed by a space
		string currString;
		if (itr != encoder.end())
			currString = itr->second;
		else
			throw ("Character not found");
		morse += currString;
		morse += ' ';
	}
	return morse;
}

std::string MorseCode::decode(std::string message)
{
    
	string decoded = "";
	string fragment = "";

	//For each character in the morse code message, add to fragment if it is not a space
	for (int i = 0; i < message.length(); i++) {
		if (message[i] != ' ')
			fragment += message[i];

		//If character is a space, find the letter corresponding to the fragment in the binary tree, add to decoded string
		//Reset the fragment as an empty string for the next character
		else {
			char currChar = findLetter(fragment);
			decoded += currChar;
			fragment = "";
		}
	}
	return decoded;
}

char MorseCode::findLetter(std::string code)
{
    //Create pointer to the root of the decoder tree
	BTNode<char>* localRoot = decoder.getRoot();

	//The max height of the tree is 4, so any code length greater than that is invalid
	if (code.length() > 4 )
		throw("Invalid string length");

	//If the character in code is '.', move to left child. If it is '_', move to right. If neither, it is invalid
	for (int i = 0; i < code.length(); i++) {
		if (code[i] == '.')
			localRoot = localRoot->left;
		else if (code[i] == '_')
			localRoot = localRoot->right;
		else
			throw("Invalid character");
	}

	//Return the character at the resulting node, if there is one
	if (localRoot != NULL)
		return localRoot->data;
	else
		throw("Invalid code");
}

