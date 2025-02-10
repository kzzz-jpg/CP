#include<bits/stdc++.h>
using namespace std;
const int n=18;
int pos[9][2]={{1,1},{1,7},{1,13},  
 {7,1},{7,7},{7,13},  
 {13,1},{13,7},{13,13}};
int g[10][10];
int cnt[10];
void init_cnt(){
    for(int i=0;i<=9;i++) cnt[i]=0;
}
bool check_cnt(int x){
    for(int i=1;i<=9;i++){
        if(cnt[i]!=x) return 1;
    }
    return 0;
}
bool solve(){
    for(int i=1;i<=n;i++){
        init_cnt();
        for(int j=1;j<=n;j++) cnt[g[i][j]]++;
        if(check_cnt(2)) return 0;
    }
    for(int i=1;i<=n;i++){
        init_cnt();
        for(int j=1;j<=n;j++) cnt[g[j][i]]++;
        if(check_cnt(2)) return 0;
    }
    for(int k=0;k<9;k++){
        int x=pos[k][0],y=pos[k][1];
        init_cnt();
        for(int i=0;i<6;i++){
            for(int j=0;j<6;j++) cnt[g[i+x][j+y]]++;
        }
        if(check_cnt(4)) return 0;
    }
    return 1;
}
signed main(){
    int x,y;
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