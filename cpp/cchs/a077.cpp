#include<bits/stdc++.h>
using namespace std;
int n,m;
double N=0;
signed main(){
    cin>>n>>m;
    vector<vector<double>> g(n,vector<double>(m));
    vector<double> sa(n),sb(m);
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) {
        cin>>g[i][j];
        sa[i]+=g[i][j];
        sb[j]+=g[i][j];
        N+=g[i][j];
    }
    vector<vector<double>> e(n,vector<double>(m));
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) e[i][j]=sa[i]*sb[j]/N;
    double ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ans+=(g[i][j]-e[i][j])*(g[i][j]-e[i][j])/(e[i][j]);
        }
    }
    cout<<fixed<<setprecision(2)<<ans<<'\n';
}