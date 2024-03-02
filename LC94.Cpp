class Solution {
    private:
    void traversal(TreeNode* node,vector<int> &l){
        if(node==NULL){
            return;
        }
        traversal(node->left,l);
        l.push_back(node->val);
        // cout<<node->val<<" ";
        traversal(node->right,l);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> l;
        traversal(root,l);
        return l;
    }
};
