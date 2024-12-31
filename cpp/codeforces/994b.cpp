#include<bits/stdc++.h>
using namespace std;
bool check(deque<char> &a){
    //cerr<<1<<'\n';
    bool flag=1;
    for(auto x:a) {
        //cerr<<x<<'\n';
        if(x=='s') flag=0;
    }
    if(flag) return 1;
    flag=1;
    for(auto x:a) {
       // cerr<<x<<'\n';
        if(x=='p') flag=0;
    }
    if(flag) return 1;
    //cerr<<1<<'\n';
    if((a[0]!='s'&&a.back()!='p')) return 0;
    if(a[0]=='s') return a.pop_front(),check(a);
    if(a.back()=='p') return a.pop_back(),check(a);
}
void solve(){
    int n;
    cin>>n;
    deque<char> a(n);
    for(auto &x:a) cin>>x;
    if(check(a)) cout<<"Yes\n";
    else cout<<"No\n";
}
signed main(){
    int t;
    cin>>t;
    while(t--) solve();
}