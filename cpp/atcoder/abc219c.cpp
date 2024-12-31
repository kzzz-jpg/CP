#include<bits/stdc++.h>
using namespace std;
string t;
string s[50050];
int n;
int p[26];
bool comp(string &a,string &b){
    int len=max(b.size(),a.size());
    for(int i=0;i<len;i++){
        if(i>=b.size()) {
            return 0;
        }
        if(i>=a.size()) {
            return 1;
        }
        if(a[i]==b[i]) continue;
        return p[a[i]-'a']<p[b[i]-'a'];
    }
}
signed main(){
    cin>>t;
    for(int i=0;i<26;i++){
        p[t[i]-'a']=i;
    }
    cin>>n;
    for(int i=1;i<=n;i++) cin>>s[i];
    sort(s+1,s+1+n,comp);
    for(int i=1;i<=n;i++) cout<<s[i]<<'\n';
}