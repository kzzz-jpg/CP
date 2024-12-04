#include<bits/stdc++.h>
using namespace std;
bool vs[2020][2020];
struct nd{
        int x,y,st;
        nd(int a=0,int b=0,int c=0):x(a),y(b),st(c){}
};
void solve(){
        int n,m;
        cin>>n>>m;
        vector<int> col(n+1,0);
        vector<vector<int>> g(n+1);
        for(int i=1;i<=n;i++)cin>>col[i];
        int x,y,ans=0;
        for(int i=0;i<m;i++){
                cin>>x>>y;
                g[x].push_back(y);
                g[y].push_back(x);
        }
        queue<nd> q;
        q.push(nd(1,n,0));
        while(q.size()){
                auto tp=q.front();q.pop();
                for(auto x:g[tp.x]){
                        for(auto y:g[tp.y]){
                                if(col[x]==col[y]||vs[x][y]) continue;
                                if(x==n&&y==1) {
                                        ans=tp.st+1;
                                        break;
                                }
                                vs[x][y]=1;
                                q.push(nd(x,y,tp.st+1));
                        }
                        if(ans) break;
                }
                if(ans) break;
        }
        if(ans==0) cout<<-1<<'\n';
        else cout<<ans<<'\n';
        for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) vs[i][j]=0;
}
signed main(){
        int t;
        cin>>t;
        while(t--) solve();
}
