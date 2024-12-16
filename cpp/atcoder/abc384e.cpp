#include<bits/stdc++.h>
#define int long long
using namespace std;
int h,w,p,q,x;
int g[505][505];
bool vs[505][505];
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
struct nd{
    int hp,x,y;
    nd(int h=0,int xx=0,int yy=0):hp(h),x(xx),y(yy){}
    bool operator<(nd o) const{
        return hp>o.hp;
    }
};
int ans;
priority_queue<nd> pq;
signed main(){
    cin>>h>>w>>x>>p>>q;
    for(int i=1;i<=h;i++) for(int j=1;j<=w;j++) cin>>g[i][j];
    for(int i=0;i<=h+1;i++) vs[i][0]=vs[i][w+1]=1;
    for(int i=0;i<=w+1;i++) vs[0][i]=vs[h+1][i]=1;
    vs[p][q]=1;
    ans=g[p][q];
    pq.push(nd(g[p][q],p,q));
    while(pq.size()){
        auto tp=pq.top();pq.pop();
        //cerr<<tp.hp<<'\n';
        if(tp.hp*(__int128)x<(__int128)ans||(tp.x==p&&tp.y==q)){
            if(tp.x!=p||tp.y!=q) ans+=tp.hp;
            //cerr<<tp.x<<' '<<tp.y<<'\n';
            for(int i=0;i<4;i++){
                int nx=tp.x+dir[i][0],ny=tp.y+dir[i][1];
                //cerr<<nx<<' '<<ny<<'\n';
                if(!vs[nx][ny]){
                    //cerr<<nx<<' '<<ny<<' '<<g[nx][ny]<<'\n';
                    vs[nx][ny]=1;
                    pq.push(nd(g[nx][ny],nx,ny));
                }
            }
        }else break;
    }
    cout<<ans<<'\n';
}