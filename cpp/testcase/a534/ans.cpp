#include <bits/stdc++.h>
using namespace std;
template<class T>
class Prime{
    #define N (int)1e7+9
    public:
        vector<T> list;
        void init(T n){
            //eular(n);
            eratosthenes(n);
        }
    private:
        bitset<N> notprime;//1e8<2^27=128MB
        void eular(T n){
            for(T i=2;i<=n;++i){
                if(!notprime[i])list.emplace_back(i);
                const T k=n/i;
                for(T j:list){
                    if(j>k)break;
                    notprime[i*j]=1;
                    if(!(i%j))break;
                }
            }
        }
        void eratosthenes(T n){
            for(T i=2;i<=n;++i){
                if(!notprime[i])list.emplace_back(i);
                const T k=n/i;
                for(T j:list){
                    if(j>k)break;
                    notprime[i*j]=1;
                }
            }
        }
        
        // T factor[N]
    #undef N
};

#define LL long long
int main(){
    Prime<LL> prime;
    LL n;
    scanf("%lld",&n);
    prime.init(n);
    LL ans=0;
    //for(LL i:prime.list)cout<<i<<" ";
    for(LL i:prime.list)ans^=i;
    printf("%lld",ans);
}
