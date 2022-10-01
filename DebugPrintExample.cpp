#include "DebugPrint.hpp"
#include <map>
#include <vector>

int main() {
  std::cout << std::vector<int>({1, 2, 3});

  std::map<char, int> foo;
  foo['a'] = 65;
  foo['b'] = 66;
  std::cout << foo;

  std::tuple<int, char, float> bar = {3, 'a', 3.14};
  std::cout << bar << "The end.";

  // Output: [1, 2, 3]{a: 65, b: 66}(3, a, 3.14)The end.
}
