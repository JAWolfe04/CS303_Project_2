# CS303_Project_2
CS 303 Project 2B

Description
----------------------------------

Morse code is a common code that is used to encode messages consisting of letters and digits. Each letter consists of a series of dots and dashes, for example, the code for the letter a is - and the code for the letter b is -. Store each letter of the alphabet in a node of a binary tree of depth 4. The root node is at depth 0 and stores no letter. The left node at depth 1 stores the letter e (code ) and the right node stores the letter t (code is -). The four nodes at depth 2 stores the letters with codes (,-, -, --). To build the tree (See the figure below), read a file in which each line consists of a letter followed by its code. The letters should be ordered by tree depth. To find the position for a letter in the tree, scan the code and branch left for a dot and branch right for a dash. Encode a message by replacing each letter by its code symbol. Then decode the message using Morse code tree. Make sure you use a delimiter symbol between coded letters.

Requirements
----------------------------------

- Write a function that builds the morse tree shown in the figure above. The  information of the tree (the letters and the codes) is stored in a file. You can find the file here: https://www.dropbox.com/s/3cj8yb8gcdsrefg/morse.txt?dl=0 (Notice that the file hasn’t been laid out in convenient order for building the tree). 

- Your system should be able to decode a message using the morse tree that you built. For example, decoding -  -- results in “dg”. The problem text briefly explains how you can do that. Notice that between the symbols (dots and dashes) is a space. The space is a delimiter that separates the codes for letters. 

- Your system should also encode a message. For example, encoding “ac” results in -  --. 

- You may use a binary search tree or a map to store the codes for letters. 

Assumptions
----------------------------------
- You may assume that the character delimiters are simply spaces. 

- You may assume the string has one word only. 

- You are welcome to use the source code on Blackboard (e.g. Binary_Tree, Binary_Search_Tree). 

- You may just call the decode and encode functions in the main function. There is no need for getting input from the user or a menu-based system. 
