#include<bits/stdc++.h>
using namespace std;
int n;
char g[100][100];
signed main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        int j=n-i+1;
        if(i>j) continue;
        for(int x=i;x<=j;x++){
            for(int y=i;y<=j;y++){
                if(i&1){
                    g[x][y]='#';
                }else{
                    g[x][y]='.';
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<g[i][j];
        }
        cout<<'\n';
    }
}