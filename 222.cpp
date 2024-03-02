class Solution {
    private:
    void traversal(TreeNode* node,vector<int> &l){
        if(node==NULL){
            return;
        }
        l.push_back(node->val);
        traversal(node->left,l);
        traversal(node->right,l);
    }
public:
    int countNodes(TreeNode* root) {
        vector<int> l;
        traversal(root,l);
        return l.size();
    }
};
