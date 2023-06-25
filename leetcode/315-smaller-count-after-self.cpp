#include "common.hpp"

// https://leetcode.cn/problems/count-of-smaller-numbers-after-self/
class Solution {
public:
    int * temp;
    void countSmaller(vector<int>& nums) {
      temp = new int[nums.size()];
      sort(nums, 0, nums.size() - 1);
      delete []temp;
    }
    
    void sort(vector<int>& nums, int left, int right) {
      if (left >= right) {
        return;
      }

      int mid = (left + right) / 2;
      // 这样写是为了防止溢出，效果等同于 (hi + lo) / 2
      // int mid = lo + (hi - lo) / 2;
      sort(nums, left, mid);
      sort(nums, mid + 1, right);
      merge(nums, left, mid, right);
      for (auto n : nums) {
        std::cout << n << " ";
      }
      std::cout << std::endl;
    }

    void merge(vector<int>& nums, int left, int mid, int right) {
      for (int i = 0; i < nums.size(); ++i) {
        temp[i] = nums[i];
      }
      int i = left, j = mid + 1;
      for (int k = 0; k < nums.size(); ++k) {
        if (i == mid + 1) {
          nums[k] = temp[j++];
        } else if (j == right + 1) {
          nums[k] = temp[i++];
        } else if (nums[i] < nums[j]) {
          nums[k] = temp[i++];
        } else {
          nums[k] = temp[j++];
        }
      }
    }
};

int main(int argc, char **argv)
{
  std::vector<int> nums{5, 3, 2, 1, 4, 7, 6, 8};
  for (auto n : nums) {
    std::cout << n << " ";
  }
  std::cout << std::endl;
  Solution s;
  s.countSmaller(nums);
  for (auto n : nums) {
    std::cout << n << " ";
  }
  std::cout << std::endl;
}