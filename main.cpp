#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol311;

/*
Input:

A = [
  [ 1, 0, 0],
  [-1, 0, 3]
]

B = [
  [ 7, 0, 0 ],
  [ 0, 0, 0 ],
  [ 0, 0, 1 ]
]

Output:

     |  1 0 0 |   | 7 0 0 |   |  7 0 0 |
AB = | -1 0 3 | x | 0 0 0 | = | -7 0 3 |
                  | 0 0 1 |
*/

tuple<vector<vector<int>>, vector<vector<int>>, vector<vector<int>>> testFixture1()
{
  auto const A = vector<vector<int>>{
      {1, 0, 0},
      {-1, 0, 3}};
  auto const B = vector<vector<int>>{
      {7, 0, 0},
      {0, 0, 0},
      {0, 0, 1}};
  auto const output = vector<vector<int>>{
      {7, 0, 0},
      {-7, 0, 3}};

  return make_tuple(A, B, output);
}

void test1()
{
  auto f = testFixture1();
  cout << "Test 1 - expect to see " << Util::toString(get<2>(f)) << endl;
  Solution sol;
  cout << "result: " << Util::toString(sol.multiply(get<0>(f), get<1>(f))) << endl;
}

main()
{
  test1();
  return 0;
}