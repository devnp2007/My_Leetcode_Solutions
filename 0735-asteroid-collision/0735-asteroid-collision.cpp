class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int asteroid : asteroids) {
            bool alive = true;

            while (!st.empty() &&
                   st.top() > 0 &&
                   asteroid < 0) {

                if (st.top() < -asteroid) {
                    // Stack asteroid is smaller and explodes.
                    st.pop();
                }
                else if (st.top() == -asteroid) {
                    // Both asteroids explode.
                    st.pop();
                    alive = false;
                    break;
                }
                else {
                    // Incoming asteroid is smaller and explodes.
                    alive = false;
                    break;
                }
            }

            if (alive) {
                st.push(asteroid);
            }
        }

        vector<int> result;

        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }

        reverse(result.begin(), result.end());

        return result;
    }
};

/*
An incoming asteroid may destroy multiple asteroids, so we use while, not just if.
*/