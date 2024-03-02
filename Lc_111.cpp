class Solution {
    private:
    void traversal(TreeNode*node,vector<int>&l,int i){
        if(node==NULL){
            return;
        }
        if(node->left==NULL && node->right==NULL){
            l.push_back(i);
        }
        traversal(node->left,l,i+1);
        traversal(node->right,l,i+1);
    }
public:
    int minDepth(TreeNode* root) {
        vector<int>l;
        if(root==NULL){
            return 0;
        }
        traversal(root,l,0);
        return *min_element(l.begin(),l.end())+1;
    }
};
