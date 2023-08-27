#include "common.hpp"

// https://leetcode.cn/problems/is-subsequence/description/?envType=study-plan-v2&envId=top-interview-150
class Solution {
public:
  // Given two strings s and t, return true if s is a subsequence of t, or false otherwise.
  bool isSubsequence(string s, string t) {
    int j = 0;
    for(int i = 0; i < t.length() && j < s.length(); ++i) {
      if (s[j] != t[i]) {
        // j = 0;
        continue;
      } else {
        ++j;
      }
    }
    return j == s.length();
  }
};

int main(int argc, char **argv)
{
  string s = "axc", t = "ahbgdc";

  Solution so;
  cout << so.isSubsequence(s, t) << endl;
}