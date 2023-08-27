#include "common.hpp"

class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    std::unordered_map<int, int> map;
    for (auto i = 0; i < nums.size(); i++) {
      auto iter = map.find(target - nums[i]);
      if (iter != map.end()) {
        return std::vector<int>{min(i, iter->second), max(i, iter->second)};  // use {}, rather than ()
      }
      map.insert(std::make_pair(nums[i], i));
      // for (auto kv : map) {
      //   cout << kv.first << " " << kv.second << endl;
      // }
    }
    return std::vector<int>();
  }
};

int main(int argc, char **argv)
{
  vector<int> nums = {2,7,11,15};
  int target = 9;
  Solution s;
  auto v = s.twoSum(nums, target);
  for (auto i : v) {
    cout << i << " " << std::endl;
  }
}