#include<bits/stdc++.h>
using namespace std;
int n,t,a,x;
double mn=1e9,pos;
signed main(){
        cin>>n;
        cin>>t>>a;
        for(int i=1;i<=n;i++){
                cin>>x;
                if(abs((t-x*0.006)-a)<mn) mn=abs((t-x*0.006)-a),pos=i;
        }
        cout<<pos<<'\n';
}
