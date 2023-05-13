#include "common.hpp"

// https://leetcode.cn/problems/regular-expression-matching/
// 思路： 拆分成2sum问题，用双指针来解决！
class Solution {
public:
  // bool helper(string s, string p, int index_s, int index_p) {
  //   if (index_s > s.size() -1 && index_p > p.size() -1) {
  //     return true;
  //   }

  //   while (s[index_s] == p[index_p] || p[index_p] == '.') {
  //     ++index_s;
  //     ++index_p;
  //   }
  //   if (p[index_p] == '*') {

  //   }
  // }
  
  // s is original string and p is pattern
  // https://leetcode.cn/problems/regular-expression-matching/comments/86480  没太看懂，抄的！！
  bool isMatch(string s, string p) {
      if (p.empty()) return s.empty();
      
      auto first_match = !s.empty() && (s[0] == p[0] || p[0] == '.');
      
      if (p.length() >= 2 && p[1] == '*') {
          // 这里怎么理解呢？
          return isMatch(s, p.substr(2)) || (first_match && isMatch(s.substr(1), p));
      } else {
          return first_match && isMatch(s.substr(1), p.substr(1));
      }
  }
};

int main(int argc, char **argv)
{
  Solution s;
  std::cout << s.isMatch("aaabbb", "a*.*") << std::endl;
}