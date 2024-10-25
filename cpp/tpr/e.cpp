    #include<bits/stdc++.h>
    #include <ext/pb_ds/tree_policy.hpp>
    #include <ext/pb_ds/assoc_container.hpp>
    using namespace __gnu_pbds;
    using namespace std;
    #define int long long
    int n;
    int pos[200500];
    tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update> ods;
    signed main(){
        cin>>n;
        for(int i=1;i<=n;i++) pos[i]=5000*i,ods.insert({pos[i],i});
        int op,a,b;
        while(cin>>op){
            if(op==3)break;
            else if(op==2){
                cin>>a;
                auto it=ods.find_by_order(a-1);
                cout<<it->second<<'\n';
            }else{
                cin>>a>>b;
                ods.erase(ods.find({pos[a],a}));
                pos[a]=pos[b]-1;
                ods.insert({pos[a],a});
            }
        }
    }
