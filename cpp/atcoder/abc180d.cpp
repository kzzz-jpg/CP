#include<bits/stdc++.h>
#define int __int128
using namespace std;
long long xx,yy,aa,bb;
int x,y,a,b;
int ans=0;
signed main(){
    cin>>xx>>yy>>aa>>bb;
    x=xx,y=yy,a=aa,b=bb;
    while(a^1&&x*a<y&&x*a<=x+b) x*=a,ans++;
    ans+=(y-x)/b-((y-x)%b==0);
    cout<<(long long)ans<<'\n';
}