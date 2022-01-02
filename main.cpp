#include <cassert>
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
 public:
  int singleNumber(vector<int> &nums) {
    unordered_set<int> occur;
    for (const auto& i: nums) {
      if (not occur.count(i)) {
        occur.insert(i);
      } else {
        occur.erase(i);
      }
    }

    return *occur.begin();
  }
};

void TestSingleNimber() {
  Solution s;
  {
    vector<int> nums{2, 2, 1};
    assert(1 == s.singleNumber(nums));
  }
  {
    vector<int> nums{4, 1, 2, 1, 2};
    assert(4 == s.singleNumber(nums));
  }
  {
    vector<int> nums{1};
    assert(1 == s.singleNumber(nums));
  }
}

int main() {
  TestSingleNimber();
  std::cout << "Ok!" << std::endl;
  return 0;
}
