#include<iostream>
#include<list>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;
void DFS(vector<vector<int>>graph,int source,vector<int>&depth){
    vector<bool>visited;
    visited.resize(graph.size(),false);
    stack<int>h;
    h.push(source);
    visited[source]=true;
    while(!h.empty()){
        int x=h.top();
        h.pop();
        depth.push_back(x);
        for(int val:graph[x]){
            if(visited[val]==false){
                visited[val]=true;
                h.push(val);
            }
        }
    }
}
int main()
{
    int n,m;
    cin>>n;
    cin>>m;
    int j;
    vector<int>k;
    for(int i=0;i<n;i++){
        cin>>j;
        k.push_back(j);
    }
    vector<vector<int>>l;
    int max=*max_element(k.begin(),k.end())+1;
    l.resize(max);
    int x,y;
    for(int i=0;i<m;i++){
        cout<<"Enter edge "<<i+1<<endl;
        cin>>x;
        cin>>y;
        l[x].push_back(y);
        l[y].push_back(x);
    }
    int s;
    cin>>s;
    vector<int>depth;
    DFS(l,s,depth);
    cout<<"Depth First Search:"<<endl;
    for(int val:depth){
        cout<<val<<" ";
    }
    cout<<endl;
    vector<int>check;
    for(int val:k){
        if(val!=s){
        int c=0;
        for(int x:l[s]){
            if(val==x){
                c++;
                break;
            }
        }
        if(c==0){
            check.push_back(val);
        }
        }
    }
    if(check.size()==0){
        cout<<"Nothing"<<endl;
    }
    for(int g:check){
        int c=0;
        for(int q:depth){
            if(q==g){
                c++;
                break;
            }
        }
        if(c>0){
            cout<<g<<" ";
        }
    }
}
