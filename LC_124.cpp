class Solution {
    private:
    int traversal(TreeNode* root,vector<int>&l)
    {
        if(root==NULL){
            return 0;
        }
        int left,right;
        left=traversal(root->left,l);
        right=traversal(root->right,l);
        left=max(left,0);
        right=max(right,0);
        l[0]=max(l[0],root->val+left+right);
        return root->val+max(left,right);
    }
public:
    int maxPathSum(TreeNode* root) {
        vector<int> l;
        l.push_back(root->val);
        traversal(root,l);
        return l[0];
    }
};
