class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        vector<int> ans;

        int m = matrix.size();
        int n = matrix[0].size();

        int top = 0;
        int bottom = m - 1;

        int left = 0;
        int right = n - 1;

        while(top <= bottom && left <= right){


            // traverse top row, left to right
            for(int col = left; col <=right; col++){
                ans.push_back(matrix[top][col]);
            }
            top++; 

            // traverse right col, top to bottom
            for(int row = top; row <= bottom; row++){
                ans.push_back(matrix[row][right]);
            }
            right--;

            // traverse bottom row, right to left
            if (top <= bottom){
                for(int col = right; col >=left; col--){
                    ans.push_back(matrix[bottom][col]);
                }
                bottom--;
            }

            //traverse left col, bottom to top
            if (left <= right){
                for(int row = bottom; row >= top; row--){
                    ans.push_back(matrix[row][left]);
                }
                left++;
            }
        }
        return ans;         
        }
};