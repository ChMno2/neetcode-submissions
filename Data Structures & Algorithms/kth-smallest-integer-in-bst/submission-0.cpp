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
    int kthSmallest(TreeNode* root, int k) {
        int count =0; //走到第幾個節點
        int result = -1;//ans

        inorder(root, k , count , result);
        return result;
    }
private:
    void inorder(TreeNode* node, int k , int& count, int& result){
        if(node == nullptr || count >= k){
            return ;
        }
        inorder(node->left,k,count,result); //left

        count++;
        if(count == k){//inorder
            result = node->val;
            return;
        }

        inorder(node->right,k,count,result);//right


    }
};
