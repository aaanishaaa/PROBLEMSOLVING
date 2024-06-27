#include<vector>
#include<iostream>
#include<queue>
using namespace std;
void dfs(int i,vector<int> al[],vector<int>&status,int &m){
    status[i]=1;
    m++;
    for(int j=0;j<al[i].size();j++){
        int y=al[i][j];
        if(status[y]==0){
            dfs(y,al,status,m);
        }
    }
}
int main(){
    int V,E;
    cout<<"Enter the no. of vertices";
    cin>>V;
    cout<<"Enter the no of edges";
    cin>>E;

    vector<int> adjlist[V];
    for(int i=1;i<=E;i++){
        int a,b;
        cout<<"Enter the end points of e"<<i<<" ";
        cin>>a>>b;
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    }
    // for (int i=0;i<V;i++){
    //     cout<<i<<": ";
    //     int x=adjlist[i].size();
    //     for(int j=0;j<x;j++){
    //         cout<<adjlist[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    vector<int> status(V);
    for(int i=0;i<V;i++){
        int m=0;
        int count=0;
        if(status[i]==0){
            dfs(i,adjlist,status,m);
            cout<<m<<" ";
            m=0;
        }
    }
}