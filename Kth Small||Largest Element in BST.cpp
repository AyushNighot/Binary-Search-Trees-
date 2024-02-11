Intuition:
We need the kth smallest element. And, we know that our inorder traversal will first give the 1st smallest element, then 2nd smallest element ... and so on.
So, instead of storing the node values inside a vector, we can maintain a 'cnt' variable to keep track if we have reached kth smallest value or not in the inorder traversal. And then, we can return the value once cnt reaches k value.

Algorithm:
Initialize a variable, cnt = 0;
Do an Inorder traversal and instead of saving node->val in vector do a cnt++, denoting that we have encountered cnt th smallest element.
Return node->val once cnt == k.

  
Complexity:
Time complexity: O(n)O(n)O(n)
O(n) for traversing the Tree consisting of n nodes.
Space complexity:O(1)O(1)O(1) + recursive stack space



Code:
class Solution {
public:
    void solve(TreeNode* root, int &cnt, int &ans, int k){
        if(root == NULL)    return;
        //left, root, right 
        solve(root->left, cnt, ans, k);
        cnt++;
        if(cnt == k){
            ans = root->val;
            return;
        }
        solve(root->right, cnt, ans, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        
        int cnt = 0;        
        int ans;
        solve(root, cnt, ans, k);
        return ans;
    }
};
