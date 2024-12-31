#include<bits/stdc++.h>
using namespace std;
int n,q;
string s;
int nw=0;
signed main(){
        cin>>n>>q;
        int x,op;
        cin>>s;
        while(q--){
                cin>>op>>x;
                if(op==1){
                        nw=(nw-x+n)%n;
                }else{
                        cout<<s[(nw+x-1)%n]<<'\n';
                }
        }
}
