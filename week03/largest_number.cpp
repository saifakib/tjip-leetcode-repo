class Solution {
private:
    static bool comparator(int &a, int &b) {
        string sa = to_string(a);
        string sb = to_string(b);
        string sab = sa + sb;
        string sba = sb + sa;
        return sab > sba;
    }
public:
    // TC: 0(nwlogn) 
    // SC: 0(n)
    string largestNumber(vector<int>& nums) {
        // 0(nwlogn) // n = length of nums && w = avg length of string from nums;
        sort(nums.begin(), nums.end(), comparator);

        // after softing if large value is 0
        if(nums.size() > 0 && nums[0] == 0) return to_string(0);
        string largest = "";
        // 0(n)
        for(auto &num: nums) {
            largest += to_string(num);
        }
        return largest;
    }
};

