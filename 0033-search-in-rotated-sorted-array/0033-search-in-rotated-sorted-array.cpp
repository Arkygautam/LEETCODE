class Solution {
public:

    int findMin(vector<int>& nums) {
        int s = 0;
        int e = nums.size()-1;
        int mid = s + (e-s)/2;

        while(s<e){
            if(nums[mid] < nums[e]){
                e = mid;
            }   
            else{
                s = mid+1;
            }

            mid = s +(e-s)/2;
        }

        return e;
    }

    int binsearch(int s, int e, vector<int>& nums, int target) {
        int mid = s + (e - s) / 2;

        while (s <= e) {
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }

            mid = s + (e - s) / 2;
        }

        return -1;
    }

    int search(vector<int>& nums, int target) {
        int pivot = findMin(nums);
        int t = binsearch(0, pivot - 1, nums, target);
        int s = binsearch(pivot, nums.size() - 1, nums, target);

        if (t >= 0) {
            return t; 
        }

        if (s >= 0) {
            return s;
        }

        return -1;
    }
};
