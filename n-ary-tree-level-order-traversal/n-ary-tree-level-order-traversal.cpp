/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) 
    {
        vector<vector<int>> ans;
        
        if(root == NULL)
        {
            return ans;
        }
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty())
        {
            vector<int> v;            
            int t = q.size();
             
            while(t--)
            {
                Node* p = q.front();
                q.pop();
                
                for(int i=0;i<(p->children).size();i++)
                {
                    q.push(p->children[i]);
                }
                
                v.push_back(p->val);
            }
            
            ans.push_back(v);
            
        }
        
        return ans;
    }
};