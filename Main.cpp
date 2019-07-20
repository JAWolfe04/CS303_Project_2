#include "MorseCode.h"
#include <iostream>

/*  Assumes morse.txt is the input file containing 26 letters of the modern 
    English alphabet with one letter at the start of each line followed by 
    the Morse code consisting of up to 4 '.'s and/or '_'s for that letter. 
    There should not be any other symbols other than the letters, code, 
    end of line characters and end of file. The encoded message must be a
    single word of only letters of the modern English alphabet. Assumes
    the Morse codes in the file correspond to the order of the described
    tree in the project instructions.
*/
// O(n lg n)
int main() {
    // Pull in the Morse code text file
    // O(1)
    MorseCode morseCode("morse.txt");

    // Tests for encode and decode for each letter of the alphabet
    // O(n lg n)
    std::string encodedMessage = morseCode.encode("abCdefGhijklmnoPqrstUvwxYz");

    // Prints out the encoded and decoded message
    // O(n lg n)
    std::cout << encodedMessage << " = " << 
        morseCode.decode(encodedMessage) << std::endl;

    return 0;
}