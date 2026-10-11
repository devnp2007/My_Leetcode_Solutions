class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> seen;

        int left = 0;
        int max_window_length = 0;

        for(int right = 0; right <s.size(); right++){

            //remove characters until the current character is no longer repeated inside the windows
            while( seen.find(s[right]) != seen.end() ){
                seen.erase(s[left]);
                left++;
            }

            //add new current character to the window
            seen.insert(s[right]);

            //calculating current window length
            int current_window_length = right - left + 1;

            //updating maximum window length
            max_window_length = max(current_window_length,max_window_length);           
        }

        return max_window_length;
        
    }
};