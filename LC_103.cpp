class Solution {
    private:
    void traversal(TreeNode*node,vector<int>&l,int i){
        if(node==NULL){
            return;
        }
        l.push_back(i);
        traversal(node->left,l,i+1);
        traversal(node->right,l,i+1);
    }
    void level_order(TreeNode* root,vector<vector<int>>&l,int i){
        if(root==NULL){
            return;
        }
        level_order(root->left,l,i+1);
        l[i].push_back(root->val);
        level_order(root->right,l,i+1);
    }
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<int>l1;
        vector<vector<int>> l;
        if(root==NULL){
            return l;
        }
        traversal(root,l1,0);
        int level=*max_element(l1.begin(),l1.end());
        l.resize(level+1);
        level_order(root,l,0);
        for(int i=0;i<level+1;i++){
            if(i%2!=0){
                reverse(l[i].begin(),l[i].end());
            }
        }
        return l;
    }
};
