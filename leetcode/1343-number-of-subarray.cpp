#include "common.hpp"

// https://leetcode.cn/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/description/
class Solution {
public:
  // 注意这里的子数组是要连续的，而不是子序列，后者是无序的。
  // 这是没有按照框架写的代码，比较冗余
  int numOfSubarrays1(vector<int>& arr, int k, int threshold) {
    int left = 0, right = 0;
    int res = 0;
    int sum = arr.empty() ? 0 : arr[0];
    while(right < arr.size()) {
      if (right - left + 1 < k) {
        ++right;
        sum += arr[right];
        continue;
      }
      double average = sum / (right - left + 1);
      if (average >= threshold) {
        ++res;
      }
      sum -= arr[left];
      ++left;
      ++right;
      if (right < arr.size()) {
        sum += arr[right];
      }
    }
    return res;
  }
  // 按照框架修改了一下，整体好多了！
  int numOfSubarrays(vector<int>& arr, int k, int threshold) {
    int left = 0, right = 0;
    int res = 0;
    int sum = 0;
    while(right < arr.size()) {
      sum += arr[right];
      if (right - left + 1 >= k) {
        if (sum >= threshold * k) {
          ++res;
        }
        sum -= arr[left];
        ++left;
      }
      ++right;
    }
    return res;
  }
};

int main(int argc, char **argv)
{
  vector<int> arr = {2,2,2,2,5,5,5,8};
  int k = 3, threshold = 4;

  Solution so;
  cout << so.numOfSubarrays(arr, k ,threshold) << endl;
}