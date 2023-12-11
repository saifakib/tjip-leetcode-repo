// TC: O(N) // where N is the number of intervals
// MC: O(N) 
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<pair<int, int>> events;
        for(auto &interval: intervals) {
            events.push_back({interval[0], +1});
            events.push_back({interval[1], -1});
        };
        sort(events.begin(), events.end());
        int max_room = 0;
        int currenct_conferences = 0;
        for(auto &event: events) {
            currenct_conferences = currenct_conferences + event.second;
            max_room = max(max_room, currenct_conferences);
        };

        return max_room;
    }
};