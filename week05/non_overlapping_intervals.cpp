// TC: O(nlogn) // where n is the number of intervals
// MC: O(1)
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
       sort(intervals.begin(), intervals.end(), [](vector<int>&a, vector<int>&b) {
           return a[1] < b[1];
       });

       int non_ovelapping_interval_count = 0;
       int last = INT_MIN / 2;

       for(auto &interval: intervals) {
           if(interval[0] >= last) {
               non_ovelapping_interval_count++;
               last = interval[1];
           }
       };

       return intervals.size() - non_ovelapping_interval_count;
    }
};