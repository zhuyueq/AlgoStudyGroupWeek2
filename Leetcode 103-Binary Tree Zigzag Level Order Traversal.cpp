/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
/**
performance:faster than 100%
**/
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        std::stack<TreeNode*> treeA,treeB;
        treeA.push(root);
        vector<vector<int>> res;
        TreeNode* cur;
        int level=0;
        if (!root)
        {
            return res;
        }
        while (!treeA.empty() or !treeB.empty()){
            level++;
            while (!treeA.empty()){
            cur=treeA.top();
            treeA.pop();
            if(cur->left) treeB.push(cur->left);
            if(cur->right) treeB.push(cur->right);
            if (res.size()<level) 
            { 
                vector<int> tmp;
                tmp.push_back(cur->val);
                res.push_back(tmp);
            }
            else {
                    res[level-1].push_back(cur->val);
                }
            }
            level++;
            while (!treeB.empty()){
            cur=treeB.top();
            treeB.pop();
            if(cur->right) treeA.push(cur->right);
            if(cur->left) treeA.push(cur->left);
            if (res.size()<level) 
            { 
                vector<int> tmp;
                tmp.push_back(cur->val);
                res.push_back(tmp);
            }
            else {
                    res[level-1].push_back(cur->val);
                }
            }
        }
        return res;
    }
};