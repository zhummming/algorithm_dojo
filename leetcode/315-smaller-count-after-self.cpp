#include "common.hpp"

// https://leetcode.cn/problems/count-of-smaller-numbers-after-self/
// 未通过，不看了
class Solution {
public:
    int * temp;
    int * count;
    std::map<int, int> index_map;
    vector<int> countSmaller(vector<int>& nums) {
      temp = new int[nums.size()];
      count = new int[nums.size()];
      for (int i = 0; i < nums.size(); ++i) {
        index_map.insert({nums[i], i});
        count[i] = 0; // 记得要初始化！
      }
      sort(nums, 0, nums.size() - 1);
      std::vector<int> res(count, count + nums.size());
      delete []temp;
      delete []count;
      return res;
    }
    
    void sort(vector<int>& nums, int left, int right) {
      if (left == right) {
        return;
      }

      int mid = (left + right) / 2;
      // 这样写是为了防止溢出，效果等同于 (hi + lo) / 2
      // int mid = lo + (hi - lo) / 2;
      sort(nums, left, mid);
      sort(nums, mid + 1, right);
      merge(nums, left, mid, right);
    }

    void merge(vector<int>& nums, int left, int mid, int right) {
      for (int i = left; i <= right; ++i) {
        temp[i] = nums[i];
      }
      int i = left, j = mid + 1;
      for (int k = left; k <= right; ++k) {
        if (i == mid + 1) {
          nums[k] = temp[j++];
        } else if (j == right + 1) {
          nums[k] = temp[i++];
          // 这个判断解决-1,-1这个用例
          if (nums[k] != temp[right]) {
            count[index_map[nums[k]]] += j - (mid + 1);
          }
        } else if (temp[i] < temp[j]) {
          nums[k] = temp[i++];
          if (nums[k] != temp[j]) {
            count[index_map[nums[k]]] += j - (mid + 1);
          }
        } else {
          nums[k] = temp[j++];
        }
      }
    }
};

int main(int argc, char **argv)
{
  std::vector<int> nums{26,78,27,100,33,67,90,23,66,5,38,7,35,23,52,22,83,51,98,69,81,32,78,28,94,13,2,97,3,76,99,51,9,21,84,66,65,36,100,41};
  // 看看排序结果对不对呢？
  for (auto n : nums) {
    std::cout << n << " ";
  }
  std::cout << std::endl;
  Solution s;
  auto res = s.countSmaller(nums);
  for (auto n : res) {
    std::cout << n << " ";
  }
  std::cout << std::endl;
}