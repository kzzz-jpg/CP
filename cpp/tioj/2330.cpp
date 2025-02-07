#include "bits/stdc++.h"
using namespace std;
#define int long long
int n,m;
struct house{
    int x,y,r,id;
    unsigned long long dis=8e18;
    bool operator<(house o)const{
        if(dis==o.dis){
            if(r==o.r) return id<o.id;
            return r<o.r;
        }
        return dis<o.dis;
    }
} a[100500];
struct sta{
    int x,y;
} p[2006];
signed main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i].x>>a[i].y>>a[i].r;
        a[i].dis=8e18;
        a[i].id=i;
    }
    for(int i=1;i<=m;i++) cin>>p[i].x>>p[i].y;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            a[i].dis=min(a[i].dis,(unsigned long long)(a[i].x-p[j].x)*(a[i].x-p[j].x)+(a[i].y-p[j].y)*(a[i].y-p[j].y));
        }
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++) cout<<a[i].id<<"\n";
}