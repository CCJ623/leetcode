#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // <num, index>
        unordered_map<int, size_t> hash_table;
        for (size_t i =0; i < nums.size(); ++i){
            auto num = nums[i];
            auto iter = hash_table.find(target-num);
            if (iter != hash_table.cend()){
                return {static_cast<int>(iter->second), static_cast<int>(i)};
            }
            hash_table[num] = i;
        }
        return {};
    }
};