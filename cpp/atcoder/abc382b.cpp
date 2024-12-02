#include<bits/stdc++.h>
using namespace std;
int n,d;
string s;
signed main(){
        cin>>n>>d;
        cin>>s;
        reverse(s.begin(),s.end());
        for(auto &x:s){
                if(x=='@'&&d){
                        x='.';
                        d--;
                }
        }
        reverse(s.begin(),s.end());
        cout<<s<<'\n';
}
