#include <iostream>
#include <string>
#include <vector>
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// ListNode *MergeTwoSortedLists(ListNode *list1, ListNode *list2)
// {   
//         ListNode* current = new ListNode();
//         ListNode* head = current;
//         // std::cout << head->val << std::endl;
//         if(list1 == nullptr)
//         {
//            return list2;
//         }
//         if(list2 == nullptr)
//         {
//             return list1;
//         }    
        
//         while(list1 != nullptr || list2 != nullptr)
//         {
//             if(list1 && list2 == nullptr)
//             {
//                 current->next = list1;
//                 list1 = list1->next;
//                 break;
//             }
//             else if(list2 && list1 == nullptr)
//             {
//                 current->next = list2;
//                 list2 = list2->next;
//                 break;
//             }
//             else if(list1->val < list2->val)
//             {
//                 current->next=list1;
//                 list1 = list1->next;
//             }
//             else
//             {
//                 current->next = list2;
//                 list2 = list2->next;
//             }
//             current = current->next;

//         }

//         return head->next;
// }
ListNode* MergeTwoSortedLists(ListNode* list1, ListNode* list2) {
    
        ListNode* current = new ListNode();
        ListNode* head = current;
        // std::cout << head->val << std::endl;
        if(list1 == nullptr)
        {
           return list2;
        }
        if(list2 == nullptr)
        {
            return list1;
        }
        while (list1 != nullptr || list2 != nullptr)
        {
            if(list1 && list2 == nullptr)
            {
                current->next = list1;
                list1 = list1->next;
                break;
            }
            else if(list2 && list1 == nullptr)
            {
                current->next = list2;
                list2 = list2->next;
                break;
            }
            
            if(list1->val > list2->val)
            {
                current->next = list2;
                list2 = list2->next;
            }
            else if(list1->val <= list2->val)
            {
                current->next = list1;
                list1 = list1->next;
            }
            
            
            current = current->next;
        } 
        return head;
    }
void InsertListNodeAtEnd(int i, ListNode *&head)
{
    ListNode *temp = new ListNode();
    temp->val = i;
    ListNode *current = head;
    if (head == nullptr)
    {
        head = temp;
    }
    else
    {
        while (current->next != nullptr)
            current = current->next;
        current->next = temp;
    }
}

void Printval(ListNode *ListNode)
{
    while (ListNode)
    {
        std::cout << ListNode->val ;
        ListNode = ListNode->next;
    }
    std::cout << std::endl;
}

int main()
{
    ListNode *L1 = new ListNode();
    ListNode *L2 = new ListNode();
    for (auto it : {2})
    {
        InsertListNodeAtEnd(it, L1);
    }
    for (auto it : {1})
    {
        InsertListNodeAtEnd(it, L2);
    }
    ListNode *L3 = new ListNode();
    ListNode *L4 = new ListNode();
    for (auto it : {1,2,4})
    {
        InsertListNodeAtEnd(it, L3);
    }
    for (auto it : {1,3,4})
    {
        InsertListNodeAtEnd(it, L4);
    }
    // Printval(L1);
    // Printval(L2);
    Printval(MergeTwoSortedLists(L1, L2));
    Printval(MergeTwoSortedLists(L3, L4));
    return 0;
}

/*
Input
list1 =
[]
list2 =
[0]
Output
[]
Expected
[0]
*/ 

/*
Steps:
    1) Set Temp HEAD to first List
        ListNode* head = list1;
       ListNode* current = head
    2) Iterate over second List
        while()
    4) Compare the current.val to current.val of second list.
    5) If current of L1.val is > than current.val of second list
        then insert the ListNode in between.
    6) If current of L1.val is < than current.val of second list
        then insert the ListNode before the current.
    7) return the head
*/