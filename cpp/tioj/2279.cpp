#include<bits/stdc++.h>
#include <ctime>
#include <random>
using namespace std;
int n;
random_device rd;
mt19937 rg(rd());
signed main(){
    cin>>n;
    if(n==0) cout<<0<<'\n';
    else if(n==1) cout<<100<<'\n';
    else if(n==2){
        int x=1;
        cout<<2<<endl;
        for(int i=1;i<=1e10;i++) x=(x<<1+x>>1)%100009;
        x=1;
    }
    else if(n==3){
        cout<<3<<endl;
        volatile long long* a[10000] ;
        for(int i=0;i<10000;i++) a[i]=(long long *)(malloc(1024*1024)),a[i][0]=8;
    }
    else if(n==4){
        cout<<4<<endl;;
        vector<int> v(1e9);
        for(int i=1;i<1e9;i+=1e8) v[i]=i;
    }else if(n==5){
        cout<<5<<endl;
        for(int i=1;i<=1e8;i++) cerr<<"                                                                                                                                                                                                                                                                                                                                                                          "<<endl;
    }else if(n==6){
        cout<<6<<endl;
        return 1;
    }else if(n==7){
        cout<<7<<endl;
        cerr<<(0/0)<<'\n';
    }else if(n==8) {
        vector<int> v(3000600);
        for(auto &x:v) x=1;
        cout<<8<<endl;
    }
    else {
        cout<<9<<endl;
        int x=2;
        while(double(clock())/CLOCKS_PER_SEC<0.999) x=((x<<1)+(clock()>>1))%100009;
        cerr<<x<<'\n';
    }
}