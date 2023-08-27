#include "common.hpp"

class Solution {
public:
  int searchInsert(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (nums[mid] == target) {
        return mid;
      } else if (nums[mid] > target) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    return left;
  }
};

int main(int argc, char **argv)
{
  vector<int> nums = {1,3,5,6};
  int target = 7;
  Solution s;
  cout << s.searchInsert(nums, target) << endl;
}