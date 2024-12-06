#include<bits/stdc++.h>
using namespace std;
double a,b,x;
double y;
signed main(){
        cin>>a>>b>>x;
        double xx=max(0.0,b-(2*x)/double(a*a));
        cerr<<xx<<'\n';
        x=x/a-max(0.0,a*xx);
        b=b-xx;
        y=(2*x)/double(b);
        cerr<<a<<' '<<b<<' '<<x<<'\n';
        cout<<fixed<<setprecision(9)<<90-((atan(y/b)/acos(-1))*180)<<'\n';
}
