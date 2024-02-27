class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = INT_MIN;

        for (int i = 0; i < piles.size(); i++) {
            if (piles[i] > maxi) {
                maxi = piles[i];
            }
        }

        int s = 1;
        int e = maxi;
        
        while (s <= e) {
            int mid = s + (e - s) / 2;
            long long int ans = 0;

            for (int i = 0; i < piles.size(); i++) {
                ans += ceil(static_cast<double>(piles[i]) / static_cast<double>(mid));
            }

            if (ans <= h) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }

        return s;
    }
};
