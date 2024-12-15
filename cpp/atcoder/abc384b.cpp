#include<bits/stdc++.h>
using namespace std;
int n,t;
signed main(){
    cin>>n>>t;
    int d,a;
    while(n--){
        cin>>d>>a;
        if(d==1){
            if(t>=1600&&t<=2799) t+=a;
        }else{
            if(t>=1200&&t<=2399) t+=a;
        }
    }
    cout<<t<<'\n';
}