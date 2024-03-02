class Solution {
    void traversal(TreeNode* node,vector<int>&l,int i){
        if (node==NULL){
            return;
        }
        l.push_back(i);
        traversal(node->left,l,i+1);
        traversal(node->right,l,i+1);
    }
    void traversal2(TreeNode* node,vector<vector<int>>&l2,int i){
        if (node==NULL){
            return;
        }
        traversal2(node->left,l2,i+1);
        l2[i].push_back(node->val);
        traversal2(node->right,l2,i+1);
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> l2;
        vector<int> l;
        if(root==NULL){
            return l2;
        }
        traversal(root,l,0);
        int level=*max_element(l.begin(),l.end());
        l2.resize(1+level);
        traversal2(root,l2,0);
        return l2;
    }
};
