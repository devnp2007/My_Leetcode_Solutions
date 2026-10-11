class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int pivot = -1;


        /*We compare nums[i] with nums[i + 1].

        Therefore, i must be at most n - 2; otherwise, i + 1 would be outside the array.*/

        //step 1: find pivot from right to left
        for(int i = n-2; i>= 0; i--){
            if(nums[i] < nums[i+1]){
                pivot = i;
                break;
            }
        }

        //step 2 : if pivot exits find the smallest number greater than pivot to replace/swap it with 
        if(pivot != -1){
            for(int i = n-1; i >pivot; i--){
                if(nums[i] > nums[pivot]){
                    swap(nums[i],nums[pivot]);
                    break;
                }
            }
        }

        // step 3 : reverse the remaing suffix/ elements after pivot from left to right in reverse as they would already be in descending order and reversing them would make them in ascending essentially solving our problem.

        reverse(nums.begin() + pivot + 1, nums.end());
        
    }
};

/*
The algorithm works because of two connected observations:

Finding the pivot: We scan from right to left until we find nums[i] < nums[i + 1]. The suffix to the right of this pivot is in descending order.
Finding the replacement: We scan that suffix from right to left. The first element greater than the pivot is therefore the smallest element greater than it.

That's why we don't need to sort the suffix to find the replacement.

One subtle point: After swapping the pivot with its replacement, the suffix remains in descending order. Reversing it puts the suffix in ascending order, making the result the immediate next permutation.
*/


/*
2. Why do we initialize pivot = -1?

int pivot = -1;

This indicates that we haven't found a pivot yet.

If the array is completely descending, pivot remains -1, so we skip the swapping step.

3. Why does the reversal work even when no pivot exists?

reverse(nums.begin() + pivot + 1, nums.end());

If pivot == -1, then:

pivot + 1 == 0

Consequently, we reverse the entire array. Otherwise, we reverse only the suffix after the pivot.

Complexity
Time: O(n)
Extra space: O(1)


*/
