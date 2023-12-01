// TC: O(N^2)
// SC: O(N)

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());  // Intro Sort: O(NLogN)
        vector<vector<int>> triplets;
        
        for(int i = 0; i < nums.size(); i++) {
            int a = nums[i];
            // Find b and c from [i+1, n-1] range
            // b + c = -a
            int L = i + 1;
            int R = nums.size() - 1;
            int target = -a;

            while(L < R) {
                if(nums[L] + nums[R] > target) R--;
                else if(nums[L] + nums[R] < target) L++;
                else {
                    int b = nums[L];
                    int c = nums[R];
                    while(L + 1 < R && nums[L + 1] == b) L++;
                    while(R - 1 > L && nums[R - 1] == c) R--;
                    triplets.push_back({ a, b, c });
                    R--;
                    L++;
                }
            }
            while(i + 1 < nums.size() && nums[i] == nums[i + 1]) i++;
        }
        return triplets;
    }
};