#include<bits/stdc++.h>
using namespace std;
signed main(){
        string a,b;
        cin>>a>>b;
        if(a.size()>b.size()) swap(a,b);
        while(a.size()<b.size()) a.push_back('%');
        for(int i=0;i<a.size();i++){
                if(a[i]!=b[i]){
                        return cout<<i+1<<'\n',0;
                }
        }
        cout<<0<<'\n';
}
