#include<iostream>
#include<string>
#include<vector>

std::vector<std::string> generateParenthesis(int n) 
{
    std::string parenthesis = "";
    for (size_t i = 0; i < n; i++)
    {
       std::cout << "()" ;
    }
    std::cout << std::endl;
    for (size_t i = 0; i < n; i++)
    {
        std::cout << "(";
    }
    for (size_t i = 0; i < n; i++)
    {
        std::cout << ")";
    }
    std::cout << std::endl;
    return std::vector<std::string> {""};
    
}
int main()
{
    int n =1;
    generateParenthesis(n);
 return 0;
}

/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]

Example 2:

Input: n = 1
Output: ["()"]

To solve this problem, you can use a recursive approach. Here's how you can approach the task and put your mind in the right direction:

    Base Case: Start by identifying the base case. When n is 0, there's only one possible combination: an empty string.

    Recursive Case: For each pair of parentheses, you have two options: open a new parenthesis or close an existing open parenthesis. So, you'll recursively generate combinations by trying both options for each parenthesis.

    Recursion with Backtracking: Use recursion to explore all possibilities. When adding an open parenthesis, decrement n by 1 to indicate that one opening parenthesis has been used. When adding a closing parenthesis, make sure there's a matching open parenthesis available (meaning n hasn't reached 0 yet).

    Build and Return the Combinations: As you explore the possibilities, build and store the combinations in a list. Once you've exhausted all possibilities for a given state, return the list of combinations.

    Edge Cases: Handle edge cases like if n is negative or zero, and set up the initial call to the recursive function.

In terms of algorithm, the key idea is to generate all possible combinations while ensuring that they're well-formed parentheses. The recursive approach allows you to explore these combinations in a structured manner. Remember to think about the base case, the recursive cases, and how to build and return the combinations as you traverse the recursion tree.

In terms of implementation, you can create a recursive function that takes parameters such as the current combination being built, the remaining open and close parentheses, and the list to store combinations. Each recursive call will decide whether to add an open or close parenthesis, and the parameters will be updated accordingly.

Remember that recursive problems often involve thinking about how to break down the problem into smaller, more manageable subproblems, and how to combine the results of those subproblems to get the final solution.

Constraints:

    1 <= n <= 8


*/