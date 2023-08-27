#include "common.hpp"

// https://leetcode.cn/problems/container-with-most-water/?envType=study-plan-v2&envId=top-interview-150
class Solution {
public:
  int maxArea(vector<int>& height) {
    int left = 0, right = height.size() - 1;
    int max = 0;
    while (left < right) {
      int curr = (right - left) * min(height[left], height[right]);
      max = max < curr ? curr : max;
      if (height[left] < height[right]) {
        ++left;
      } else {
        --right;
      }
    }
    return max;
  }
};

int main(int argc, char **argv)
{
  vector<int> height = {1,1};

  Solution so;
  cout << so.maxArea(height) << endl;
}