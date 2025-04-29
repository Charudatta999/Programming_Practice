#ifndef HEADER_LINKED_LIST
#define HEADER_LINKED_LIST

#include "DoubleLL.hpp"

#include <cstddef>

namespace LinkedList
{

    class DoublelyLinkedList
    {   
        private:
            DoubleLL* GetTail();
            DoubleLL* GetHead();
            DoubleLL* GetNode(int key); // done
            DoubleLL* GetNode(std::string& val); //done
            DoubleLL* head_;
            DoubleLL* tail_;
            size_t size_;

        public:
            DoublelyLinkedList();
            ~DoublelyLinkedList();
            bool AddNode(int key, std::string val); //done
            bool AddNode(int key, std::string val, int positon); //done
            bool AddNodeFront(int key, std::string val); //done
            bool RemoveNode(int key);
            bool RemoveNode(DoubleLL* node); // done
            bool MoveNodeFront(DoubleLL* node); //done
            bool SwapNodes(DoubleLL* first, DoubleLL* second);
            
    };
}
#endif