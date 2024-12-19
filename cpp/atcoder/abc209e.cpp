#include<bits/stdc++.h>
using namespace std;
struct nd{
        string s,ft,bk;
        bool ev,od;
} a[200500];
map<string,vector<int>> g;
int n;
int dis[200500];
int vs[200500];
void dfs(int x){
        vs[x]=1;
        for(auto to:g[a[x].bk]){
                if(vs[to]==2) {
                        if(dis[to]==-1) {
                                dis[x]=-1;
                                break;
                        }
                        a[x].ev|=a[to].od;
                        a[x].od|=a[to].ev;
                        continue;
                }
                if(vs[to]==1) return dis[x]=-1,void();
                dfs(to);
                if(dis[to]==-1) dis[x]=-1;
                else {
                        a[x].ev|=a[to].od;
                        a[x].od|=a[to].ev;
                }
        }
        vs[x]=2;
}
signed main(){
        cin>>n;
        for(int i=1;i<=n;i++){
                cin>>a[i].s;
                a[i].ft=a[i].s[0]+a[i].s[1]+a[i].s[2];
                a[i].bk=a[i].s[a[i].s.size()-1]+a[i].s[a[i].s.size()-2]+a[i].s[a[i].s.size()-3];
                g[a[i].ft].push_back(i);
        }
}
