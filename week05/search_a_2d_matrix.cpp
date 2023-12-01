// TC: 0(log(m * n))
// MC: 0(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix[0].size();
        int m = matrix.size();

        int L = 0;
        int R = n*m - 1;

        while(L <= R) {
            int M = L + (R - L) / 2;
            int row = M / n;
            int col = M % n;
            if(matrix[row][col] < target) {
                L = M + 1;
            }
            else if(matrix[row][col] > target) {
                R = M - 1;
            }
            else {
                return true;
            }
        }
        return false;
    }
};