#include<bits/stdc++.h>
#define ing long long
using namespace std;
struct pt{
    int x,y;
} a[200500];
int n;
bool chk(double pos){
    for(int i=2;i<=n;i++){
     //   cerr<<(a[i].y-a[i-1].y)*a[i-1].x<<' '<<(a[i-1].y-pos)*(a[i].x-a[i-1].x)<<'\n';
        if((a[i].y-a[i-1].y)*a[i-1].x<=(a[i-1].y-pos)*(a[i].x-a[i-1].x)) return 0;
    }
    //cerr<<pos<<' '<<1<<'\n';
    return 1;
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i].x>>a[i].y;
    double l=0,r=1e20;
    if(chk(0)) return cout<<-1<<'\n',0;
    int cnt=0;
    while(r-l>1e-10){
        cnt++;
        if(cnt>5000) break;
        double mid=(l+r)/2;
        if(chk(mid)){
            r=mid;
        }else{
            l=mid;
        }
    }
    //cerr<<chk(1)<<'\n';
    cout<<fixed<<setprecision(10)<<l<<'\n';
}