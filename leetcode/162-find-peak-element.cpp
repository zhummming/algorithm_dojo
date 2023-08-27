#include "common.hpp"

class Solution {
public:
  int findPeakElement(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    int mid = left + (right - left) / 2;
    while (left <= right) {
      mid = left + (right - left) / 2;
      int pre_mid = mid - 1 >= 0 ? nums[mid-1] : -1 * INT_MAX;
      int post_mid = mid + 1 <= nums.size() - 1 ? nums[mid+1] : -1 * INT_MAX;
      if (nums[mid] > pre_mid && nums[mid] > post_mid) {
        return mid;
      }
      if (nums[mid] <= post_mid) {
        left = mid + 1;
      } else if (nums[mid] <= pre_mid) {
        right = mid - 1;
      } else {
        // TODO: each side is ok
        left = mid + 1;
      }
    }
    return mid;
  }
};

int main(int argc, char **argv)
{
  vector<int> nums = {1,2,1,3,5,6,4};
  Solution s;
  cout << s.findPeakElement(nums) << endl;
}