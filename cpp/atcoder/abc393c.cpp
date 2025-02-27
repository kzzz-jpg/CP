#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
map<pair<int,int>,bool> mp;
int x,y;
signed main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>x>>y;
        if(x==y){
            ans++;
            continue;
        }
        if(x<y) swap(x,y);
        if(mp[{x,y}]) ans++;
        else mp[{x,y}]=1;
    }
    cout<<ans<<'\n';
}