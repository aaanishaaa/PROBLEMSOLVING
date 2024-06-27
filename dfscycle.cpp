#include<vector>
#include<iostream>
#include<queue>
using namespace std;
bool dfs_rec(int i,vector<int>&status,vector<int>adjlist[],vector<int>&InRec){
    InRec[i]=1;
    status[i]=1;
    for(int j=0;j<adjlist[i].size();j++){
        if(status[j]==0){
            return dfs_rec(j,status,adjlist,InRec);
        }
        else{
            if(InRec[j]==1){
                return true;
            }
        }
    }
    InRec[i]=0;
    return false;
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

    vector<int> status(V,0);
    vector<int>InRec(V,0);
    bool S;
    for(int i=0;i<V;i++){
        if(status[i]==0){
            S=dfs_rec(i,status,adjlist,InRec);
            if(S==true){
                cout<<"Cycle Detected";
                break;
            }
        }
    }
    if(S==false){
        cout<<"No cycle Detected";
    }
}