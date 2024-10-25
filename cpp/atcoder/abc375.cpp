#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,Ofast,inline,unroll-loops,no-stack-protector,fast-math")
#define int long long
void solve(){
    int n;
    cin>>n;
    vector<char> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    int ans=0;
    for(int i=0;i<n-2;i++){
        if(v[i]=='#'&&v[i+1]=='.'&&v[i+2]=='#') ans++;
    }
    cout<<ans<<'\n';
}
void solve2(){
    int n;
    cin>>n;
    vector<pair<double,double>> v(n+1);
    double ans=0;
    for(int i=1;i<=n;i++){
        cin>>v[i].first>>v[i].second;
        ans+=sqrt((v[i].first-v[i-1].first)*(v[i].first-v[i-1].first)+(v[i].second-v[i-1].second)*(v[i].second-v[i-1].second));
    }
    ans+=sqrt((v[n].first*v[n].first+v[n].second*v[n].second));
    cout<<fixed<<setprecision(9)<<ans<<'\n';
}
void solve3(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin>>n;
    vector<vector<char>> g(n+2,vector<char>(n+2)),rg(n+2,vector<char>(n+2));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) cin>>g[i][j],rg[i][j]=g[i][j];
    }
    for(int i=1;i<=n/2;i++){
        for(int t=0;t<(i%4);t++){
            cerr<<i<<'\n';
            for(int x=i;x<=n+1-i;x++) rg[i][n-x+1]=g[x][i],rg[n-i+1][n-x+1]=g[x][n-i+1];
            for(int y=i;y<n+1-i;y++) rg[y][n-i+1]=g[i][y],rg[y][i]=g[n-i+1][y];
            for(int y=i;y<n+1-i;y++) g[i][y]=rg[i][y],g[n-i+1][y]=rg[n-i+1][y];
            for(int x=i;x<=n+1-i;x++) g[x][i]=rg[x][i],g[x][n+1-i]=rg[x][n+1-i];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<g[i][j];
        }
        cout<<'\n';
    }
}
void solve4(){
    string s;
    cin>>s;
    int l[26]={0},r[26]={0};
    for(auto x:s) r[x-'A']++;
    int ans=0;
    for(int i=0;i<s.size();i++){
        r[s[i]-'A']--;
        for(int j=0;j<26;j++){
            ans+=l[j]*r[j];
        }
        l[s[i]-'A']++;
    }
    cout<<ans<<'\n';
}
struct rd{
    int f,t,w;
};
struct qur{
    int op;
    int x,y;
};
int dp[350][350];
void init(){
    for(int i=1;i<=300;i++){
        for(int j=1;j<=300;j++) dp[i][j]=1e15;
    }
}
void solvef(){
    init();
    int n,m,q;
    cin>>n>>m>>q;
    vector<rd> rod(m+1);
    for(int i=1;i<=m;i++) cin>>rod[i].f>>rod[i].t>>rod[i].w;
    vector<qur> qr(q+1);
    vector<bool> bd(m+1,1);
    for(int i=1;i<=q;i++){
        cin>>qr[i].op;
        if(qr[i].op==1) cin>>qr[i].x,bd[qr[i].x]=0;
        else cin>>qr[i].x>>qr[i].y;
    }
    reverse(qr.begin()+1,qr.begin()+1+q);
    for(int i=1;i<=m;i++){
        if(bd[i]){
            
        }
    }
}
signed main(){
    int t=1;
    //cin>>t;
    while(t--) solve4();
}