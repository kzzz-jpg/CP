#include<bits/stdc++.h>
using namespace std;
int n;
string s;
vector<int> ln;
int ans;
signed main(){
        cin>>n>>s;
        s=" "+s;
        for(int i=1;i<=n;i++) if(s[i]=='/') ln.push_back(i);
        for(auto x:ln){
                int nw=1;
                int l=x,r=x;
                while(l-1>=1&&r+1<=n&&s[l-1]=='1'&&s[r+1]=='2') nw+=2,l--,r++;
                ans=max(ans,nw);
        }
        cout<<ans<<'\n';
}
