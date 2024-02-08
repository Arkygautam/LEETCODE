class Solution {
public:
    bool isAnagram(string s, string t) {
        
        
        if(s.length() != t.length()){
            return false;
        }
        
        map<char,int> mp;
        
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
        }
        
        for(int i=0;i<t.length();i++){
            if(mp[t[i]] == 0){
                return false;
            }    
            else{
                mp[t[i]]--;    
            }
        }
        
        
        for(auto i:mp){
            if(i.second > 0){
                return false;
            }
        }
        
        
        return true;
    }
};