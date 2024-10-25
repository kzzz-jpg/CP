#include<bits/stdc++.h>
using namespace std;
int a,b,d;
signed main(){
    cin>>a>>b;
    d=b-a;
    if(d<10) cout<<"不罰";
    else if(d<20) cout<<3000;
    else if(d<40) cout<<3500;
    else if(d<60) cout<<500;
    else cout<<6000;
}