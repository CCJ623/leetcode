#include <charconv>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
  string decodeString(string s) {
    stack<string> level_string;
    level_string.emplace();
    stack<size_t> string_count;
    string_count.emplace(1);

    for (auto ptr = s.c_str(), end_ptr = s.c_str() + s.size(); ptr < end_ptr;) {
      auto ch = *ptr;
      if (isDigit(ch)) {
        size_t count;
        ptr = from_chars(ptr, end_ptr, count).ptr + 1;
        level_string.emplace();
        string_count.push(count);
        continue;
      }

      if (ch == ']') {
        auto str = std::move(level_string.top());
        level_string.pop();
        auto count = string_count.top();
        string_count.pop();

        level_string.top().reserve(level_string.top().size() +
                                   (str.size() * count));
        for (size_t i = 0; i < count; ++i) {
          level_string.top().append(str);
        }
      } else {
        level_string.top().push_back(ch);
      }

      ++ptr;
    }

    return level_string.top();
  }

private:
  auto isDigit(char ch) -> bool { return '0' <= ch && ch <= '9'; }
};