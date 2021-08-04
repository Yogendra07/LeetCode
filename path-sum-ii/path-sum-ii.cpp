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
class Solution 
{
public:
    vector<vector<int>> ans;
    
    void path(TreeNode *root,vector<int> &v,int targetSum)
    {
        if(root == NULL)
        {
            return;
        }
        
        v.push_back(root->val);
        
        if(root->left == NULL and root->right == NULL and targetSum-(root->val) == 0)
        {
            ans.push_back(v);
        }
    
        
        path(root->left,v,targetSum - (root->val));
        path(root->right,v,targetSum - (root->val));
        
        v.pop_back();
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) 
    {
        vector<int> v;
        path(root,v,targetSum);
        
        return ans;
    }
};