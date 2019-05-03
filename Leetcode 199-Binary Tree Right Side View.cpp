/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
/**
beats 41.6% not very fast
**/
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> list;
        std::deque<TreeNode*> treeA,treeB;
        treeA.push_back(root);
        TreeNode* cur;
        if (!root)
        {
            return list;
        }
        while (!treeA.empty() or !treeB.empty()){
            while (!treeA.empty()){
            cur=treeA.front();
            treeA.pop_front();
            if(cur->left) treeB.push_back(cur->left);
            if(cur->right) treeB.push_back(cur->right);
            if (treeA.empty())
            {
                list.push_back(cur->val);
            }
        }
            
            while (!treeB.empty()){
            cur=treeB.front();
            treeB.pop_front();
            if(cur->left) treeA.push_back(cur->left);
            if(cur->right) treeA.push_back(cur->right);  
            if (treeB.empty())
            {
                list.push_back(cur->val);
            }
        }
        }
        return list;
    }
};