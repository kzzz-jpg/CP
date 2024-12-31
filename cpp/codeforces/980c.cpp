#include<bits/stdc++.h>
#define int long long
using namespace std;
struct pt{
    int x,y;
    bool operator < (pt o) const{
        int a=0,b=0;
        if(x<o.x) a++;
        if(x<o.y) a++;
        if(y<o.x) a++;
        if(y<o.y) a++;
        if(x>o.x) b++;
        if(x>o.y) b++;
        if(y>o.x) b++;
        if(y>o.y) b++;
        return a>b;
    }
} a[200500];
int n;
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i].x>>a[i].y;
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++) cout<<a[i].x<<' '<<a[i].y<<" \n"[i==n];
}
signed main(){
    int t;
    cin>>t;
    while(t--)solve();
}