#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
int minAddToMakeValid(std::string s) 
{
    int open{0}, close{0};
    for( auto it : s)
    {
        if(it == '(' )
        {
            open++;
        }
        else if( it == ')' && open > 0)
        {
            open--;
        }
        else
        {
            close++;
        }
    }
    return open+close;

}
//     if(parentheses['('] < parentheses[')'])
//     {
        
//         if(parentheses['('] == 0)
//             return  parentheses[')'];
//         return parentheses['('];
//     }
//     else if(parentheses['('] > parentheses[')'])
//     {
//         if(parentheses[')'] == 0)
//             return  parentheses['('];
//         return parentheses[')'];
//     }
//     else
//     {
//         return 0;
//     }
// }

int main()
{
    if(minAddToMakeValid("())") == 1)
    {
        std::cout << "passed" << std::endl;
    }
    else
    {
        std::cout << minAddToMakeValid("())") << std::endl;
    }
    if(minAddToMakeValid("(((") == 3)
    {
            std::cout << "passed" << std::endl;
    }
    else
    {
            std::cout << minAddToMakeValid("(((") << std::endl;
    }
    if(minAddToMakeValid("()))((") == 4)
    {
            std::cout << "passed" << std::endl;
    }
    else
    {
            std::cout << minAddToMakeValid("(((") << std::endl;
    }
 return 0;
}
/*
soln1 ❌
()))((
stack
int add;
int pop;
if(it == '(')
    add (
else(it == ')')
    add )
    pop (

    it0 : ['(']
    it1 : ['(',')']
    it2 : [')',')','(']
    it3 : [')',')',')','(']
    it4 : ['(',')',')',')','(']
    it5 : ['(','(',')',')',')','(']
soln 2 ❌
    0 1 2 3 4 5
    ( ) ) ) ( (
    [(]

    [(]

    [)]
    [)]

    [)]
    [)]
    [)]

    [)]
    [)]
    [)]
    [(]
    [(]

soln 3 ✅ 
    0 1 2 3 4 5
    ( ) ) ) ( (
    int open, close;

    if(it == '(' )
    {
        open++;
    }
    else if( it == ')' && open > 0)
    {
        open--;
    }
    else
    {
        close++;
    }

    return open+close;


soln 4 ❌
    0 1 2 3 4 5
    ( ) ) ) ( (
bool open
bool close
int valid;

if(it == '(')
    add (;
    open =true;
    add++;
else(it == ')')
    pop (;
    pop++;
    close = true;
    if(open == close)
    {
        valid ++;
    }
    open = false;
    it0 :  ['('] a = 1; p = 0; open = true;

    it1 :  [] a = 1; p = 1; close = flase; open = true; valid= 0;
    it2 : [] p = 2; a = 1; close = false; open = true;  -> close = true; valid=1; open =flase;
    it3 : [] p = 3; a = 1; close = true; open = false; valid=1;
    it4 : ['('] p = 3; a = 2; close = true; open = true; valid=1;
    it4 : ['(','('] p = 3; a = 3; close = true; open = true; valid=1;

    
*/