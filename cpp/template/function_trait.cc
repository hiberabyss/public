/**
 * Author: Hongbo Liu <lhbf@qq.com>
 * Date  : 2023-09-12 22:03:24
 */

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

template<typename T> struct function_traits;

template<typename ClassType, typename R, typename...Args>
struct function_traits<R(ClassType::*)(Args...)> {

  static const size_t nargs = sizeof...(Args);
  using args_tuple = std::tuple<Args...>;
  using result_type = R;
  template <size_t i> struct arg {
    typedef typename std::tuple_element<i, args_tuple>::type type;
  };
};

class Solution {
public:
  Solution() {}
  virtual ~Solution() {}
  void fun(int x) {}
  void fun(string x) {}
};

// template<typename T>
// void CallFun(T t) {
//   decltype(function_traits<decltype(&Solution::fun)>)
// }

int main(int argc, char *argv[]) {
  return 0;
}
