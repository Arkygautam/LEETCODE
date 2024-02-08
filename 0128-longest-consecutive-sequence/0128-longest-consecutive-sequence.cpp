class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        map<int,int> mp;
        vector<int> res;
        
        
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }

        for(auto i:mp){
           res.push_back(i.first);
        }

        int n = res.size();
        if(n == 0){
            return 0;
        }
        if(n == 1){
            return 1;
        }

        int count = 1;
        int maxi = INT_MIN;
        
        int e = res[0];
        for(int i=1;i<res.size();i++){
            if(res[i] == e+1){
                e = res[i];
                count++;
            }
            else{
                count = 1;
                e = res[i];
            }
            maxi = max(maxi,count);
        }

        return maxi;

        
        
        
        
    }
};