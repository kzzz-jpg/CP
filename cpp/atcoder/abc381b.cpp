#include<bits/stdc++.h>
using namespace std;
string s;
int c[26];
signed main(){
        cin>>s;
        if(s.size()&1) return cout<<"No\n",0;
        int n=s.size();
        s=" "+s;
        for(int i=1;i<=n/2;i++){
                if(s[i*2]!=s[i*2-1]){
                        cout<<"No\n";
                        return 0;
                }
        }
        for(int i=1;i<=n;i++) c[s[i]-'a']++;
        for(int i=0;i<26;i++) {
                if(c[i]!=0&&c[i]!=2) return cout<<"No\n",0;
        }
        cout<<"Yes\n";
}
