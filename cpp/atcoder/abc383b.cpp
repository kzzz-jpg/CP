#include<bits/stdc++.h>
using namespace std;
int h,w,d;
char g[12][12];
int ans=0;
void upd(int x,int y,int xx,int yy){
        int nw=0;
        for(int i=1;i<=h;i++) for(int j=1;j<=w;j++){
                if((abs(i-x)+abs(j-y)<=d||abs(i-xx)+abs(j-yy)<=d)&&g[i][j]=='.') nw++;
        }
        ans=max(ans,nw);
}
signed main(){
        cin>>h>>w>>d;
        for(int i=1;i<=h;i++) for(int j=1;j<=w;j++) cin>>g[i][j];
        for(int i=1;i<=h;i++) for(int j=1;j<=w;j++) for(int k=1;k<=h;k++) for(int l=1;l<=w;l++) if(g[i][j]=='.'&&g[k][l]=='.') upd(i,j,k,l);
        cout<<ans<<'\n';
}
