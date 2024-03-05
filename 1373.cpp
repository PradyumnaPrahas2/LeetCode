class Solution {
    private:
    bool Valid(TreeNode*root,vector<int>&valid){
        if(root==NULL){
            return true;
        }
        if(root->left==NULL && root->right==NULL){
            return true;
        }
        else if(root->left!=NULL && root->right!=NULL){
            if(root->left->val>=root->val){
                valid.push_back(1);
                return false;
            }
            else if(root->right->val<=root->val){
                valid.push_back(1);
                return false;
            }
        }
        else if (root->left!=NULL){
            if(root->left->val>=root->val){
                valid.push_back(1);
                return false;
            }
        }
        else{
            if(root->right->val<=root->val){
                valid.push_back(1);
                return false;
            }
        }
        return Valid(root->left,valid) && Valid(root->right,valid);
    }
    void list(TreeNode*root,vector<int>&l){
        if(root==NULL){
            return ;
        }
        l.push_back(root->val);
        list(root->left,l);
        list(root->right,l);
    }
    void traversal(TreeNode*root,vector<int>&l){
        if(root==NULL){
            return;
        }
        vector<int>valid;
        if(Valid(root,valid)==true){
            vector<int> left;
            vector<int> right;
            list(root->left,left);
            list(root->right,right);
            int c=0;
            cout<<left.size()<<"-"<<right.size()<<endl;
            if(left.size()==0 && right.size()==0){
                c++;
            }
            else{
                if(left.size()!=0){
                    cout<<left.size();
                    if(root->val>*max_element(left.begin(),left.end())){
                        c++;
                    }
                }
                if(right.size()!=0){
                    if(root->val<*min_element(right.begin(),right.end())){
                        c++;
                    }
                }
            }
            if(c>0){
                vector<int>k;
                list(root,k);
                l.push_back(accumulate(k.begin(),k.end(),0));
                }
        }
        traversal(root->left,l);
        traversal(root->right,l);
    }
public:
    int maxSumBST(TreeNode* root) {
        vector<int>l;
        traversal(root,l);
        int x=*max_element(l.begin(),l.end());
        
        if(x<0){
            return 0;
        }
        return x;
    }
};
