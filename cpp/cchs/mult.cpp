#include<bits/stdc++.h>
using namespace std;
int n,nw=-1;
signed main(){
        cin>>n;
        int t;
        while(n--){
                cin>>t;
                if(nw==-1) nw=t;
                else if(t%nw==1) cout<<t<<'\n',nw=-1;
        }
}
