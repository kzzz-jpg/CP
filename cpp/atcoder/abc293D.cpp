#include<bits/stdc++.h>
using namespace std;
struct ls{
    int l,r;
} l[200500];
bool vs[200500];
int ans1,ans2;
int n,m;
bool  dfs(int x){
    vs[x]=1;
    for(int st=l[x].r,lt=x;st;){
        vs[st]=1;
        if(st==x) return 1;
        if(l[st].r!=lt){
            lt=st;
            st=l[st].r;
        }else{
            lt=st;
            st=l[st].l;
        }
    }
    for(int st=l[x].l,lt=x;st;){
        vs[st]=1;
        if(st==x) return 1;
        if(l[st].r!=lt){
            lt=st;
            st=l[st].r;
        }else{
            lt=st;
            st=l[st].l;
        }
    }
    return false;
}
signed main(){
    cin>>n>>m;
    int a,c;
    char b,d;
    for(int i=1;i<=m;i++){
        cin>>a>>b>>c>>d;
        if(b=='R'){
            l[a].r=c;
        }else l[a].l=c;
        if(d=='R'){
            l[c].r=a;
        }else{
            l[c].l=a;
        }
    }
    for(int i=1;i<=n;i++){
        if(!vs[i]){
            if(dfs(i)) ans1++;
            else ans2++;
        }
    }
    cout<<ans1<<' '<<ans2<<'\n';
}