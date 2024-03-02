class Solution {
public:
    bool isValid(string s) {
        if(s.length()%2!=0){
            return false;
        }
        vector<string> stack;
        string c;
        for(int i=0;i<s.length();i++){
            c=s[i];
            if(c=="(" || c=="{" || c=="["){
                stack.push_back(c);
            }
            else if(c==")"){
                if(stack.size()==0){
                    return false;
                }
                if(stack.back()!="("){
                    return false;
                }
                else{
                    stack.pop_back();
                }
            }
            else if(c=="}"){
                if(stack.size()==0){
                    return false;
                }
                if(stack.back()!="{"){
                    return false;
                }
                else{
                    stack.pop_back();
                }
            }
            else if(c=="]"){
                if(stack.size()==0){
                    return false;
                }
                if(stack.back()!="["){
                    return false;
                }
                else{
                    stack.pop_back();
                }
            }
        }
        if(stack.size()>0){
            return false;
        }
        return true;
    }
};
