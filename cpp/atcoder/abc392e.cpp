#include "bits/stdc++.h"
#include <iterator>
using namespace std;
struct rd{
    int x,y;
    bool usd;
} r[200500];
int n,m,ans;
int fa[200500],sz[200500];
int find(int x){
    if(fa[x]==x) return x;
    return fa[x]=find(fa[x]);
}
void cb(int a,int b){
    a=find(a),b=find(b);
    if(a==b) return;
    if(sz[a]>sz[b])swap(a,b);
    fa[a]=b;
    sz[b]+=sz[a];
}
set<int> s;
vector<pair<int,int>> Ans;
signed main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) fa[i]=i,sz[i]=1;
    for(int i=1;i<=m;i++){
        cin>>r[i].x>>r[i].y;
        if(find(r[i].x)==find(r[i].y)) continue;
        //cerr<<r[i].x<<' '<<r[i].y<<'\n';
        cb(r[i].x,r[i].y);
        r[i].usd=1;
    }
    for(int i=1;i<=n;i++){
        s.insert(find(i));
    }
    //for(auto x:s) cerr<<x<<' ';
    //cerr<<'\n';
    //for(int i=1;i<=n;i++) cerr<<find(i)<<" \n"[i==n];
    for(int i=1;i<=m;i++){
        //cerr<<i<<'\n';
        if(s.size()<2) break;
        if(r[i].usd) continue;
        if(next(s.lower_bound(find(r[i].x)))==s.end()){
            Ans.push_back({i,*s.begin()});
            s.erase(s.begin());
            s.erase(s.lower_bound(find(r[i].x)));
            cb(r[i].x,Ans.back().second);
            s.insert(find(r[i].x));
        }else{
            //cerr<<find(1)<<'\n';
            Ans.push_back({i,*next(s.lower_bound(find(r[i].x)))});
            //cerr<<Ans.back().second<<'\n';
            ///cerr<<r[i].x<<'\n';
            //cerr<<fa[r[i].x]<<'\n';
            //cerr<<find(r[i].x)<<'\n';
            //cerr<<*s.lower_bound(find(r[i].x))<<' '<<*next(s.lower_bound(find(r[i].x)))<<'\n';;
            s.erase(Ans.back().second);
            s.erase(find(r[i].x));
            cb(r[i].x,Ans.back().second);
            s.insert(find(r[i].x));
        }
    }
    cout<<Ans.size()<<'\n';
    for(auto [x,y]:Ans){
        cout<<x<<' '<<r[x].x<<' '<<y<<'\n';
    }
}