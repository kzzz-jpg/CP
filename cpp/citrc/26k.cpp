#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,q;
map<string,int> mp;
string ans;
int mx;
int sum;
signed main(){
        cin>>n>>q;
        string s;
        int t;
        while(n--){
                cin>>s>>t;
                mp[s]=t;
                sum+=t;
        }
        while(q--){
                cin>>s;
                cout<<mp[s]<<'\n';
        }
        cout<<"total:"<<sum<<'\n';
        for(auto [x,y]:mp){
                if(y>mx) ans=x,mx=y;
        }
        cout<<"most:"<<ans<<'\n';
}
