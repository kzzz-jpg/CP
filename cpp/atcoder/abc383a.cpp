#include<bits/stdc++.h>
using namespace std;
struct nd{
        int t,v;
} a[3000];
int n;
int nw=0;
signed main(){
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i].t>>a[i].v;
        nw=a[1].v;;
        for(int i=2;i<=n;i++){
                nw=max(0,nw-(a[i].t-a[i-1].t));
                nw+=a[i].v;
        }
        cout<<nw<<'\n';
}
