class Solution {
    private:
    void level_order(TreeNode*root,vector<vector<int>>&l,int i){
        if(root==NULL){
            return;
        }
        level_order(root->left,l,i+1);
        l[i].push_back(root->val);
        level_order(root->right,l,i+1);
    }
    void traversal(TreeNode*root,vector<int>&l,int i){
        if(root==NULL){
            return;
        }
        l.push_back(i);
        traversal(root->left,l,i+1);
        traversal(root->right,l,i+1);
    }
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<int>l;
        vector<vector<int>>l2;
        if(root==NULL){
            return l2;
        }
        traversal(root,l,0);
        int level=*max_element(l.begin(),l.end());
        l2.resize(level+1);
        level_order(root,l2,0);
        reverse(l2.begin(),l2.end());
        return l2;
    }
};
