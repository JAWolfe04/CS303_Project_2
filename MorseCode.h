#pragma once
#include "BTNode.h"
#include "BinaryTree.h"

#include <map>
#include <string>

class MorseCode
{
public:
    MorseCode(std::string fileName);

    std::string encode(std::string message);
    std::string decode(std::string message);

private:
    std::map<char, std::string> encoder;
    Binary_Tree<char> decoder;

    char findLetter(std::string code);
    BTNode<char>* createDecoder();
};