#include<bits/stdc++.h>
using namespace std;
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int h,w,s,t,ans=1;
bool inR(int x,int y) {return x>=1&&x<=h&&y>=1&&y<=w;}
int dfn=1;
stack<pair<int,int>> st;
void tarjan(int x,int y,int fx,int fy,vector<vector<char>> &g,vector<vector<int>> &lev,vector<vector<int>> &low){
        low[x][y]=lev[x][y]=dfn++;
        st.push({x,y});
        for(int i=0;i<4;i++){
                int nx=x+dir[i][0],ny=y+dir[i][1];
                if((fx==nx&&fy==ny)||(!inR(nx,ny))||g[nx][ny]=='#') continue;
                if(low[nx][ny]){
                        low[x][y]=min(low[x][y],lev[nx][ny]);
                }else{
                        tarjan(nx,ny,x,y,g,lev,low);
                        low[x][y]=min(low[x][y],low[nx][ny]);
                }
        }
        if(low[x][y]==lev[x][y]){
                while(st.top()!=pair<int,int>{x,y}){
                        st.pop();
                        if(x==s&&y==t) ans++;
                }
                st.pop();
        }
}
signed main(){
        cin>>h>>w;
        vector<vector<char>> g(h+1,vector<char>(w+1));
        vector<vector<int>> lev(h+1,vector<int>(w+1)),low(h+1,vector<int>(w+1));
        for(int i=1;i<=h;i++){
                for(int j=1;j<=w;j++){
                        cin>>g[i][j];
                        if(g[i][j]=='S') s=i,t=j;
                }
        }
        tarjan(s,t,s,t,g,lev,low);
        if(ans>=4) cout<<"Yes\n";
        else cout<<"No\n";
}
