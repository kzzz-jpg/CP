#include<bits/stdc++.h>
#define int long long
using namespace std;
multiset<int> s;
int del=0;
int q;
int op,x;
signed main(){
        cin>>q;
        while(q--){
                cin>>op;
                if(op==1&&cin>>x){
                        s.insert(x-del);
                }else if(op==2&&cin>>x){
                        del+=x;
                }else{
                        cout<<(*s.begin()+del)<<'\n';
                        s.erase(s.begin());
                }
        }
}
