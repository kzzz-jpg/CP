#include<bits/stdc++.h>
using namespace std;
random_device rd;
mt19937 rg(rd());
int n,k;
struct pt{
        int x,y,c;
} a[61];
vector<double> st;
double getn(double x,double y){
        for(int i=1;i<=n;i++){
                st[i]=a[i].c*sqrt((x-a[i].x)*(x-a[i].x)+(y-a[i].y)*(y-a[i].y));
        }
        sort(st.begin()+1,st.end());
        return st[k];
}
double ansx=0,ansy=0,anst;
double nwx=0,nwy=0;
void sa(){
        double T=300,ed=1e-7,low=0.99;
        for(;T>ed;T*=low){
                double dx=((int)(rg()%1000)-500)*T,dy=((int)(rg()%1000)-500)*T;
                nwx+=dx,nwy+=dy;
                double nw=getn(nwx,nwy);
                if(nw<anst) anst=nw,ansx=nwx,ansy=nwy;
                else if(exp((anst-nw)/T)<double(rg())/rg.max()) nwx-=dx,nwy-=dy;
        }
}
signed main(){
        cin>>n>>k;
        st.resize(n+1);
        for(int i=1;i<=n;i++) cin>>a[i].x>>a[i].y>>a[i].c;
        anst=getn(0,0);
        //while(double(clock())/CLOCKS_PER_SEC<0.8) sa();
        for(int i=0;i<100;i++) sa();
        cout<<fixed<<setprecision(6)<<anst<<'\n';
}
