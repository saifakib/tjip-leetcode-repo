// TC: 0(N^2) // where N is length of an array
// SC: 0(2N)
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> pair_sum;
        for(auto n1: nums1){
            for(auto n2: nums2){
                pair_sum[n1 + n2]++;
            }
        }
        int count = 0;
        for(auto n3: nums3){
            for(auto n4: nums4) {
                if(pair_sum.count(-(n3 + n4))) count += pair_sum[-(n3 + n4)];
            }
        }
        return count;
    }
};