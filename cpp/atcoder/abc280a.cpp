#include<bits/stdc++.h>
using namespace std;
int h,w,ans=0;
char c;
signed main(){
        cin>>h>>w;
        for(int i=0;i<h;i++)for(int j=0;j<w;j++) cin>>c,ans+=c=='#';
        cout<<ans<<'\n';
}
