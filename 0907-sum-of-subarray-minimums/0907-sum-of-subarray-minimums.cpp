class Solution {
public:
int sumSubarrayMins(vector<int>& arr) {
int n = arr.size();
const int MOD = 1000000007;

 
    vector<int> left(n), right(n);
    stack<int> st;

    // Find previous strictly smaller element
    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] >= arr[i]) {  //hre index hence arr[st.top()] not direct st.top()
            st.pop();
        }

        left[i] = st.empty() ? -1 : st.top();
        st.push(i); //pushing index
    }

    // Clear the stack
    while (!st.empty()) {
        st.pop();
    }

    // Find next smaller-or-equal element
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && arr[st.top()] > arr[i]) {
            st.pop();
        }

        right[i] = st.empty() ? n : st.top();
        st.push(i);
    }

    // Calculate contributions
    long long ans = 0;

    for (int i = 0; i < n; i++) {
        long long leftCount = i - left[i];
        long long rightCount = right[i] - i;

        long long contribution =
            (leftCount * rightCount) % MOD;

        contribution = (contribution * arr[i]) % MOD;
        ans = (ans + contribution) % MOD;
    }

    return ans;
}
 

};


// very tough question need to review again

/*

arr   = [3, 1, 2, 4]
left  = [-1, -1, 1, 2] , in first oround stack empty so -1, ,left calculated 3>1 pop 3, and left[1] = -1 meaning on right side no smaller element exists, and push into stack , and so on , here we find strictly smaller noo hence >= 
right = [1, 4, 4, 4]

*/