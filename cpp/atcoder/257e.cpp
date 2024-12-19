#include<bits/stdc++.h>
#define int long long
using namespace std;
int c[10];
int n;
string ans;
char cmn;
int mn=9999999999;
int num;
signed main(){
        cin>>n;
        for(int i=1;i<=9;i++){
                cin>>c[i];
                if(c[i]<=mn) mn=c[i],cmn='0'+i;
        };
        num=n/mn;
        n=n-num*mn;
        for(int i=1;i<=num;i++) ans.push_back(cmn);
        for(auto &x:ans){
                for(int i=9;i>=1;i--){
                        if(c[i]-mn<=n){
                                x='0'+i;
                                n-=c[i]-mn;
                                break;
                        }
                }
        }
        cout<<ans<<'\n';
}
