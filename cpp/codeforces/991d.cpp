#include<bits/stdc++.h>
using namespace std;
void solve(){
        string s;
        cin>>s;
        for(int i=1;i<s.size();i++){
                for(int j=i;j&&s[j]>s[j-1]+1;swap(s[j],s[j-1]),s[--j]--);
        }
        cout<<s<<'\n';
}
signed main(){
        int t;
        cin>>t;
        while(t--) solve();
}
