#include<bits/stdc++.h>
using namespace std;
void solve(){
        string s;
        cin>>s;
        reverse(s.begin(),s.end());
        for(auto x:s) {
                if(x=='p') cout<<'q';
                else if(x=='q') cout<<'p';
                else cout<<'w';
        }
        cout<<'\n';
}
signed main(){
        int t;
        cin>>t;
        while(t--)solve();
}
