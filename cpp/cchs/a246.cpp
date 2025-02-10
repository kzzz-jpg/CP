#include "bits/stdc++.h"
//#include <random>
using namespace std;
int seed;
//random_device rd;
//mt19937 rg(rd());
unsigned s;
int lefti[30] = { 0, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1 };
int righti[30] = { 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1 };
int gen(){
    unsigned t = (s & 13) ^ (s << 13) ^ (s >> 16) ^ (s << 14) ^ (s >> 17) ^ (s << 3) ^ (s >> 6);
    unsigned r = (t & 880301) ^ (t >> 11) ^ (t << 11) ^ (t >> 12) ^ (t << 12);
    unsigned u = (t & 110029) ^ (t << 21) ^ (t << 14) ^ (t >> 11) ^ (t >> 9);
    unsigned h = (s ^ t ^ r ^ u);
    for (int i = 0; i < 30; i++) if (lefti[i]) h ^= (h << i);
    for (int i = 0; i < 30; i++) if (righti[i]) h ^= (h >> i);
    return s = h % 1000000001;
}
int x[50], y[50];
void generateTestcase(int n) {
    for (int i = 0; i < n; i++) { 
        x[i] = gen() ^ i;
        y[i] = gen() ^ gen() ^ i;
    }
}
int n;
//double _x,_y;
//int getn(double X,double Y){
//    int ret=0;
//    map<double,int> mp;
//    for(int i=0;i<n;i++){
//        mp[(X-x[i])*(X-x[i])+(Y-y[i])*(Y-y[i])]++;
//    }
//    for(auto [__x,__y]:mp){
//        ret=max(ret,__y);
//    }
//    return ret;
//}
//int ans;
//void sa(){
//    double T=30000,ed=1e-7,low=0.98;
//    for(;T>ed;T*=low){
//        double dx=(rg()*2LL-rg.max())*T,dy=(rg()*2LL-rg.max())*T;
//        int nw=getn(_x+dx,_y+dy);
//        if(nw>ans) ans=nw,_x+=dx,_y+=dy;
//        else if(exp((nw-ans)/T)>(double(rg())/(rg.max()+1LL))) _x+=dx,_y+=dy;
//    }
//}
signed main(){
    cin>>n>>seed;
    s=seed;
    generateTestcase(n);
    cout<<(n*(n-1))<<'\n';
}