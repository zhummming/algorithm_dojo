#include "common.hpp"

class Solution {
public:
  double findKthLeastInTwoArray(vector<int>& nums1, vector<int>& nums2,
    int l1, int l2, int k) {
    if (k == 1) {
      return nums1[l1] > nums2[l2] ? nums2[l2] : nums1[l1];
    }
    if (l1 >= nums1.size()) {
      return nums2[k];
    }
    if (l2 >= nums2.size()) {
      return nums1[k];
    }

    int n = k / 2;
    int i1 = l1 + n >= nums1.size() ? nums1.size() - 1 : l1 + n - 1;
    int i2 = l2 + n >= nums2.size() ? nums2.size() - 1 : l2 + n - 1;

    // std::cout << i1 << " " << i2 << std::endl;
    // std::cout << nums1[i1] << " " << nums2[i2] << std::endl;
    if (nums1[i1] < nums2[i2]) {
      return findKthLeastInTwoArray(nums1, nums2, l1 + n, l2, k - n);
    } else {
      return findKthLeastInTwoArray(nums1, nums2, l1, l2 + n, k - n);
    }
  }
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    double m1 = findKthLeastInTwoArray(nums1, nums2, 0, 0, (nums1.size() + nums2.size() + 1) / 2);
    double m2 = findKthLeastInTwoArray(nums1, nums2, 0, 0, (nums1.size() + nums2.size() + 2) / 2);
    return (m1 + m2) / 2;
  }
};

int main(int argc, char **argv)
{
  Solution s;
  vector<int> n1{1,2};
  vector<int> n2{3,4};
  cout << s.findMedianSortedArrays(n1, n2) << endl;
}