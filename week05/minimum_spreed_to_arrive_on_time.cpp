// TC: O(NlogINT_MAX) // where N is the size of dist
// MC: O(1)
class Solution {
private: 
    bool isPossible(vector<int>& dist, double hour, int currSpreed) {
        double elapsed_time = 0.0;
        for(int i = 0; i < dist.size(); i++){
            if(i != dist.size() - 1) {
                elapsed_time += (dist[i] + currSpreed - 1) / currSpreed;
            }
            else { 
                // in fornt of office
                elapsed_time += 1.00 * dist[i] / currSpreed;
            }
        };
        return elapsed_time <= hour;
    }
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int L = 1, R = INT_MAX / 2;
        while(L < R) {
            int M = L + (R - L) / 2;
            if(!isPossible(dist, hour, M)) L = M + 1;
            else R = M;
        }
        return L == INT_MAX / 2 ? -1 : L;
    }
};