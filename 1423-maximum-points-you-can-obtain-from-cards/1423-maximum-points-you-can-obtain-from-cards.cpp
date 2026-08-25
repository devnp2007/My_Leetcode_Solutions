class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) 
    {
        int n = cardPoints.size();
        int sum = 0;
        int sum2 = 0;

        for(int i = 0; i < n; i++){
            sum += cardPoints[i];
        }

        // Edge case: if k == n, we take all cards
        if (k == n) return sum;

        int j;
        for(j = 0; j < n - k; j++){
            sum2 += cardPoints[j];
        }
        
        int p = 0;
        
        // 1. Initialize max_sum with the FIRST window
        int max_sum = sum - sum2; 
        
        while(j < n){
            // 2. Slide the window FIRST
            sum2 += cardPoints[j] - cardPoints[p]; 
            
            // 3. THEN check the new window against max_sum
            max_sum = max(max_sum, sum - sum2); 
            
            j++;
            p++;
        }
        
        return max_sum;
    }
};