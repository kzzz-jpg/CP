#include<bits/stdc++.h>
#include<random>
using namespace std;
#define int long long
random_device rd;
mt19937 rg(rd());
int n,m;
string cls[200];
void init(){
    for(int i=0;i<150;i++) cls[i]="";
}
double geta(string s){
    if(s=="A+") return 4.3;
    if(s=="A") return 4.0;
    if(s=="A-") return 3.7;
    if(s=="B+") return 3.3;
    if(s=="B") return 3.0;
    if(s=="B-") return 2.7;
    if(s=="C+") return 2.3;
    if(s=="C") return 2.0;
    if(s=="C-") return 1.7;
    if(s=="D") return 1.0;
    return 0;
}
void solve(){
    init();
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>m;
        cin>>cls[m];
    }
    double ans=0;
    for(int i=1;i<=100;i++) ans+=geta(cls[i]);
    cout<<fixed<<setprecision(1)<<ans<<'\n';
}
signed main(){
    int t=1;
    while(t--) solve();
}