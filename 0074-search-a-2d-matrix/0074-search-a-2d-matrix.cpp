class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int s = 0;
        int r = matrix.size();
        int c = matrix[0].size();
        int e = r*c-1;
        int mid = s + (e-s)/2;

        while(s<=e){
            int e1 = mid/c;
            int e2 = mid%c;

            if(matrix[e1][e2]  == target){
                return true;
            }
            else if(matrix[e1][e2] < target){
                s = mid+1;
            }
            else{
                e = mid-1;
            }
            mid = s + (e-s)/2;
        }

        return false;

    }
};