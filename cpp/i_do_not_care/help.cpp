#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{
    int x, y, s;
};
vector<int> boss(210, 0), sz(210, 1);
int find(int x) {
    if(boss[x]==x) return x;
    return boss[x] = find(boss[x]); 
}
void Union(int a, int b) {  
    int fa= find(a), fb=find(b);   
    if(fa==fb) return;  
    if(sz[fb] > sz[fa]) swap(fa, fb);
    sz[fa]+=sz[fb];
    boss[fb]=fa;
}
bool same(int a, int b) {
    return find(a)==find(b);
}
signed main() {
    int n, a, b, c;
    cin>>n;
    vector<node> v(n, {0, 0, 0});
    for(int i=0;i<n;i++) {
        cin>>a>>b>>c;
        v[i].x=a, v[i].y=b, v[i].s=c;
    }
    vector<tuple<int, int, int>> edge;
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            int t=abs(v[i].x-v[j].x)+abs(v[i].y-v[j].y);
            cerr<<t/v[i].s+(t%v[i].s>=1)<<' '<<t/v[j].s+(t%v[j].s>=1)<<'\n';
            edge.push_back({t/v[i].s+(t%v[i].s>=1), i, j});
            edge.push_back({t/v[j].s+(t%v[j].s>=1), j, i});
        }
    }
    int mx=0;
    sort(edge.begin(), edge.end());
    for(int i=0;i<=n;i++) boss[i]=i;
    for(auto [w, st, nd]:edge) {
        if(!(same(st, nd))) {
            cerr<<w<<'\n';
            Union(st, nd);
            mx=max(w, mx);
        }
    }
    cout<<mx;
}

