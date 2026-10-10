class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];

        // find meeting oint in cycle
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while(slow!=fast);

        // find start of cycle
        slow = nums[0];

        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        
        return slow;
    }
};