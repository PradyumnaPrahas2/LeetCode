class Solution {
    void traversal(TreeNode * &Node){
        if(Node==NULL){
            return;
        }
        TreeNode * temp=Node->left;
        Node->left=Node->right;
        Node->right=temp;
        traversal(Node->left);
        traversal(Node->right);
    }
public:
    TreeNode* invertTree(TreeNode* root) {
        traversal(root);
        return root;
    }
};
