#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,dl,dr,nl,nr;
string s;
int a[500500],ans=2e18;
signed main(){
    cin>>n;
    cin>>s;
    s=" "+s;
    for(int i=2;i<=n;i++){
        if(s[i]=='1') dr+=i-1,nr++;
    }
    for(int i=1;i<=n;i++){
        int tmp=dl-(nl*(nl+1)/2)+dr-(nr*(nr+1)/2);
        //cerr<<tmp<<'\n';
        if(s[i]=='0'){
            tmp+=min(nl,nr);
        }else{
            nl++;
        }
        //cerr<<tmp<<'\n';
        //cerr<<'\n';
        ans=min(ans,tmp);
        dl+=nl;
        dr-=nr;
        if(i+1<=n&&s[i+1]=='1') nr--;
    }
    cout<<ans<<'\n';
}