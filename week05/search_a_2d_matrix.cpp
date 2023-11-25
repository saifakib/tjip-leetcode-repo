// TC: 0(log(m * n))
// MC: 0(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int L =  0;
        int R = matrix.size() - 1;

        while(L <= R) {
            int M = L + (R - L) / 2;
            if(matrix[M].front() <= target && matrix[M].back() >= target) {
                int LI = 0;
                int RI = matrix[M].size();
                while(LI <= RI) {
                    int MI = LI + (RI - LI) / 2;
                    if(matrix[M][MI] == target) return true;
                    if(matrix[M][MI] > target) {
                        RI = MI - 1;
                    } 
                    else {
                        LI = MI + 1;
                    }
                }
                return false;
            } 
            if(matrix[M].front() > target) {
                R = M - 1;
            } 
            else {
                L = M + 1;
            }
        };

        return false;
    }
};