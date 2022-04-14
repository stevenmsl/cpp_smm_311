
#ifndef SOLUTION_H
#define SOLUTION_H

#include "node.h"
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>

using namespace std;
namespace sol311
{
    class Solution
    {
    private:
    public:
        vector<vector<int>> multiply(vector<vector<int>> &A,
                                     vector<vector<int>> &B);
    };
}
#endif