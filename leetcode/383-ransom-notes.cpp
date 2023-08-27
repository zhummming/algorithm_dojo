#include "common.hpp"

class Solution {
public:
  // TODO: 改成通过int [26]存储，时间和空间复杂度都能有所优化
  bool canConstruct(string ransomNote, string magazine) {
    std::unordered_map<char, int> notecount, magazinecount;
    for (auto c : ransomNote) {
      notecount[c]++;
    }
    for (auto c : magazine) {
      magazinecount[c]++;
    }
    for(auto note : notecount) {
      if (note.second > magazinecount[note.first]) {
        return false;
      }
    }
    return true;
  }
};

int main(int argc, char **argv)
{
  string ransomNote = "aa", magazine = "aab";
  Solution s;
  cout << s.canConstruct(ransomNote, magazine) << endl;
}