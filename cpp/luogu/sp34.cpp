#include<bits/stdc++.h>
using namespace std;
random_device rds;
mt19937 rg(rds());
int x[1050],y[1050];
int n;
int rgx,rgy;
double nx,ny,ans,ansx,ansy;
double getans(double cx,double cy){
    double ret=10000000;
    for(int i=1;i<=n;i++) ret=min(ret,sqrt((cx-x[i])*(cx-x[i])+(cy-y[i])*(cy-y[i])));
    return ret;
}
void sa(){
    uniform_real_distribution<> rdx(-rgx,rgx),rdy(-rgy,rgy); 
    double T=1e5,ed=1e-6,low=0.997;
    for(;T>ed;T*=low){
        double dx=rdx(rg)*T,dy=rdy(rg)*T;
        if(nx+dx>rgx||nx+dx<1||ny+dy>rgy||ny+dy<1) continue;
        nx+=dx,ny+=dy;
        double nw=getans(nx,ny);
        if(nw>ans) ans=nw,ansx=nx,ansy=ny;
        else if(exp((nw-ans)/T)<(double(rg())/(rg.max()+1))) nx-=dx,ny-=dy;
    }
}
void solve(){
    cin>>rgx>>rgy>>n;
    ans=0;
    nx=1,ny=1;
    ansx=1,ansy=1;
    for(int i=1;i<=n;i++) cin>>x[i]>>y[i];
    for(int i=1;i<=500;i++) sa();
    cout<<"The safest point is ("<<fixed<<setprecision(1)<<ansx<<", "<<ansy<<").\n";
}
signed main(){
    int t=1;
    cin>>t;
    while(t--) solve();
}