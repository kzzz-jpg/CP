#include<bits/stdc++.h>
using namespace std;
string a,b,c;
int q[3];
signed main(){
        cin>>a>>q[0];
        cin>>b>>q[1];
        cin>>c>>q[2];
        if(q[0]>q[1]&&q[0]>q[2]) cout<<a<<'\n';
        else if(q[1]>q[2]&&q[1]>q[0]) cout<<b<<'\n';
        else cout<<c<<'\n';
}
