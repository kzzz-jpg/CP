#include<bits/stdc++.h> 
#define int long long
using namespace std;
int n;
int trie[500500][26];
int tt[500500];
string s[500500];
int cnt=1;
void insert(string &str){
        int nw=0;
        for(int i=0;i<str.size();i++){
                if(trie[nw][str[i]-'a']) nw=trie[nw][str[i]-'a'];
                else trie[nw][str[i]-'a']=cnt++,nw=trie[nw][str[i]-'a'];
                tt[nw]++;
        }
}
signed main(){
        cin>>n;
        for(int i=1;i<=n;i++) cin>>s[i],insert(s[i]);
        for(int i=1;i<=n;i++){
                int nw=0,j=0;
                int ans=0;
                while(j<s[i].size()&&trie[nw][s[i][j]-'a']&&tt[trie[nw][s[i][j]-'a']]>=2){
                        ans++;
                        nw=trie[nw][s[i][j]-'a'];
                        j++;
                }
                cout<<ans<<'\n';
        }
}
