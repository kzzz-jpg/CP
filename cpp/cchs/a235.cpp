#include<bits/stdc++.h>
using namespace std;
const int n=9;
int pos[9][2]={{1,1},{1,4},{1,7},{4,1},{4,4},{4,7},{7,1},{7,4},{7,7}};
int g[10][10];
set<int> s;
void solve(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) {
            if(i==1&&j==1) continue;
            cin>>g[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        s.erase(s.begin(),s.end());
        for(int j=1;j<=n;j++) s.insert(g[i][j]);
        if(s.size()<n) return cout<<"no\n",void();
    }
    for(int i=1;i<=n;i++){
        s.erase(s.begin(),s.end());
        for(int j=1;j<=n;j++) s.insert(g[j][i]);
        if(s.size()<n) return cout<<"no\n",void();
    }
    for(int k=0;k<n;k++){
        int x=pos[k][0],y=pos[k][1];
        s.erase(s.begin(),s.end());
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++) s.insert(g[i+x][j+y]);
        }
        if(s.size()<n) return cout<<"no\n",void();
    }
    cout<<"yes\n";
}
signed main(){
    while(cin>>g[1][1]){
        solve();
    }
}