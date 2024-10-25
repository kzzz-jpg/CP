#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve1(){
    string s;
    cin>>s;
    int len=s.size();
    if(s[len-3]=='s'&&s[len-2]=='a'&&s[len-1]=='n')
    cout<<"Yes\n";
    else cout<<"No\n";
}
void solve2(){
    string s,t;
    cin>>s>>t;
    s.push_back(' ');
    t.push_back(' ');
    for(int i=0;i<s.size();i++){
        if(s[i]!=t[i]){
            cout<<(i+1)<<'\n';
            return;
        }
    }
    cout<<0<<'\n';
}
void solve3(){
    int n;
    cin>>n;
    vector<int> a(n);
    int l,r,ans=1e15;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<(1<<n);i++){
        l=r=0;
        for(int j=0;j<n;j++){
            if(i&(1<<j)){
                l+=a[j];
            }else{
                r+=a[j];
            }
        }
        ans=min(ans,max(l,r));
    }
    cout<<ans<<'\n';
}
signed main(){
    int t=1;
    while(t--) solve3();
}