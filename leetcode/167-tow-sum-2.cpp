#include "common.hpp"

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
      int left = 0, right = numbers.size() - 1;
      while (left < right) {
        if (numbers[left] + numbers[right] == target) {
          return vector<int>{left+1, right+1};
        } else if (numbers[left] + numbers[right] > target) {
          right--;
        } else {
          left++;
        }
      }
      return vector<int>{};
    }
};

int main(int argc, char **argv)
{
  std::vector<int> value{2,3,4};
  int target = 6;
  
  Solution s;
  PrintVector(s.twoSum(value, target));
}