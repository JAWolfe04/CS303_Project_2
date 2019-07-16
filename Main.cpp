
int main()
{
    // Pull in the morse code text file
    MorseCode morseCode("morse.txt");

    // Tests for encode and decode for each letter of the alphabet
    std::string encodedMessage = morseCode.encode("abcdefghijklmnopqrstuvwxyz");

    //Prints out the encoded and decoded message
    std::cout << encodedMessage << " = " << 
        morseCode.decode(encodedMessage) << std::endl;

    return 0;
}
