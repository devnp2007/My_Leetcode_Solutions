/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;

        if(root == nullptr)
        return result;

        queue<TreeNode*> q;
        q.push(root);

        // here queue is used to as push from back and pop from front, so each level by level

        bool left_to_right = true;

        while(!q.empty()){
            int size = q.size();

            vector <int> level(size);

            for(int i = 0; i < size; i++){
                TreeNode* node = q.front();
                q.pop();

                int index;

                if(left_to_right)
                    index = i;
                else
                    index = size - 1 -i;

            level[index] = node->val;

            if(node->left != nullptr)
                q.push(node->left);

            if(node->right != nullptr)
                q.push(node->right);

            }

        result.push_back(level);

        left_to_right =! left_to_right; // not !=
        }

        return result;
        
    }
};




/*
          3
         / \
        9   20
           /  \
          15   7

excepted output : [[3], [20,9], [15,7]]

Given a binary tree, return its level-order traversal, but alternate the direction at every level.

find how many nodes are currently in the queue
process exactly those nodes
store their values in the current direction
add their children to the queue
reverse the direction for the next level

when moving left to right : 0 1 2
but when moving right to left : 2 1 0 , so index = size - 1 -i

and then after each level : 
switch the direction : leftToRight =! leftToRight
this will switch the direction

true become false , and false become true

TC : O(n)
SC : O(n)



*/