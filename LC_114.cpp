class Solution {
    void traversal(TreeNode* &node){
        if(node==NULL){
            return;
        }
        if(node->left==NULL && node->right==NULL){
            return;
        }
        if(node->left!=NULL){
            traversal(node->left);
            TreeNode* temp=node->right;
            node->right=node->left;
            node->left=NULL;
            TreeNode*curr=node;
            while(curr->right!=NULL){
                curr=curr->right;
            }
            curr->right=temp;
        }
        traversal(node->right);
    }
public:
    void flatten(TreeNode* root) {
        vector<int>l;
        traversal(root);

    }
};
