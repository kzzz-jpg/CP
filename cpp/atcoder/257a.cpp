#include<bits/stdc++.h>
using namespace std;
vector<char> v;
int n,x;
signed main(){
        cin>>n>>x;
        for(int i=0;i<26;i++){
                for(int j=0;j<n;j++) v.push_back('A'+i);
        }
        cout<<v[x-1]<<'\n';
}
