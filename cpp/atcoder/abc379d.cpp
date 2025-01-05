#include<bits/stdc++.h>
#define int long long
using namespace std;
int q,h,ans,op;
int ti=0;
priority_queue<int> pq;
signed main(){
    cin>>q;
    while(q--){
        cin>>op;
        if(op==1){
            pq.push(0-ti);
        }else if(op==2){
            cin>>h;
            ti+=h;
        }else{
            cin>>h;
            ans=0;
            while(pq.size()&&pq.top()+ti>=h) ans++,pq.pop();
            cout<<ans<<'\n';
        }
    }
}