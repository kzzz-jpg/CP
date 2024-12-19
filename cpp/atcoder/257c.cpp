#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int w[200500];
vector<int> ad,ch;
string s;
int ans;
signed main(){
        cin>>n;
        cin>>s;
        for(int i=1;i<=n;i++){
                cin>>w[i];
                if(s[i-1]=='1') ad.push_back(w[i]);
                else ch.push_back(w[i]);
        }
        ans=ad.size();
        sort(ad.begin(),ad.end());
        sort(ch.begin(),ch.end());
        for(int i=0;i<ch.size();i++){
                int it=ad.end()-upper_bound(ad.begin(),ad.end(),ch[i]);
                ans=max(ans,it+i+1);
        }
        cout<<ans<<'\n';
}
