#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> AV[5];
    AV[0].push_back(1);
    AV[0].push_back(2);
    AV[0].push_back(3);
    AV[0].push_back(4);

    AV[1].push_back(5);
    AV[1].push_back(6);
    AV[1].push_back(7);

    AV[2].push_back(8);
    AV[2].push_back(9);
    AV[2].push_back(10);
    AV[2].push_back(11);
    AV[2].push_back(12);

    AV[3].push_back(13);
    AV[3].push_back(14);

    AV[4].push_back(15);
    AV[4].push_back(16);
    AV[4].push_back(17);
    AV[4].push_back(18);

    for (int i=0;i<5;i++){
        int x=AV[i].size();
        for(int j=0;j<x;j++){
            cout<<AV[i][j]<<" ";
        }
        cout<<"\n";
    }
    // V.push_back(10);
    // V.push_back(20);
    // V.push_back(30);
    // V.push_back(40);
    // int x=V.size();
    // for(int i=0;i<x;i++){
    //     cout<<V[i]<<endl;
    // }
    // cout<<V.size();
    return 0;
}