#include "common.hpp"

class Solution {
public:
  bool isIsomorphic(string s, string t) {
    if (s.size() != t.size())
      return false;
    char map[256] = {0};
    for(int i = 0; i < s.size(); i++) {
      int index = s[i];
      // 如果是bar映射到foo，那么就一直进入第一个判断，也会认为是对的。
      if (0 == map[index]) {
        // check if two index point to same char
        for (int j = 0; j < 256; j++) {
          if (map[j] == t[i]) {
            return false;
          }
        }
        map[index] = t[i];
        // cout << "1: " << map[index] << endl;
      } else {
        // cout << "2: " << map[index] << endl;
        // check if same index point to diff char
        if (map[index] != t[i]) {
          return false;
        }
      }
    }
    return true;
  }
};

int main(int argc, char **argv)
{
  string s = "egg", t = "ada";
  Solution s1;
  cout << s1.isIsomorphic(s, t) << endl;
}