class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        queue<pair<int,int>>Q;
        int n = rooms.size();
        int m = rooms[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(rooms[i][j] == 0){
                    Q.push({i,j});
                }
            }
        static vector<int>dir = {1,0,-1,0,1};
        while(!Q.empty()){
            auto u = Q.front(); Q.pop();
            for(int i = 0; i < 4; i++){
                int vr = u.first + dir[i];
                int vc = u.second + dir[i+1];
                if( vr < 0 || vc < 0 || vr >= n || vc >= m || rooms[vr][vc] == -1 ) continue;
                if( rooms[vr][vc] > rooms[u.first][u.second] + 1 ){
                    rooms[vr][vc] = rooms[u.first][u.second] + 1;
                    Q.push({vr, vc});
                }
            }
        }

    }
};