#include<bits/stdc++.h>
using namespace std;
int n,m,h,w,k;
int g[400][400];
int col[400];
int ans;
signed main(){
        cin>>n>>m>>k>>h>>w;
        for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                        cin>>g[i][j];
                        if(col[g[i][j]]++==0) ans++;
                }
        }
        for(int i=1;i<=n-h+1;i++){
                for(int a=i;a<=i+h-1;a++){
                        for(int b=1;b<=w;b++){
                                if(--col[g[a][b]]==0) ans--;
                        }
                }
                for(int b=1;b<=m-w+1;b++){
                        cout<<ans<<' ';
                        if(b==m-w+1){
                                for(int x=b;x<=m;x++){
                                        for(int y=i;y<=i+h-1;y++){
                                                if(col[g[y][x]]++==0) ans++;
                                        }
                                }
                                break;
                        }
                        for(int a=i;a<=i+h-1;a++){
                                if(col[g[a][b]]++==0)ans++;
                                if(--col[g[a][b+w]]==0)ans--;
                        }
                }
                cout<<'\n';
        }
}
