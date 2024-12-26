#include<bits/stdc++.h>
#define int long long
using namespace std;
string s,t;
int nxt[1200500];
int ans[1200500];
int pre[1200500];
signed main(){
        cin>>s>>t;
        for(int i=1;t.size()-i>=0;i++){
                if(t[t.size()-i]==s[s.size()-i]||t[t.size()-i]=='?'||s[s.size()-i]=='?') nxt[i]=1;
                else break;
        }
        pre[0]=1,nxt[0]=1;
        for(int i=0;i<t.size();i++){
                if(s[i]==t[i]||s[i]=='?'||t[i]=='?') pre[i+1]=1;
                else break;
        }
        for(int i=t.size();i>=0;i--){
                if(nxt[i]&&pre[t.size()-i]) cout<<"Yes\n";
                else cout<<"No\n";
        }
}
