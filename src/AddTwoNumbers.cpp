// Problem Link:  https://leetcode.com/problems/two-sum/
#include <iostream>
#include <iostream>
#include <vector>
#include <cassert>
#include <string>
#include<sstream>
struct ListNode
{
    int val{};
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


void PrintList(ListNode* l1)
{
    while (l1 != nullptr)
    {
        std::cout<< l1->val;
        l1=l1->next;
    }
    std::cout<< std::endl;
}


ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
    std::stringstream firstNum;
    std::stringstream secondNum;

    while (l1 != nullptr)
    {
        firstNum << l1->val;
        l1 = l1->next;
    }
    while (l2 != nullptr)
    {
        secondNum << l2->val;
        l2 = l2->next;
    }

    std::cout << firstNum.str() << std::endl;
    std::cout << secondNum.str() << std::endl;

    int numOne,numTwo;
    firstNum >> numOne;
    secondNum >> numTwo;
    int sum = numOne + numTwo;
    

    auto head = new ListNode();
    auto temp = head;
    if(sum == 0)
    {
        head->val = 0;
        return head;
    }
    else 
    {
        while(sum>0)
        {   
            int digit = sum % 10;
            auto newNode = new ListNode(digit,nullptr);
            temp->next= newNode;
            temp = newNode;
            sum /= 10;
        }
    }
    return head->next;
}

// Utility function t;o create a linked list from a vector of integers.
ListNode* createList(const std::vector<int>& nums) {
    if (nums.empty()) return nullptr;
    ListNode* head = new ListNode(nums[0]);
    ListNode* current = head;
    for (size_t i = 1; i < nums.size(); ++i) {
        current->next = new ListNode(nums[i]);
        current = current->next;
    }
    return head;
}

// Utility function to compare two linked lists for equality.
bool compareLists(ListNode* l1, ListNode* l2) {
    while (l1 != NULL && l2 != NULL) {
        if (l1->val != l2->val) return false;
        l1 = l1->next;
        l2 = l2->next;
    }
    return l1 == NULL && l2 == NULL;
}

// Utility function to print the result of a test case.
void printTestResult(const std::string& testName, bool passed) {
    std::cout << testName << ": " << (passed ? "PASSED" : "FAILED") << std::endl;
}

// Function to run all test cases.
void runTests() {
    // Test case 1
    ListNode* l1 = createList({2, 4, 3});
    ListNode* l2 = createList({5, 6, 4});
    ListNode* expected = createList({7, 0, 8});
    ListNode* result = addTwoNumbers(l1, l2);
    PrintList(result);
    printTestResult("Test Case 1", compareLists(result, expected));

    // Test case 2
    l1 = createList({0});
    l2 = createList({0});
    expected = createList({0});
    result = addTwoNumbers(l1, l2);
    PrintList(result);
    printTestResult("Test Case 2", compareLists(result, expected));

    // Test case 3
    l1 = createList({9, 9, 9, 9, 9, 9, 9});
    l2 = createList({9, 9, 9, 9});
    expected = createList({8, 9, 9, 9, 0, 0, 0, 1});
    result = addTwoNumbers(l1, l2);
    PrintList(result);
    printTestResult("Test Case 3", compareLists(result, expected));

    // Test case 4
    l1 = createList({2,4,9});
    l2 = createList({5,6,4,9});
    expected = createList({8,9,8,5});
    result = addTwoNumbers(l1, l2);
    PrintList(result);
    printTestResult("Test Case 3", compareLists(result, expected));

    // Free allocated memory for lists
    auto freeList = [](ListNode* list) {
        while (list != NULL) {
            ListNode* temp = list;
            list = list->next;
            delete temp;
        }
    };

    freeList(result);
    freeList(expected);
}

int main() {
    runTests();
    return 0;
}
