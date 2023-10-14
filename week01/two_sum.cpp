// TC: O(N)
// SC: O(N)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numsIndex;
        
        for(int i=0; i<nums.size(); i++) {
            if(numsIndex.count(nums[i])) {
                return {numsIndex[nums[i]], i};
            }
            numsIndex[target-nums[i]] = i;
        }
        return {-1, -1};
    }
};