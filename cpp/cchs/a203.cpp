#include<bits/stdc++.h>
using namespace std;
#define int long long
int fa[400500];
int sz[400500];
int n,m,f,s,p,k;
bool hasans;
struct undo
{
    int a,sza,b;
    undo(int aa,int szaa,int bb):a(aa),sza(szaa),b(bb){}
};

stack<undo> st;
int find(int x){
    if(fa[x]==x) return x;
    return find(fa[x]);
}
void cb(int a,int b){
    a=find(a),b=find(b);
    if(a==b)return;
    if(sz[a]>sz[b]) swap(a,b);
    st.push(undo(a,sz[a],b));
    fa[a]=b;
    sz[b]+=sz[a];
}
bool chk(int a,int b){
    return find(a)==find(b);
}
int ans[200500],cnt=1;
signed main(){
    cin>>n>>m;
    for(int i=0;i<2*n;i++) fa[i]=i,sz[i]=1;
    for(int i=0;i<m;i++){
        cin>>f>>s;
        cb(f,s+n);
        cb(f+n,s);
    }
    while(st.size()) st.pop();
    cin>>p>>k;
    for(int i=1;i<=p;i++){
        hasans=0;
        for(int j=0;j<k;j++){
            cin>>f>>s;
            cb(f,s+n);
            cb(f+n,s);
            if((!hasans)&&(chk(f+n,f)||chk(s,s+n))){
                ans[cnt++]=i;
                hasans=1;
            }
        }
        while(st.size()){
            auto tp=st.top();st.pop();
            fa[tp.a]=tp.a;
            sz[tp.a]=tp.sza;
            sz[tp.b]-=tp.sza;
        }
    }
    for(int i=1;i<cnt;i++) cout<<ans[i]<<'\n';
}