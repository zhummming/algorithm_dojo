#include "common.hpp"

// https://leetcode.cn/problems/find-the-kth-largest-integer-in-the-array/
class Solution {
public:
    static bool compareIntegerStrings(const std::string& str1, const std::string& str2) {
      size_t len1 = str1.length();
      size_t len2 = str2.length();

      // Compare the lengths of the strings first
      if (len1 < len2) return 1;
      if (len1 > len2) return 0;

      // If the lengths are equal, compare character by character
      for (size_t i = 0; i < len1; ++i) {
        if (str1[i] < str2[i]) return 1;
        if (str1[i] > str2[i]) return 0;
      }

      // Both strings are equal
      return 1;
    }
    static bool cmp(string &str1,string &str2)
    {
        if(str1.size()==str2.size())
          return str1.compare(str2)>0;
        return str1.size()>str2.size();
    } 
    string quickSelect(vector<string>& nums, int low, int high, int k) {
      // std::cout << "QuickSelect: " << low << " " << high << " " << k << std::endl;
      // divide nums into left and right and return pivot
      string pivot = nums[high];
      int i = low - 1;
      for (int j = low; j < high; ++j) {
        // if nums[j] < pivot
        if (!cmp(nums[j], pivot)) {
          ++i;
          swap(nums[i], nums[j]);
        }
      }
      swap(nums[i + 1], nums[high]);

      // after divide, judge kth and then recurse
      int index = i + 1;
      if (k < high - index + 1) {
        // k is in right side
        return quickSelect(nums, index + 1, high, k);
      } else if (k > high - index + 1) {
        // k is in right side, mind that the new "k" is not simplely (k-index)
        return quickSelect(nums, low, index - 1, k - (high - index + 1));
      } else {
        // find kth and return
        return nums[index];
      }
    }
    
    string sortAndSelect(vector<string> &nums, int k) {
      std::sort(nums.begin(), nums.end(), cmp);
      // return nums[nums.size() - k];
      return nums[k - 1];
    }
    string kthLargestNumber(vector<string>& nums, int k) {
      return quickSelect(nums, 0, nums.size() - 1, k);
      // return sortAndSelect(nums, k);
    }
};

int main() {
  Solution s;
  vector<string> nums{"5","5","5","5","5","5","5","5","5","5","5","5","5","5","5"};
  auto r = s.kthLargestNumber(nums, 563);
  std::cout << "result: " << r << std::endl;
  // std::cout << "result: " << stol("6888794705") << ", max: " << std::numeric_limits<int>::max() << std::endl;
}
