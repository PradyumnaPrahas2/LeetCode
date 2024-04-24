#include<iostream>
#include<list>
#include<vector>
#include<limits.h>
using namespace std;
class Graph{
    private:
    vector<vector<int>>l;
    vector<vector<long>>weights;
    public:
    Graph(int s){
        l.resize(s);
        weights.resize(s);
        for(int i=0;i<s;i++){
            weights[i].resize(s,100000000);
        }
    }
    void addEdge(int i,int j,int w){
        l[i].push_back(j);
        weights[i][j]=w;
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
};
int main()
{
    Graph g(4);
    g.addEdge(0,1,3);
    g.addEdge(1,0,8);
    g.addEdge(1,2,2);
    g.addEdge(0,3,7);
    g.addEdge(3,0,2);
    g.addEdge(2,3,1);
    g.addEdge(2,0,5);
    g.done();
    g.printweight();
    g.getshortest();
    cout<<"After modifying the weights"<<endl;
    g.printweight();
}