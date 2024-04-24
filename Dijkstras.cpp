#include<iostream>
#include<list>
#include<vector>
#include<limits.h>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
class Graph{
    private:
    vector<vector<int>>l;
    vector<vector<int>>weights;
    public:
    Graph(int s){
        l.resize(s);
        weights.resize(s);
        for(int i=0;i<s;i++){
            weights[i].resize(s,1000000);
        }
    }
    void addEdge(int i,int j,int w){
        l[i].push_back(j);
        l[j].push_back(i);
        weights[i][j]=w;
        weights[j][i]=w;
    }
    void done(){
        for(int i=0;i<weights.size();i++){
            addEdge(i,i,0);
        }
    }
    void getshortest(){
        int n=weights.size();
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    weights[i][j]=min(weights[i][j],weights[i][k]+weights[k][j]);
                }
            }
        }
    }
    void printweight(){
        for(int i=0;i<weights.size();i++){
            for(int val:weights[i]){
                cout<<val<<" ";
            }
            cout<<endl;
        }
    }
    vector<int> answer(int i){
        return weights[i];
    }
    void getweight(int i,int key,vector<int>&ans,vector<bool>&selected,vector<int>&list){
        int mini=INT_MAX;
        int j;
        for(int v=0;v<ans.size();v++)
        {
            if(selected[v]!=true){
                if(ans[v]<mini){
                    mini=ans[v];
                    j=v;
                }
            }
        }
        selected[j]=true;
        vector<int>ans2=answer(j);
        for(int v=0;v<ans.size();v++){
            if(selected[v]==false){
                ans[v]=min(ans[v],ans2[v]);
            }
        }
        list.push_back(j);
        int c=count(ans2.begin(),ans2.end(),1000000);
        if(c==ans2.size()-1){
            return;
        }
        if(key<weights.size()-2){
            return getweight(j,key+1,ans,selected,list);
        }
    }
};
int main()
{
    int size=9;
    Graph g(size);
    g.addEdge(0,1,4);
    g.addEdge(0,7,8);
    g.addEdge(1,7,11);
    g.addEdge(1,2,8);
    g.addEdge(2,3,7);
    g.addEdge(2,5,4);
    g.addEdge(3,5,14);
    g.addEdge(3,4,9);
    g.addEdge(5,4,10);
    g.addEdge(2,8,2);
    g.addEdge(7,8,7);
    g.addEdge(7,6,1);
    g.addEdge(8,6,6);
    g.addEdge(6,5,2);
    // g.addEdge(0,1,3);
    // g.addEdge(0,3,4);
    // g.addEdge(3,2,10);
    // g.addEdge(2,1,-30);
    g.done();
    // g.printweight();
    int x;
    cout<<"enter the source vertex:-";
    cin>>x;
    vector<bool>selected;
    selected.resize(size,false);
    vector<int> ans=g.answer(x);
    selected[x]=true;
    vector<int>list;
    cout<<"Shortest path is"<<endl;
    list.push_back(x);
    g.getweight(x,0,ans,selected,list);
    if(list.size()!=size){
        cout<<"Dijkstra algorithm has failed on this test case"<<endl;
    }
    else{
        for(int v:list){
            cout<<v<<"->";
        }
        cout<<"NULL"<<endl<<"Total path sum is: "<<accumulate(ans.begin(),ans.end(),0);
    }
    g.getshortest();
    cout<<"After modifying the weights"<<endl;
    // g.printweight();
}