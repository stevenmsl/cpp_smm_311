#ifndef NODE_H
#define NODE_H

#include <vector>
#include <cinttypes>
using namespace std;

namespace sol311
{
    struct Node
    {
        int val;
        Node *next;
        Node(int initVal) : val(initVal), next(nullptr){};
    };
}
#endif