#include<iostream>
#include<string>
#include<vector>
int lengthOfLastWord(std::string s) 
{
    int i = 0;
    int j = 0;
    bool inSpace = true; // Track if we are currently in a space
    int maxLen{0};
    while (i <= s.size()) {
        if (i == s.size() || s[i] == ' ') { // Check if we reached the end or a space
            if (!inSpace) { // Only print if we were not in a space
                std::string substr = s.substr(j, i - j);// Extract the substring
                if(substr.length() > maxLen) 
                    maxLen = substr.length();
                std::cout << substr << std::endl; // Print the substring
                inSpace = true; // Now we are in a space
            }
            j = i + 1; // Move j to the next character after the space
        } else {
            inSpace = false; // We are not in a space
        }
        ++i;
    }
    return  maxLen;       
}

int main()
{
    std::string s = "Hello World";
    std::string s1 = "   fly me   to   the moon  ";
    std::string s2 = "luffy is still joyboy";
    lengthOfLastWord(s);
    lengthOfLastWord(s1);
    lengthOfLastWord(s2);
 return 0;
}