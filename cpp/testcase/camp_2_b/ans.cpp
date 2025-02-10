#include<bits/stdc++.h>
using namespace std;
const int n=9;
int pos[9][2]={{1,1},{1,4},{1,7},{4,1},{4,4},{4,7},{7,1},{7,4},{7,7}};
int g[10][10];
int x,y;
set<int> s;
bool solve(){
    for(int i=1;i<=n;i++){
        s.erase(s.begin(),s.end());
        for(int j=1;j<=n;j++) s.insert(g[i][j]);
        if(s.size()<n) return 0;
    }
    for(int i=1;i<=n;i++){
        s.erase(s.begin(),s.end());
        for(int j=1;j<=n;j++) s.insert(g[j][i]);
        if(s.size()<n) return 0;
    }
    for(int k=0;k<n;k++){
        int x=pos[k][0],y=pos[k][1];
        s.erase(s.begin(),s.end());
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++) s.insert(g[i+x][j+y]);
        }
        if(s.size()<n) return 0;
    }
    return 1;
}
signed main(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) {
            cin>>g[i][j];
            if(g[i][j]==0) x=i,y=j;
        }
    }
    for(int i=1;i<=9;i++){
        g[x][y]=i;
        if(solve()){
            cout<<i<<'\n';
            return 0;
        }
    }
    cout<<-1<<'\n';
}