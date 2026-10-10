class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans(n);

        int positive_index = 0; // even indices 0,2,4
        int negative_index = 1; // odd indices 1,3,5

        for(int i = 0; i < n; i++){
            if(nums[i] > 0){
                ans[positive_index] = nums[i];
                positive_index += 2;
            }

            else if (nums[i] < 0){
                ans[negative_index] = nums[i];
                negative_index += 2;
            }
        }

        return ans;
    }
};