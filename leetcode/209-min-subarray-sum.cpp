#include "common.hpp"

class Solution {
public:
  int minSubArrayLen(int target, vector<int>& nums) {
    int left = 0, right = 0;
    int minlength = INT_MAX;
    int sum = 0;
    bool add = true;
    while (right < nums.size()) {
      // cout << sum << " " << right << " " << left << " " << nums[right] << " " << nums[left] << endl;
      sum += nums[right];  //  不能每次都加
      while (sum >= target) {
        int len = right - left + 1;
        minlength = minlength < len ? minlength : len;
        sum -= nums[left];
        left++;
        // right++;
      }
      right++;
    }
    return minlength == INT_MAX ? 0 : minlength;
  }
};

int main(int argc, char **argv)
{
  int target = 11;
  vector<int> nums = {1,2,3,4,5};
  Solution s;
  cout << s.minSubArrayLen(target, nums) << endl;
}