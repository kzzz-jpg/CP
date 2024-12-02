#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
tree<int,null_type,greater<int>,rb_tree_tag,tree_order_statistics_node_update> s;
int n,k;
signed main(){
        cin>>n>>k;
        int t;
        for(int i=1;i<k;i++) cin>>t,s.insert(t);
        for(int i=k;i<=n;i++){
                cin>>t;
                s.insert(t);
                cout<<*s.find_by_order(k-1)<<'\n';
        }
}
