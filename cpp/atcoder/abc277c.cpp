#include<bits/stdc++.h>
using namespace std;
int a[400500],b[400500];
int n;
int fa[400500],sz[400500];
int mx[400500];
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
    mx[b]=max(mx[a],mx[b]);
}
vector<int> lsh;
signed main(){
    cin>>n;
    lsh.push_back(1);
    for(int i=1;i<=n;i++) cin>>a[i]>>b[i],lsh.push_back(a[i]),lsh.push_back(b[i]);
    sort(lsh.begin(),lsh.end());
    lsh.erase(unique(lsh.begin(),lsh.end()),lsh.end());
    for(int i=1;i<=n;i++) a[i]=lower_bound(lsh.begin(),lsh.end(),a[i])-lsh.begin(),b[i]=lower_bound(lsh.begin(),lsh.end(),b[i])-lsh.begin();
    for(int i=0;i<=2*n;i++) fa[i]=i,sz[i]=1,mx[i]=i;
    for(int i=1;i<=n;i++) cb(a[i],b[i]);
    int ans=mx[find(0)];
    cout<<lsh[ans]<<'\n';
    return 0;
}