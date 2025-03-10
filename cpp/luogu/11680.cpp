#include<bits/stdc++.h>
using namespace std;
bool chk(int x){
    string s;
    while(x){
        s.push_back(x%10);
        x/=10;
    }
    //if(s.size()<2) return 0;
    if(s.size()&1){
        if(s[0]==s.back()&&s.back()==s[s.size()/2]) return 1;
        return 0;
    }
    return 0;
}
void solve(){
    int l,r;
    cin>>l>>r;
    for(int i=l;i<=r;i++){
        if(chk(i)){
            cout<<i<<' ';
        }
    }
    cout<<'\n';
}
signed main(){
    int t;
    cin>>t;
    while(t--) solve();
}