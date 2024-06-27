#include<iostream>
#include<vector>
#include<queue>
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
    queue<int>Q;
    vector<int>status(V,0);
    Q.push(0);
    status[0]=1;
    cout<<"BFS order is => ";
    while(Q.size()!=0){
        int x=Q.front();
        Q.pop();
        cout<<x<<" ";
        for(int j=0;j<adjlist[x].size();j++){
            int y=adjlist[x][j];
            if(status[y]==-1){
                status[y]=status[x]+1;
                Q.push(y);
            }
        }
    }
    cout<< "distance is =>";
    for(int i=0;i<status[i];i++){
         cout<<status[i]<<" ";
    }
    return 0;
}