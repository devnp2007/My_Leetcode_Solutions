class Solution {
private:
    // Finds the largest rectangle area in a histogram.
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        // Stores indices of histogram bars.
        stack<int> st;

        int maxArea = 0;

        // Process every bar, plus one imaginary bar of height 0
        // at the end to ensure all remaining bars are processed.
        for (int i = 0; i <= n; i++) {

            // The imaginary final bar has height 0.
            int currentHeight = (i == n) ? 0 : heights[i];

            // A shorter bar means taller bars cannot extend further.
            while (!st.empty() && heights[st.top()] > currentHeight) {

                // Get the height of the bar we are removing.
                int height = heights[st.top()];
                st.pop();

                // Find the left boundary.
                int leftBoundary = st.empty() ? -1 : st.top();

                // Calculate the width of the rectangle.
                int width = i - leftBoundary - 1;

                // Calculate the rectangle area.
                int area = height * width;

                // Update the largest area found so far.
                maxArea = max(maxArea, area);
            }

            // Push only real indices, not the imaginary final bar.
            if (i < n) {
                st.push(i);
            }
        }

        return maxArea;
    }

public:
    int maximalRectangle(vector<vector<char>>& matrix) {

        // Handle an empty matrix.
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }

        int rows = matrix.size();
        int cols = matrix[0].size();

        // heights[j] represents consecutive ones vertically
        // in column j, ending at the current row.
        vector<int> heights(cols, 0);

        int maxArea = 0;

        // Process the matrix one row at a time.
        for (int i = 0; i < rows; i++) {

            for (int j = 0; j < cols; j++) {

                if (matrix[i][j] == '1') {
                    heights[j]++;
                } else {
                    heights[j] = 0;
                }
            }

            // Solve the histogram problem for this row.
            maxArea = max(maxArea, largestRectangleArea(heights));
        }

        return maxArea;
    }
};