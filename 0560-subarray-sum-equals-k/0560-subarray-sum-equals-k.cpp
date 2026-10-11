class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefix_count;

        //an empty prefix has sum 0 and occurs once
        prefix_count[0] = 1;

        int prefix_sum = 0;
        int count = 0;

        for(int i =0; i < nums.size(); i++){

            //step 1: calculate the current prefix sum
            prefix_sum += nums[i];

            //step 2: find the previous sum we needed
            int needed = prefix_sum - k;

            //step 3: count subarrays ending at this postion.
            if(prefix_count.find(needed) != prefix_count.end()){
                count += prefix_count[needed];
            }

            //step 4:
            prefix_count[prefix_sum]++;
        }

        return count;
        
    }
};

//A sliding window based on expanding or shrinking according to the sum is not generally reliable when negative numbers are present. Prefix sums and a hash map handle them correctly.