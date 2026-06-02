#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<long>> prerequests;
vector<long> compile_times;
vector<bool> compiled;
long min_compile_time = -1;

size_t convertIndex(long index) { return index - 1; }

vector<pair<long, long>> findAllCombinations(const vector<long> &targets) {
  if (targets.empty()) {
    return {};
  }
  if (targets.size() < 2) {
    if (compiled[targets.front()]) {
      return {};
    }
    return {{targets.front(), -1}};
  }

  vector<pair<long, long>> result;
  bool found_first = false;
  for (size_t first = 0; first < targets.size() - 1; ++first) {
    auto target1 = targets[first];
    if (compiled[target1]) {
      continue;
    }
    found_first = true;
    bool found_second = false;
    for (size_t second = first + 1; second < targets.size(); ++second) {
      auto target2 = targets[second];
      if (compiled[target2]) {
        continue;
      }
      result.emplace_back(target1, target2);
      found_second = true;
    }
    if (!found_second) {
      result.emplace_back(target1, -1);
    }
  }
  if (!found_first && !compiled[targets.back()]) {
    result.emplace_back(targets.back(), -1);
  }
  return result;
}

vector<long> findAllCanCompileTarget(const vector<vector<long>> &prerequests) {
  vector<long> result;
  for (size_t i = 0; i < prerequests.size(); ++i) {
    if (prerequests[i].empty()) {
      result.push_back(i);
    }
  }

  return result;
}

void solve(vector<vector<long>> prerequests, long compile_time) {
  // cut
  if (min_compile_time != -1 && compile_time > min_compile_time) {
    return;
  }

  auto targets = findAllCanCompileTarget(prerequests);
  // cout << "targets size: " << targets.size() << "\n";
  if (targets.empty()) {
    // failed
    return;
  }
  auto all_combinations = findAllCombinations(targets);
  // cout << "all_combinations size: " << all_combinations.size() << "\n";

  if (all_combinations.empty()) {
    if (min_compile_time == -1) {
      min_compile_time = compile_time;
    } else {
      min_compile_time = min(min_compile_time, compile_time);
    }
    return;
  }

  for (const auto &combination : all_combinations) {
    auto copy_prerequests = prerequests;
    auto target1 = combination.first;
    auto target2 = combination.second;
    // cout << "combination: " << target1 << " " << target2 << "\n";
    long curr_compile_time;
    if (target1 != -1) {
      curr_compile_time = compile_times[target1];
      for (auto &item : copy_prerequests) {
        auto iter = find(item.begin(), item.end(), target1);
        if (iter != item.end()) {
          item.erase(iter);
        }
      }
      compiled[target1] = true;
    }
    if (target2 != -1) {
      curr_compile_time = max(curr_compile_time, compile_times[target2]);
      for (auto &item : copy_prerequests) {
        auto iter = find(item.begin(), item.end(), target2);
        if (iter != item.end()) {
          item.erase(iter);
        }
      }
      compiled[target2] = true;
    }

    solve(std::move(copy_prerequests), compile_time + curr_compile_time);

    if (target1 != -1) {
      compiled[target1] = false;
    }
    if (target2 != -1) {
      compiled[target2] = false;
    }
  }
}

int main() {
  long N, K;
  cin >> N >> K;
  prerequests.resize(N);
  compiled.resize(N, false);
  compile_times.reserve(N);
  for (long i = 0; i < N; ++i) {
    long num;
    cin >> num;
    compile_times.push_back(num);
  }
  for (long i = 0; i < K; ++i) {
    long curr, prev;
    cin >> curr >> prev;
    prerequests[convertIndex(curr)].push_back(convertIndex(prev));
  }

  solve(prerequests, 0);
  cout << min_compile_time << "\n";
}