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
    unordered_map<int,vector<TreeNode*>>dp;
    vector<TreeNode*> allPossibleFBT(int n) {
       if(n%2 == 0)return {};
       if(n == 1)return {new TreeNode(0)};
       if(dp.count(n))return dp[n];
       vector<TreeNode*>ans;
        for(int i = 1; i < n; i+=2){
            int leftNodes = i;
            int rightNodes = n-1-i;

            vector<TreeNode*> leftTrees = allPossibleFBT(leftNodes);
            vector<TreeNode*> rightTrees = allPossibleFBT(rightNodes);

            for(auto left : leftTrees){
                for(auto right : rightTrees){
                    TreeNode* root = new TreeNode(0);

                    root->left = left;
                    root->right = right;

                    ans.push_back(root);
                }
            }
        }
        return dp[n] = ans;
    }
};