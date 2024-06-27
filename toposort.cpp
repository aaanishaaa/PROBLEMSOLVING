#include<vector>
#include<iostream>
#include<queue>
using namespace std;
int main(){
    int V,E;
    cout<<"Enter the no. of vertices";
    cin>>V;
    cout<<"Enter the no of edges";
    cin>>E;
    vector<int> Indegree(V,0);
    vector<int> Outdegree(V,0);
    vector<int> adjlist[V];
    for(int i=1;i<=E;i++){
        int a,b;
        cout<<"Enter the end points of e"<<i<<" ";
        cin>>a>>b;
        adjlist[a].push_back(b);}
/*************Outdegree*************/
for(int i=0;i<V;i++){
    Outdegree[i]=adjlist[i].size();
}
/*************Indegree**************/
for(int i=0;i<V;i++){
    for(int j=0;j<adjlist[i].size();j++){
        Indegree[adjlist[i][j]]++;
    }
}
/***********************************/
    queue<int> Q;
    for(int i=0;i<V;i++){
        if(Indegree[i]==0){
            Q.push(i);
        }
    }
    while(!Q.empty()){
        int x=Q.front();
        Q.pop();
        cout<<x<<",";
        for(int j=0;j<adjlist[x].size();j++){
            int y=adjlist[x][j];
            Indegree[y]--;
            if(Indegree[y]==0){
                Q.push(y);
            }
        }
    }
}