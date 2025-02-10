#include "bits/stdc++.h"
#include <iomanip>
#include <ios>
using namespace std; 
int n;
vector<vector<pair<int,int>>> v(1001);
int mp[101][100500];
int k[1050];
double ans=0;
signed main(){
    cin>>n;
    int tmp;
    bool flag=0;
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>tmp;
            flag=1;
            for(int d=0;d<v[i].size();d++){
                if(v[i][d].first==tmp){
                    v[i][d].second++;
                    flag=0;
                    break;
                }
            }
            if(flag){
                v[i].push_back({tmp,1});
            }
            mp[i][tmp]++;
        }
    }
    double nw;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j) continue;
            nw=0;
            for(auto [x,y]:v[i]){
                nw+=(double(mp[i][x])/k[i])*(double(mp[j][x])/k[j]);
            }
            ans=max(nw,ans);
        }
    }
    cout<<fixed<<setprecision(12)<<ans<<'\n';
}