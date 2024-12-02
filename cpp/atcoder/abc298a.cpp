#include<bits/stdc++.h>
using namespace std;
int n;
char c;
bool a=0,b=1;
signed main(){
    cin>>n;
    while(n--){
        cin>>c;
        if(c=='o') a=1;
        if(c=='x') b=0;
    }
    if(a&&b) cout<<"Yes\n";
    else cout<<"No\n";
}
