#include "../inc/DoubleLL.hpp"

namespace LinkedList
{
    DoubleLL::DoubleLL(int key, std::string val, DoubleLL* next , DoubleLL* prev): key_(key), val_(val), next_(next), prev_(prev)
    {}
}