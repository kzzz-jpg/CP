#include<bits/stdc++.h>
using namespace std;
char a,b,c;
char d,e,f;
int dif=0;
signed main(){
        cin>>a>>b>>c;
        cin>>d>>e>>f;
        if(a==d) dif--;
        if(b==e) dif--;
        if(c==f) dif--;
        if(dif+3==2) cout<<"No\n";
        else cout<<"Yes\n";
}
