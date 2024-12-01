#include<bits/stdc++.h>
using namespace std;
int a[5];
int q,nw,op;
signed main(){
    cin>>q;
    while(q--){
        cin>>op;
        if(op==0){
            cout<<a[nw]<<'\n';
        }else if(op==1){
            a[nw]++;
        }else if(op==2){
            nw=(nw+1)%5;
        }else{
            nw=(nw+4)%5;
        }
    }
}