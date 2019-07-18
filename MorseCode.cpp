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
    root->right->left->right->left = new BTNode<char>('y');
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

BTNode<char>* MorseCode::createDecoder()
{
    // Create a null node for the root of the decoder tree. 
    // Replicate the tree in the project example. Using the root, use (->right) and (->left) to mark where 
    // each of the 26 letters of the alphabet is on that tree and assign it to the new node of that letter
    // Return the root
    return nullptr;
}
