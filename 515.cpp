class Solution {
    private:
    void traversal(TreeNode* root,vector<int>&l,int i){
        if(root==NULL){
            return;
        }
        l.push_back(i+1);
        traversal(root->left,l,i+1);
        traversal(root->right,l,i+1);
    }
    void traversal2(TreeNode*root,vector<vector<int>>&l,int i){
        if(root==NULL){
            return;
        }
        l[i].push_back(root->val);
        traversal2(root->left,l,i+1);
        traversal2(root->right,l,i+1);
    }
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> l;
        if(root==NULL){
            return l;
        }
        traversal(root,l,0);
        if(l.size()==1){
            l.pop_back();
            l.push_back(root->val);
            return l;
        }
        vector<vector<int>>l2;
        l2.resize(*max_element(l.begin(),l.end()));
        traversal2(root,l2,0);
        vector<int> ans;
        for(vector<int> b:l2){
            ans.push_back(*max_element(b.begin(),b.end()));
        }
        return ans;
    }
};
