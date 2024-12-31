#include<bits/stdc++.h>
using namespace std;
string s;
int ans;
signed main(){
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]!='0') ans++;
        else if(i+1<s.size()&&s[i+1]=='0') ans++,i++;
        else ans++;
    }
    cout<<ans<<'\n';
}