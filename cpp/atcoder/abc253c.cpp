#include<bits/stdc++.h>
#define int long long
using namespace std;
int q;
multiset<int> s;
signed main(){
    cin>>q;
    int op,x,y;
    while(q--){
        cin>>op;
        if(op==1){
            cin>>x;
            s.insert(x);
        }else if(op==2){
            cin>>x>>y;
            for(int i=0;i<y;i++){
                auto it=s.find(x);
                if(it==s.end()) break;
                s.erase(it);
            }
        }else{
            cout<<(*prev(s.end())-*s.begin())<<'\n';
        }
    }
}