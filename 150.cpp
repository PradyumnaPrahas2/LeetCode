#include<string>
#include<stdlib.h>
#include<string>
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        list<int>stack;
        for(string i:tokens){
            if(i!="+" && i!="-" && i!="/" && i!="*"){
                int n=stoi(i);
                stack.push_back(n);
            }
            else if(i=="+"){
                int x=stack.back();
                stack.pop_back();
                int y=stack.back();
                stack.pop_back();
                cout<<x+y<<endl;
                stack.push_back(x+y);
            }
            else if(i=="-"){
                int x=stack.back();
                stack.pop_back();
                int y=stack.back();
                stack.pop_back();
                cout<<y-x<<endl;
                stack.push_back(y-x);
            }
            else if(i=="*"){
                int x=stack.back();
                stack.pop_back();
                int y=stack.back();
                stack.pop_back();
                cout<<x*y<<endl;
                stack.push_back(x*y);
            }
            else if(i=="/"){
                int x=stack.back();
                stack.pop_back();
                int y=stack.back();
                stack.pop_back();
                cout<<y/x<<endl;
                stack.push_back(y/x);
            }
        }
        cout<<stack.size()<<endl;
        return stack.front();
    }
};
