#pragma once
#include "BTNode.h"
#include "BinaryTree.h"

#include <map>
#include <string>

/* Builds a map and binary tree from a provided file and the description
   of the tree in the project instructions. Encodes and decodes messages
   following the project guidelines.
*/
class MorseCode {
public:
    /* Uses fileName to populate a map for encoding messages and creates
       a binary tree as described in the project instructions

       Throws an error if the file cannot be opened or a line in the 
       file is not a char/code combination

       O(1): while it is actually O(n) the alphabet will 
       always be the same length so it is functionally O(1)
    */
    MorseCode(std::string fileName);

    /* Returns an encoded message using a map populated from the file
       provided in the class constructor to convert the provided message
       to Morse code with each letter code separated a space

       Throws an error if a char other than a letter is used in the message

       O(n lg n): n is the amount of letters to encode and it takes
       O(lg n) to find the corresponding code for each letter
    */
    std::string encode(std::string message);

    /* Returns a decoded message using a tree as described in the project 
       instructions and the provided message in Morse code with each
       letter code separated by a space

       Throws an error if an invalid code or a char other than '.' or '_'
       is used in the message

       O(n lg n): n is the amount of letters be found
       and it takes O(lg n) to find each letter
    */
    std::string decode(std::string message);

private:
    std::map<char, std::string> encoder; // Map for encoding messages
    Binary_Tree<char> decoder; // Binary tree for decoding messages

    /* Returns a char corresponding to the provided code from a
       binary tree described in the project instructions

       Throws an error if an invalid code or a char other than '.' or '_'
       is used in the message

       O(lg n): n is the amount of different types of letters
    */
    char findLetter(std::string code);

    /* Returns the root of a hard-coded binary tree as described 
       in the project directions

       O(1) --- T(17): Hard-coded binary tree
    */
    BTNode<char>* createDecoder();
};