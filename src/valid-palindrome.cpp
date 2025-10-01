#include <string>
#include <unordered_map>
#include <iostream>
bool isPalindrome(std::string s) 
{
        std::string sentence;
        for (char c : s)
        {
            if (std::isalnum(c)) {
                sentence += std::tolower(c);
            }
        }
        size_t end,start;
        start = 0; end = sentence.length() -1;
        while (start < end)
        {
            if(sentence[start] != sentence[end])
            {
                return false;
            }
            ++start;
            --end;
        }
        return true;
}

int main()
{
    std::unordered_map<std::string,bool> strings {{"A man, a plan, a canal: Panama",true},{"race a car",false},{" ",true}};
    for (const auto& [s, expected] : strings) 
    {
        if(expected == isPalindrome(s))
        {
            std::cout << "passed" << std::endl;
        }
    }
    
    

}