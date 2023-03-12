#include "common.hpp"

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
      int fast = 0, slow = 0;
      while (fast < nums.size()) {
        if (nums[fast] != 0) {
          nums[slow] = nums[fast];
          ++slow;
        }
        ++fast;
      }
      while (slow < nums.size()) {
        nums[slow] = 0;
        ++slow;
      }
    }
};

int main(int argc, char **argv)
{
  std::vector<int> value{1, 1, 0, 4, 4, 0, 3, 0, 1};
  auto print_vec = [](const vector<int>& v) {
      for (auto i : v) {
        cout << i << " ";
      }
      cout << endl;
    };
  print_vec(value);

  Solution s;
  s.moveZeroes(value);
  print_vec(value);
}