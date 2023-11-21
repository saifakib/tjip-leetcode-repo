// TC: 0(NlogN) where n size of intervals
// SC: 0(N)
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>nonOverlapping;
        sort(intervals.begin(), intervals.end());
        nonOverlapping.push_back(intervals[0]);

        for(auto interval: intervals) {
            if(nonOverlapping.back()[1] >= interval[0]) {
                nonOverlapping.back()[1] = max(nonOverlapping.back()[1], interval[1]);
            } else {
                nonOverlapping.push_back(interval);
            }
        }
        return nonOverlapping;
    }
};