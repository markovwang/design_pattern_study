#include <algorithm>
#include <iostream>
#include <vector>
class Solution {
public:
  std::vector<int> searchRange(std::vector<int> &nums, int target) {
    [[unlikely]] if (nums.size() == 0) return {-1, -1};
    else {
      auto low = std::lower_bound(nums.cbegin(), nums.cend(), target);
      auto upper = std::upper_bound(nums.cbegin(), nums.cend(), target);
      if (low == upper)
        return {-1, -1};
      else {
        int dist_l = std::distance(nums.cbegin(), low);
        int dist_r = std::distance(nums.cbegin(), upper);
        return {dist_l, dist_r};
      }
    }
  }
};

template <typename T>
std::ostream &operator<<(std::ostream &os, std::vector<T> ivec) {
  for (auto &&item : ivec) {
    os << item << '\t';
  }
  return os;
}

int main() {
  std::vector<int> ivec{5, 7, 7, 8, 8, 10};
  std::cout << Solution{}.searchRange(ivec, 8);
}