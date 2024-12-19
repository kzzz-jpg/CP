#include<bits/stdc++.h>
using namespace std;
string a,b;
signed main(){
        cin>>a>>b;
        reverse(a.begin(),a.end()),reverse(b.begin(),b.end());
        if(a.size()>b.size()) swap(a,b);
        for(int i=0;i<a.size();i++) b[i]+=a[i]-'0';
        for(int i=0;i<b.size();i++){
                if(b[i]>'9'){
                        if(i+1<b.size()) b[i+1]++;
                        else b.push_back('1');
                        b[i]-=10;
                }
        }
        reverse(b.begin(),b.end());
        cout<<b<<'\n';
}
