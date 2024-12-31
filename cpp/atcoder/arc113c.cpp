#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
int a[26];
int ans=0;
signed main(){
        cin>>s;
        for(int i=0;i<26;i++) a[i]=0;
        for(int i=s.size()-1;i;i--){
                if(s[i]==s[i-1]&&s[i]!=s[i+1]){
                        ans+=(int)s.size()-i-1-a[s[i]-'a'];
                        for(int j=0;j<26;j++){
                                if(j==s[i]-'a') continue;
                                a[j]=0;
                        }
                        a[s[i]-'a']=(int)s.size()-i-1;
                }
                a[s[i]-'a']++;
        }
        cout<<ans<<'\n';
}
