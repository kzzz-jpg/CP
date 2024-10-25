#include<bits/stdc++.h>
using namespace std;
#define ll long long
signed main(){
    int n;
    cin>>n;
    vector<int> a(n+1);
    vector<int> b(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    ll sum=0;
    deque<pair<int,int>> s;
    s.push_back({a[1],1});
    for(int i=2;i<=n;i++){
        pair<int,int> t={a[i]+b[i],i};
        auto it=upper_bound(s.begin(),s.end(),t);
        if(it==s.end()) sum+=i-1;
        else sum+=i-(it->second)-1;
        while((!s.empty())&&(s.begin()->first<=a[i])) s.erase(s.begin());
        s.push_front({a[i],i});
    }
    cout<<sum<<'\n';
    return 0;
}