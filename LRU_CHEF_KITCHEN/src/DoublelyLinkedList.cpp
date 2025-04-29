#include "../inc/DoublelyLinkedList.hpp"
#include <iostream>

namespace LinkedList
{
    DoublelyLinkedList::DoublelyLinkedList() : head_(nullptr), tail_(nullptr),size_{0} {}

    bool DoublelyLinkedList::AddNode(int key, std::string val)
    {
        DoubleLL* node = new DoubleLL(key, val, nullptr, nullptr);
        if(head_ == nullptr)
        {
            head_ = node;
            tail_ = node;
            ++size_;
            return true;
        }
        else
        {
            tail_->next_ = node;
            node->prev_ = tail_;
            tail_ = node;
            ++size_;
            return true;
        }
        return false;
    }

    bool DoublelyLinkedList::AddNodeFront(int key, std::string val)
    {
        DoubleLL* node = new DoubleLL(key, val, nullptr, nullptr);
        if(head_ != nullptr)
        {
            node->next_ = head_;
        }
        head_ = node;
        if(tail_ == nullptr)
        {
            tail_ = node;
        }
        ++size_;
        return true;
    }

    bool DoublelyLinkedList::AddNode(int key, std::string val, int position)
    {
        if(position > size_)
        {
            std::cerr << "List out of bounds..." << std::endl;
            return false;
        }

        DoubleLL* node = new DoubleLL(key, val, nullptr, nullptr);

        if(position > 0)
        {
            
            size_t it = 0;
            auto temp = head_;
            while (position != it)
            {
                temp = temp->next_;
                ++it;
            }
            node->prev_ = temp;
            node->next_ = temp->next_;
            temp = node;
            ++size_;
            return true;
        }
        else
        {
            return AddNodeFront(key,val);
        }
        return false;
    }

    bool DoublelyLinkedList::MoveNodeFront(DoubleLL* node)
    {
        if(node == head_)
        {
            return true;
        }

        DoubleLL* prev = node->prev_;
        DoubleLL* next = node->next_;

        if(prev != nullptr)
        {
            prev->next_ = next;
        }

        if(next != nullptr)
        {
            next->prev_ = prev;
        }

        if(head_!= nullptr)
        {
            head_->prev_ = node->next_;
        }

        node->prev_ = nullptr;
        head_ = node;
        
    }

    bool DoublelyLinkedList::RemoveNode(DoubleLL* node)
    {
        if(node == head_)
        {
            head_= node->next_;
            head_->prev_ = nullptr;
            --size_;
            delete node;
            return true;
        }

        if(node == tail_)
        {
            node->prev_->next_= nullptr;
            --size_;
            delete node;
            return true;
        }
        DoubleLL* prev = node->prev_;
        DoubleLL* next = node->next_;
        prev->next_ = next;
        next->prev_ = prev;
        --size_;
        delete node;
    }

    DoubleLL* DoublelyLinkedList::GetNode(std::string& val)
    {
        if(val == head_->val_)
        {
            return head_;
        }

        if(val == tail_->val_)
        {
            return tail_;
        }
        DoubleLL* start = head_;
        DoubleLL* end = tail_;
        while(start == end)
        {
            if(start->val_ == val)
            {
                return start;
            }
            if(end->val_ == val)
            {
                return end;
            }
            if(end != nullptr)
            {
                end = end->prev_;
            }
            if(start != nullptr)
            {
                start = start->next_;
            }
        }
        return nullptr;
    }

    DoubleLL* DoublelyLinkedList::GetNode(int key)
    {
        if(key == head_->key_)
        {
            return head_;
        }

        if(key == tail_->key_)
        {
            return tail_;
        }
        DoubleLL* start = head_;
        DoubleLL* end = tail_;
        while(start == end)
        {
            if(start->key_ == key)
            {
                return start;
            }
            if(end->key_ == key)
            {
                return end;
            }
            if(end != nullptr)
            {
                end = end->prev_;
            }
            if(start != nullptr)
            {
                start = start->next_;
            }
        }

        return nullptr;
    }

    bool DoublelyLinkedList::SwapNodes(DoubleLL* first, DoubleLL* second)
    {
        if (first == head_)
        {
            first->prev_ = second->prev_;
            second->prev_=nullptr;
            first->next_ =
        }
        
    }
}