#include<bits/stdc++.h>
using namespace std;
int t1,t2;
char c1,c2;
signed main(){
        cin>>c1>>t1>>c2>>t2;
        if(c1==c2&&t1==t2) cout<<"What\n";
        else if(c1==c2||t1==t2) cout<<"Checkmate\n";
        else cout<<"Nothing Happened\n";
}
