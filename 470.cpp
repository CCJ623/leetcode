// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

int rand7();

class Solution {
public:
  int rand10() {
    while (true) {
      auto index = (rand7() - 1) * 7 + rand7();
      if (index <= 40) {
        return index % 10 + 1;
      }
    }
  }
};