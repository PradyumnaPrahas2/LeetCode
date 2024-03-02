class Solution {
    private:
    void traversal2(TreeNode* node,vector<vector<int>>&l,int i){
        if(node==NULL){
            return;
        }
        l[i].push_back(node->val);
        traversal2(node->left,l,i+1);
        traversal2(node->right,l,i+1);
    }
    void traversal(TreeNode* node,vector<int> &l,int i){
        if(node==NULL){
            return;
        }
        l.push_back(i);
        traversal(node->left,l,i+1);
        traversal(node->right,l,i+1);
    }
public:
    int findBottomLeftValue(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        vector<int> l;
        traversal(root,l,0);
        int level=*max_element(l.begin(),l.end());
        vector<vector<int>>l2;
        l2.resize(level+1);
        traversal2(root,l2,0);
        return l2[l2.size()-1][0];
    }
};
