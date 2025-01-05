#include<bits/stdc++.h>
using namespace std;
string s;
int n,k,ans;
signed main(){
    cin>>n>>k;
    cin>>s;
    for(int i=0;i+k-1<s.size();i++){
        if(s[i]=='O'){
            bool flag=1;
            for(int j=0;j<k;j++){
                if(s[i+j]!='O'){
                    flag=0;
                    break;
                }
            }
            if(flag) ans++,i=i+k-1;
        }
    }
    cout<<ans<<'\n';
}