#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,nw;
signed main(){
        cin>>n>>k;
        while(n--){
                int x;
                cin>>x;
                if(x>=nw) cout<<x+k<<'\n',nw=x+k;
                else cout<<nw+k<<'\n',nw+=k;

        }
}
