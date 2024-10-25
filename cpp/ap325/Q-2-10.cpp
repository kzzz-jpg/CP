#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define chungAC ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main()
{
    chungAC
    ll n,k;
    cin>>n>>k;
    vector<ll> g(n);
    for(auto &x:g) cin>>x;
    int half=n/2;
    vector<ll> a,b;
    ll ans=0;
    for(int i=0;i<(1<<half);++i){
        ll sum=0;
        for(int j=0;j<half;j++){
            if(i&(1<<j)) sum+=g[j];
        }
        if(sum>ans&&sum<=k) ans=sum;
        a.push_back(sum);
    }
    for(int i=0;i<(1<<(n-half));++i){
        ll sum=0;
        for(int j=0;j<(n-half);j++){
            if(i&(1<<j)) sum+=g[half+j];
        }
        if(sum>ans&&sum<=k) ans=sum;
        b.push_back(sum);
    }
    sort(b.begin(),b.end());
    for(auto x:a){
        int t=0;
        for(int j=b.size();j>0;j>>=1){
            while(t+j<b.size()&&b[t+j]<=k-x){
                t+=j;
            }
        }
        if(x+b[t]>ans&&x+b[t]<=k) ans=x+b[t];
    }
    cout<<endl<<ans<<endl;
    return 0;
}