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
    TreeNode *insert(vector<int> &nums,int low,int high)
    {
        if(low > high)
        {
            return NULL;
        }
        
        int mid = (low + high)/2;
        
        TreeNode *key = new TreeNode(nums[mid]);
        key->left = insert(nums,low,mid-1);
        key->right = insert(nums,mid+1,high);
        
        return key;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums)
    {
        if(nums.size() == 0)
        {
            return NULL;
        }    
        
        
        if(nums.size() == 1)
        {
            return new TreeNode (nums[0]);
        }
        
        
        int low = 0;
        int high = nums.size()-1;
        
        TreeNode *root = insert(nums,low,high);
        return root;
        
    }
};