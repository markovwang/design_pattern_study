#include <algorithm>
#include <array>
#include <iostream>
#include <type_traits>
#include <vector>

template <typename T> struct is_container : public std::false_type {};

template <typename T, typename Alloc>
struct is_container<std::vector<T, Alloc>> : std::true_type {};

template <typename T, std::size_t Sz>
struct is_container<std::array<T, Sz>> : std::true_type {};

// 左右皆闭区间, // right +1 = left
// l =0 r=size-1
// termi:left>right
// search l: right = mid -1
// search r: left = mid +1
// 仅需mid就能判断左右区间
template <typename T, typename = is_container<T>>
std::size_t bin_search_1(const T &vec, typename T::value_type target) {
  std::size_t left = 0;
  std::size_t right = vec.size() - 1;
  while (left <= right) {
    std::size_t mid = (left + right) >> 1;
    if (vec[mid] == target)
      return mid;
    else if (vec[mid] < target)
      left = mid + 1;
    else
      right = mid - 1;
  }
  return -1;
}

int main() {}