#include<bits/stdc++.h>
using namespace std;
struct pt{
        int x,y;
}a,b,c,d,e;
signed main(){
        cin>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y;
        d={b.x-a.x,b.y-a.y},e={c.x-a.x,c.y-a.y};
        double ans=abs(d.x*e.y-d.y*e.x)/2.0;
        cout<<fixed<<setprecision(2)<<ans<<'\n';
}
