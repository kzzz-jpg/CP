#include<bits/stdc++.h>
#define int long long
using namespace std;
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int r,c,n,p,s,t,ans,cnt;
int g[1010][1010],vs[1000500];
struct posi{
    int x,y;
    posi(int X=0,int Y=0):x(X),y(Y){}
} pos[1000500];
bool inR(int x,int y){
    return x>=1&&x<=r&&y>=1&&y<=c;
}
signed main(){
    scanf("%lld%lld%lld%lld",&r,&c,&n,&p);
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            scanf("%lld",&g[i][j]);
            if(g[i][j]) pos[g[i][j]]=posi(i,j);
        }
    }
    while(p>0){
        for(int i=0;i<4;i++){
            int nx=pos[p].x+dir[i][0],ny=pos[p].y+dir[i][1];
            if(inR(nx,ny)){
                //cerr<<nx<<' '<<ny<<' '<<g[nx][ny]<<' ';
                if(g[nx][ny]){
                    if(g[nx][ny]+cnt<=n&&vs[g[nx][ny]+cnt]==0) ans++,vs[g[nx][ny]+cnt]=1;
                }
            }
        }
        //cerr<<'\n';
        cnt++;
        p--;
    }
    assert(cnt<=n);
    printf("%lld/%lld",ans,n-1);
}