class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int l = 0, r = nums.size()-1, ans = 0;
        while(l<r){
            if(nums[r] == 0){
                r--;
            }else if(nums[l] == 0 && nums[r] != 0){
                ans++;
                l++, r--;
            }else l++;
        }
        return ans;
    }
};