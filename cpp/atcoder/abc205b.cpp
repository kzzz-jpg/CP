#include<bits/stdc++.h>
using namespace std;
int n,t;
signed main(){
        cin>>n;
        set<int> s;
        for(int i=1;i<=n;i++) cin>>t,s.insert(t);
        if(s.size()==n) cout<<"Yes\n";
        else cout<<"No\n";
}
