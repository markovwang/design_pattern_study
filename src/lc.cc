#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>

class Solution {
  
public:
  int search(std::vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size()-1;
    while(left< right) {
      int mid = (left+right)>>1;
      // 何时向左归
      // nums.0<nums.mid and nums.0<=target<=nums.mid
      // nums.0>nums.mid and target<=nums.mid
      // nums.0<nums.mid and target>=nums.0
      // 其余情况右归
      if((nums[0]>target) or (nums[0]>nums[mid]) or (target>nums[mid])) {
        left = mid+1; }    
      else right = mid;
    }
    return left == right and nums[left] == target ?left:-1;
  }
};

int main() {
  std::vector ivec{4,5,6,7,0,1,2};
  std::cout<<Solution{}.search(ivec,0);
}