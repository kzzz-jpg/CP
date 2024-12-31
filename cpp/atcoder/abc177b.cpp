#include<bits/stdc++.h>
using namespace std;
string s,t;
int ans=0x3f3f3f;
signed main(){
        cin>>s>>t;
        for(int i=0;i+t.size()<=s.size();i++){
                int dif=0;
                for(int j=0;j<t.size();j++){
                        if(s[i+j]!=t[j]) dif++;
                }
                ans=min(ans,dif);
        }
        cout<<ans<<'\n';
}
