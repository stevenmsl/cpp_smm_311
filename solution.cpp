#include "solution.h"
#include "util.h"
#include <unordered_set>
#include <algorithm>
#include <iterator>
#include <unordered_map>
#include <queue>
using namespace sol311;
using namespace std;

/*takeaways
  - record the non-zero cols in B row by row
  - look at each non-zero A[i][j] and calculate its
    contribution to the cols in R's ith row
    R[i][col] = A[i][j] * B[j][col] where B[j][col] != 0

  - A = [ 1, 0, 0     x   B= [7, 0, 0
         -1, 0, 3]            0, 0, 0
                              0, 0, 1]
  - R = [ 7,  0, 0
          -7, 0, 3]

  - view multiplication differently: when calculating
    the product of AxB, A[0][0] is involved
    in calculating every entry in the first row of R:
    R[0][0] = A[0][0]*B[0][0] + ...
    R[0][1] = A[0][0]*B[0][1] + ...
    R[0][2] = A[0][0]*B[0][2] + ...
*/

vector<vector<int>> Solution::multiply(vector<vector<int>> &A,
                                       vector<vector<int>> &B)
{
  const int m = A.size();
  const int n = B.size();
  const int l = B[0].size();

  /* record the index of the non-zero cols
     row by row in B
  */
  auto nonZero = vector<vector<int>>();
  for (auto i = 0; i < n; i++)
  {
    auto cols = vector<int>();
    for (auto j = 0; j < l; j++)
      if (B[i][j] != 0)
        cols.push_back(j);
    nonZero.push_back(cols);
  }

  /* the dimensions of the resulting matrix
     - number of rows in A * number of cols in B
  */
  auto result = vector<vector<int>>(m, vector<int>(l));

  /* we record the non-zero cols in B row by row, so we
     will do the matrix product a bit differently
     - given an entry A[i][j], it will contribute
       partially to the product sum of the resulting
       matrix for all the entries in the ith row
     - for example
       A[0][0]*B[0][0] -> R[0][0]
       A[0][0]*B[0][1] -> R[0][1]
       A[0][0]*B[0][2] -> R[0][2]
  */

  /* for each row in A */
  for (auto i = 0; i < m; i++)
    /* for each col in A or for each row in B */
    for (auto j = 0; j < n; j++)
    {
      /* will not contribute to R[i][0..n-1] */
      if (A[i][j] == 0)
        continue;
      /* A[i][j] will contribute to R[i][col]
         where B[j][col] != 0
      */
      for (auto col : nonZero[j])
        result[i][col] += A[i][j] * B[j][col];
    }

  return result;
}