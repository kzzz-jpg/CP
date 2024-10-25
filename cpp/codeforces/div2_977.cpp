#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve1(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a.begin(),a.end());
    int ans=a[0];
    for(int i=1;i<n;i++) ans=(ans+a[i])>>1;
    cout<<ans<<'\n';
}
void solve2(){
    int n,x;
    cin>>n>>x;
    map<int,int> mp;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i],mp[a[i]]++;
    sort(a.begin(),a.end());
    for(int i=0;i<=n;i++){
        if(i>=x) mp[i]+=mp[i-x];
        if(mp[i]) mp[i]--;
        else{
            cout<<i<<'\n';
            return;
        }
    }
}
void solve3(){
    int n,m,q;
    cin>>n>>m>>q;
    vector<int> a(n),b(m),rb;
    map<int,int> mp;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<m;i++) {
        cin>>b[i];
        if(mp[b[i]]==0) rb.push_back(b[i]);
        mp[b[i]]++;
    }
    for(int i=0;i<rb.size();i++){
        if(a[i]!=rb[i]) {
            cout<<"TIDAK\n";
            return;
        }
    }
    cout<<"YA\n";
}
signed main(){
    int t=1;
    cin>>t;
    while(t--) solve3();
}