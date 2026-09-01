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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> inordermap;
        for(int i=0;i<inorder.size();i++){
            inordermap[inorder[i]] = i;
        }

        int preorderIndex = 0;

        return build(preorder,inordermap,preorderIndex,0,inorder.size()-1);
    }
private:
    TreeNode* build(const vector<int>& preorder,const unordered_map<int,int>& inordermap,int& preorderIndex,int left,int right){
        if(left > right){
            return nullptr;
        }

        int rootval = preorder[preorderIndex++];
        TreeNode* root = new TreeNode(rootval);

        int mid = inordermap.at(rootval);

        root->left = build(preorder,inordermap,preorderIndex,left,mid - 1);
        root->right = build(preorder,inordermap,preorderIndex,mid + 1, right);

        return root;
    }
};
