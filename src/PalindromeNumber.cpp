#include<iostream>
bool isPalindrome(int num)
{
    if(num < 0)
    {
        return false;
    }
    int tempNum{0};
    int check{num};
    int digit{0};
    while(num > 0)
    {
        digit = num % 10;
        num = num/10;
        tempNum= tempNum * 10 +  digit;
    }
    return tempNum == check;

}



int main() {
    // Test cases
    struct TestCase {
        int input;
        bool expectedOutput;
    };

    TestCase testCases[] = {
        {12321, true},
        {-121, false},
        {10, false},
        {12321, true},
        {123, false}
    };

    for (const auto& test : testCases) {
        bool result = isPalindrome(test.input);
        std::cout << "Input: x = " << test.input << std::endl;
        std::cout << "Output: " << (result ? "true" : "false") << std::endl;
        std::cout << "Expected Output: " << (test.expectedOutput ? "true" : "false") << std::endl;
        std::cout << (result == test.expectedOutput ? "Test Passed" : "Test Failed") << std::endl;
        std::cout << "---------------------------------" << std::endl;
    }

    return 0;
}