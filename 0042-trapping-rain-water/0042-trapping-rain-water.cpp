class Solution {
public:
    int trap(vector<int>& height) {

        vector<int> ll;
        vector<int> rr;
        int l = 0 ;
        int r = 0;
        for(int i=0;i<height.size();i++){
            if(height[i] >= l){
                l = height[i];
            }

            ll.push_back(l);
        }

        for(int i=height.size()-1;i>=0;i--){
            if(height[i] >= r){
                r = height[i];
            }
            rr.push_back(r);
        }

        reverse(rr.begin(),rr.end());
        int ans = 0;
        for(int i=0;i<height.size();i++){
            ans+=min(ll[i],rr[i])-height[i];
        }

        return ans;
        
    }
};