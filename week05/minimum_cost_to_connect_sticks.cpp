// TC: 0(nlogn) where n is the size of sticks;
// MC: 0(n)
class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        priority_queue<int, vector<int>, greater<int>> acs_sticks(sticks.begin(), sticks.end());
        int totalCost = 0;
        while(acs_sticks.size() > 1) {
            int x = acs_sticks.top();
            acs_sticks.pop();
            int y = acs_sticks.top();
            acs_sticks.pop();
            totalCost += x + y;
            acs_sticks.push(x + y);
        };
        return totalCost;
    }
};