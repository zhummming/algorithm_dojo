#include "common.hpp"

class Solution {
public:
    // bool isPalindrome(const string & s) {
    //   int left = 0, right = s.size() - 1;
    //   while (left < right) {
    //     if (s[left] != s[right]) {
    //       return false;
    //     }
    //     left++;
    //     right--;
    //   }
    //   return true;
    // }
    string longestPalindrome(string s) {
      int len = 0;
      string res;
      for (int i = 0; i < s.size(); i++) {
        auto judgeByCenter = [&](const string & s, int left, int right) {
            while (left >= 0 && right <= s.size() - 1) {
              if (s[left] == s[right]) { // isPalindrome(curr_str)
                int curr_len = right - left + 1;
                if (curr_len > len) {
                  len = curr_len;
                  res = s.substr(left, curr_len);
                }
              } else {
                break;
              }
              left--;
              right++;
            }
          };
        // center is i
        judgeByCenter(s, i, i);
        // center is i, i + 1
        if (i + 1 <= s.size() - 1 && s[i] == s[i + 1]) {
          judgeByCenter(s, i, i + 1);
        }
      }
      return res;
    }
};

int main(int argc, char **argv)
{
  Solution s;
  cout << s.longestPalindrome("bbbaacc") << endl;
}