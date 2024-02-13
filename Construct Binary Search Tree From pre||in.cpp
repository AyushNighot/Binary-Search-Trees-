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
    int i=0;
    TreeNode* builtBST(vector<int>& preorder,int start,int end){
        if(start>end)return NULL;
        int curr=preorder[i];
        TreeNode* root=new TreeNode(preorder[i++]);
        int j;
        for(j=i;j<preorder.size();j++){
            if(preorder[j]>curr)break;
        }
        root->left=builtBST(preorder,i,j-1);
        root->right=builtBST(preorder,j,end);
        return  root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return builtBST(preorder,0,preorder.size()-1);       
    }
};
