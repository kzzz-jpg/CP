#include<bits/stdc++.h>
using namespace std;
string s;
int ans;
signed main(){
    cin>>s;
    for(int i=0;i<s.size();i++){
        for(int j=i+1;j<s.size();j++){
            for(int k=j+1;k<s.size();k++){
                if(s[i]=='A'&&s[j]=='B'&&s[k]=='C'&&j-i==k-j) ans++;
            }
        }
    }
    cout<<ans<<'\n';
}