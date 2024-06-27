#include<iostream>
#include<vector>
using namespace std;
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
    for (int i=0;i<V;i++){
        cout<<i<<": ";
        int x=adjlist[i].size();
        for(int j=0;j<x;j++){
            cout<<adjlist[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}