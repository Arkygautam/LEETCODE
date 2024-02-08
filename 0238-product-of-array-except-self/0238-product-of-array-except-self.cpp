class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        int l = 1;
        int r = 1;
        for(int i = 0;i<nums.size();i++){
            ans.push_back(1);
        }

        for(int i = 0;i<nums.size();i++){
            ans[i] = ans[i]*l;
            l=l*nums[i];
        }
        for(int i = nums.size()-1;i>=0;i--){
            ans[i] = ans[i]*r;
            r=r*nums[i];
        }

        return ans;
    }
};