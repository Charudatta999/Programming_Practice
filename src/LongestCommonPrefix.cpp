#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
const int ALPHABETSIZE=26; 
struct Node
{
    char ch{};
    bool isTerminalChar{false};
    size_t childCount{0};
    Node* children[ALPHABETSIZE];
    Node(char chr)
    {
        for( int i = 0; i < ALPHABETSIZE; i++)
        {
            children[i] = nullptr;
        }
        ch = chr;
    };
};

bool IsCharPresent(char ch, Node* node)
{
    auto index = ch - 'a';
    return node->children[index] != nullptr;
}

void  InsertWord(std::string str, Node* node)
{
        for(auto it: str)
        {
            if(IsCharPresent(it,node))
            {
                node = node->children[it - 'a'];
            }
            else
            {
                // node[it - 'a'].ch = it;// incorrect
                node->children[it - 'a'] = new Node(it);
                node->childCount++;
                node = node->children[it - 'a'];
            } 
        }
        node->isTerminalChar = true;
}

bool IsPrefix(std::string prefix, Node* node)
{
    for(auto it : prefix)
    {
        if(!IsCharPresent(it,node))
        {
            return false;
        }
        node = node->children[it - 'a'];
    }
    if(node->isTerminalChar)
        return  false;
    return true;
}

std::string FindPrefix(Node* node)
{
    std::string prefix;
    while (node)
    {
        if (node->childCount != 1 || node->isTerminalChar)
        {
            break;
        }

        for (int i = 0; i < ALPHABETSIZE; i++) {
            if (node->children[i] != nullptr) {
                prefix += 'a' + i;
                node = node->children[i];
                break;
            }
        }
    }
    return prefix;
}

std::string LCP(std::vector<std::string> strs)
{
    Node* trie = new Node('\0');
    for( auto word : strs)
    {
        InsertWord(word, trie);
    }
    return FindPrefix(trie);
}

int main()
{
    // std::cout << LCP({"dog","racecar","car"}) << std::endl;
    std::cout << LCP({"flower","flow","flight"}) << std::endl;
    // std::cout << LCP({"","b"}) << std::endl;
    // std::cout << LCP({"flower","flower","flower","flower"}) << std::endl;
    return 0;
}

/*
output: 
[cjadhav@136470-P14s leetCode]$ ./LCP 

fl

flow
expected output:
[cjadhav@136470-P14s leetCode]$ ./LCP 

fl

flower
result: Failed
*/