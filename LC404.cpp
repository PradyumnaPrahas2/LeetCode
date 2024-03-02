class Solution {
    private:
    void traversal(TreeNode* node,vector<int>&l){
        if(node==NULL){
            return;
        }
        if(node->left){
            if(node->left->left==NULL && node->left->right==NULL){
                l.push_back(node->left->val);
            }
        }
        traversal(node->left,l);
        traversal(node->right,l);
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        vector<int>l;
        traversal(root,l);
        int s=0;
        for(int val:l){
            s=s+val;
        }
        return s;
    }
};
