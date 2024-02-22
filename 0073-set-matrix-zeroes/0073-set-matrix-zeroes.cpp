class Solution {
public:

    void transform(int r, int c,vector<vector<int>>& matrix){
        //left 
        for(int i=c;i>=0;i--){
            matrix[r][i] = 0;
        }

        //right
        for(int i=c;i<matrix[0].size();i++){
            matrix[r][i] = 0;
        }

        //up
        for(int i=r;i>=0;i--){
            matrix[i][c] = 0;
        }

        //down
        for(int i=r;i<matrix.size();i++){
            matrix[i][c] = 0;
        }

    }



    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int>> v;

        for(int i=0;i<matrix.size();i++){
            for(int j= 0;j<matrix[i].size();j++){
                if(matrix[i][j] == 0){
                    v.push_back({i,j});
                }
            }
        }

        for(int i=0;i<v.size();i++){
            transform(v[i].first,v[i].second,matrix);
        }  
    }
};