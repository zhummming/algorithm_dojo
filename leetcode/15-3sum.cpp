#include "common.hpp"

// https://leetcode.cn/problems/3sum/submissions/   a+b+c=0
// 思路： 拆分成2sum问题，用双指针来解决！
class Solution {
public:
  set<std::pair<int, int> > twoSum(vector<int> & nums, int index) {
    // 此处使用set，是为了避免重复结果，比如-2 0 0 2 2, 如果不用set，此处会返回两组0 2
    set<std::pair<int, int> > res;
    int left = index + 1;
    int right = nums.size() - 1;
    while (left < right) {
      int curr = nums[left] + nums[right];
      if (curr > -1 * nums[index]) {
        right--;
      } else if (curr < -1 * nums[index]) {
        left++;
      } else {
        res.insert(std::make_pair(nums[left], nums[right]));
        left++;
        right--;
      }
    }
    return res;
  }
  vector<vector<int>> threeSum(vector<int>& nums) {
    // sort array and remove deplicated
    std::sort(nums.begin(), nums.end());
    // 不能直接去重，因为会有比如-1 -1 2这种情况，去重之后变成-1 2
    // std::set<int> s(nums.begin(), nums.end());
    // std::vector<int> sorted_num(s.begin(), s.end());
    // nums.swap(sorted_num);

    vector<vector<int>> res;
    int pre = INT_MAX;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] == pre) {
        continue;
      }
      pre = nums[i];
      auto curr = twoSum(nums, i);
      if (!curr.empty()) {
        for (auto& v : curr) {
          std::vector<int> sum{nums[i], v.first, v.second};
          res.emplace_back(sum);
        }
      }
    }
    return res;
  }
};

int main(int argc, char **argv)
{
  Solution s;
  // std::vector<int> v{1,2,3,4,5,6,7,8,-1,-2,0};
  std::vector<int> v{-2,0,0,2,2};
  // std::vector<int> v{-1,0,1,2,-1,-4};
  auto sum = s.threeSum(v);

  for (auto s : sum) {
    for (auto i : s) {
      std::cout << i << " ";
    }
    std::cout << std::endl;
  }
}