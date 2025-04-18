#include<iostream>
#include<string>
#include<unordered_map>
int strStr(std::string haystack, std::string needle)
{
    std::string tempString{""};
    size_t needleSize{needle.size()-1};

    for(size_t i = 0; i< haystack.size(); i++)
    {
        std::string tempString1{""};
        for(int j=i; j <= haystack.size(); j++)
        {
            tempString1+=haystack[j];
            if(tempString1 == needle)
            {
                return i;
            }

        }
        tempString+=haystack[i];
        if(tempString == needle)
        {
            if(i - needleSize == 0)
            {
                if(needle[0] == haystack[0])
                {
                    return 0;
                }
                else
                {
                    return -1;
                }
            }
            
            
            if(haystack[i - needleSize] == needle[0])
            {
                return i - (needleSize);
            }
        }
        else if(tempString.size() > needle.size())
        {
            if(tempString[tempString.size()-1] == needle[0])
            {
                tempString = needle[0];
            }
            else
            {
                tempString="";
            }
        }
    }
    return -1;


}

int main()
{
    std::string haystack{"mississippi"};
    std::string needle{"issi"};
    if(1 == strStr(haystack, needle))
    {
        std::cout << "passed" << std::endl;
    }
    else
    {
        std::cout << strStr(haystack, needle) << std::endl;
    }
    if(0 == strStr("sadbutsad", "sad"))
    {
        std::cout << "passed" << std::endl;
    }
    else
    {
        std::cout << strStr(haystack, needle) << std::endl;
    }
    if(2 == strStr("hello", "ll"))
    {
        std::cout << "passed" << std::endl;
    }
    else
    {
        std::cout << strStr(haystack, needle) << std::endl;
    }
    if(4 == strStr("mississippi", "issip"))
    {
        std::cout << "passed" << std::endl;
    }
    else
    {
        std::cout << strStr(haystack, needle) << std::endl;
    }
    if(4 == strStr("mississippi", "lll"))
    {
        std::cout << "passed" << std::endl;
    }
    else
    {
        std::cout << strStr(haystack, needle) << std::endl;
    }
    if(4 == strStr("aaaa", "baaa"))
    {
        std::cout << "passed" << std::endl;
    }
    else
    {
        std::cout << strStr("aaaa", "baaa") << std::endl;
    }
    return 0;
}
/*
1) store the staring index if the start of the haystack matches the start of needle.
2) store the index in a vector
3) return the minimum index from the vector of index's if the vector is empty return -1;
*/