#include<bits/stdc++.h>
using namespace std;
vector<pair<double,double>> ln;
int x,y,n;
void addL(double xx,double yy,double xxx,double yyy){
    double a=x-y*(xx-x)/(yy-y);
    double b=x-y*(xxx-x)/(yyy-y);
    ln.push_back({a,b});
}
int a,b,c;
signed main(){
    cin>>n>>x>>y;
    for(int i=0;i<n;i++) {
        cin>>a>>b>>c;
        addL(a,c,b,c);
    }
    sort(ln.begin(),ln.end());
    double l=ln[0].first,r=ln[0].second,ans=0;
    for(int i=1;i<ln.size();i++){
        if(r>=ln[i].first){
            r=max(r,ln[i].second);
        }else{
            ans+=(r-l);
            l=ln[i].first;
            r=ln[i].second;
        }
    }
    ans+=(r-l);
    cout<<fixed<<setprecision(9)<<ans<<'\n';
}