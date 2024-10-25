#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<vector<int>> g(n+1,vector<int> (m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>g[i][j];
        }
    }
    for(int j=1;j<=m;j++) g[1][j]+=g[1][j-1];
    for(int i=1;i<=n;i++) g[i][1]+=g[i-1][1];
    for(int i=2;i<=n;i++){
        for(int j=2;j<=m;j++){
            g[i][j]+=max(g[i-1][j],g[i][j-1]);
        }
    }
    cout<<g[n][m]<<endl;
    return 0;
}