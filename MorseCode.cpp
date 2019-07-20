#include "MorseCode.h"
#include "BTNode.h"

#include <string>
#include <fstream>
#include <sstream>
#include <map>

MorseCode::MorseCode(std::string fileName) {
    std::ifstream fin(fileName);
    std::string inputLine;

    // Throw error if can't open file
    if (!fin)
        throw std::exception("Error opening input file!");

    // Inserts each line of the file into the encoding map with the letter
    // as the key and code as the value
    // O(1)-- T(n)= 26: while it is actually O(n) the alphabet will 
    // always be the same length so it is functionally O(1)
    while (fin >> inputLine) {
        if (inputLine.size() < 2)
            throw std::exception("Line in file not a char/code combination.");

        encoder[tolower(inputLine[0])] = inputLine.substr(1);
    }
   
    fin.close();

    // Sets the binary tree root to the constructed tree from the 
    // project instructions
    decoder.setRoot(createDecoder());
}

BTNode<char>* MorseCode::createDecoder() {
    // Create and return a hard-coded binary tree as described in the project instructions
    BTNode<char>* root = new BTNode<char>(NULL, new BTNode<char>('e'), new BTNode<char>('t')); 
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
   
    return root;
}

std::string MorseCode::encode(std::string message) {
    std::string morse = "";

    // Convert each character in message to lowercase and find 
    // it in the map. O(n lg n) since each character in the message must 
    // be found in a map
    for (size_t i = 0; i < message.length(); ++i) {
        // O(lg n) for encoder.find
        auto itr = encoder.find(tolower(message[i]));

        // Add morse code corresponding to the character to the morse code 
        // string, followed by a space
        if (itr != encoder.end())
            morse += itr->second + ' ';
        else
            throw ("Invalid character in message directed to encode.");
    }
    return morse;
}

std::string MorseCode::decode(std::string message) {
    std::string decoded = "";
    std::stringstream inputCode(message);
    std::string fragment;

    //Find the letter corresponding to the code in the binary tree, add to decoded string
    while (inputCode >> fragment)
        decoded += findLetter(fragment);

    return decoded;
}

char MorseCode::findLetter(std::string code) {
    // Create pointer to the node of the corresponding 
    // code starting with the root
    BTNode<char>* localRoot = decoder.getRoot();

    // The max height of the tree is 4, so any code length greater 
    // than that is invalid
    if (code.length() > 4 )
        throw("Invalid code length");

    // If the character in code is '.', move to left child. 
    // If it is '_', move to right. If neither, it is invalid
    for (size_t i = 0; i < code.length(); i++) {
        if (code[i] == '.')
            localRoot = localRoot->left;
        else if (code[i] == '_')
            localRoot = localRoot->right;
        else
            throw("Invalid character in encoded message.");
    }

    //Return the character at the resulting node, otherwise throw an error
    return localRoot != NULL ? localRoot->data : 
        throw("Invalid code in encoded message.");
}