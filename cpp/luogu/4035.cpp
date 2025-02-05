
//Failed
#include<bits/stdc++.h>
using namespace std;
random_device rd;
mt19937 rg(rd());
double g[20][20];
double tmp[20];
double nw[20];
int n;
double ans;
double as[20];
double getn(){
    double mx=0,mn=1e9,tnw;
    for(int i=1;i<=n+1;i++){
        tnw=0;
        for(int j=1;j<=n;j++) tnw+=(tmp[j]-g[i][j])*(tmp[j]-g[i][j]);
        mx=max(tnw,mx);
        mn=min(mn,tnw);
    }
    return mx-mn;
}
void sa(){
    double T=30000,ed=1e-7,low=0.998;
    for(;T>ed;T*=low){
        for(int i=1;i<=n;i++){
            tmp[i]=(rg()%2000+rg()%2000-2000)*T;
            nw[i]+=tmp[i];
        }
        double tnw=getn();
        if(tnw<ans){
            ans=tnw;
            for(int j=1;j<=n;j++) as[j]=nw[j];
        }else if(exp((ans-tnw)/T<double(rg())/(rg.max()))){
            for(int i=1;i<=n;i++) nw[i]-=tmp[i];
        }
    }
}
signed main(){
    cin>>n;
    for(int i=1;i<=n+1;i++){
        for(int j=1;j<=n;j++) cin>>g[i][j];
    }
    ans=getn();
    for(int i=1;i<=100;i++) sa();
    for(int i=1;i<=n;i++) cout<<as[i]<<" \n"[i==n];
}