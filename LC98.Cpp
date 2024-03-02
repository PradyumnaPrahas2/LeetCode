class Solution {
    private:
    void get_tree(TreeNode* node,vector<int>&l){
        if(node==NULL){
            return;
        }
        cout<<node->val<<" ";
        l.push_back(node->val);
        get_tree(node->left,l);
        get_tree(node->right,l);
    }
    void traversal2(TreeNode* node,vector<int>&l2){
        if(node==NULL){
            return;
        }
        if(node->left){
            vector<int> ref;
            get_tree(node->left,ref);
            int x=*max_element(ref.begin(),ref.end());
            cout<<"for "<<node->val<<endl;
            if(node->val<=x){
                l2.push_back(1);
            }
        }
        if(node->right){
            vector<int> ref2;
            get_tree(node->right,ref2);
            int x2=*min_element(ref2.begin(),ref2.end());
            cout<<"for "<<node->val<<endl;
            if(node->val>=x2){
                l2.push_back(1);
            }
        }
        traversal2(node->left,l2);
        traversal2(node->right,l2);
    }
    void traversal(TreeNode* node,vector<int>&l){
        if(node==NULL){
            return;
        }
        traversal(node->left,l);
        if(node->left!=NULL && node->right!=NULL){
            if(node->val<=node->left->val){
                l.push_back(1);
            }
            if(node->val>=node->right->val){
                l.push_back(1);
            }
        }
        else if(node->left!=NULL){
            if(node->val<=node->left->val){
                l.push_back(1);
            }
        }
        else if(node->right!=NULL){
            if(node->val>=node->right->val){
                l.push_back(1);
            }
        }
        
        traversal(node->right,l);
    }
public:
    bool isValidBST(TreeNode* root) {
        vector<int> l;
        vector<int> l2;
        traversal(root,l);
        if(l.size()>0){
            return false;
        }
        traversal2(root,l2);
        if(l2.size()>0){
            return false;
        }
        return true;
    }
};
