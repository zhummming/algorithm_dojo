#include "common.hpp"

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int left = 0, right = 0;
    bool hash[128] = {0};
    string sub;
    int maxl = 0;
    while (right < s.length()) {
      // if repeated
      if (!hash[s[right]]) {
        hash[s[right]] = 1;
        if (right - left + 1 > maxl) {
          maxl = right - left + 1;
          sub = s.substr(left, right - left + 1);
        }
        right++;
        continue;
      }
      hash[s[left]] = 0;
      left++;
    }
    // cout << sub << endl;
    return maxl;
  }
};

int main(int argc, char **argv)
{
  Solution s;
  cout << s.lengthOfLongestSubstring("pwwkew") << endl;
}