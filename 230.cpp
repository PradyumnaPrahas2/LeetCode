class Solution {
    private:
    void traversal(TreeNode *node,vector<int> &l){
        if(node==NULL){
            return;
        }
        traversal(node->left,l);
        l.push_back(node->val);
        traversal(node->right,l);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> l;
        traversal(root,l);
        sort(l.begin(),l.end());
        return l[k-1];
    }
};
