﻿//
//                       _oo0oo_
//                      o8888888o
//                      88" . "88
//                      (| -_- |)
//                      0\  =  /0
//                    ___/`---'\___
//                  .' \\|     |// '.
//                 / \\|||  :  |||// \
//                / _||||| -:- |||||- \
//               |   | \\\  -  /// |   |
//               | \_|  ''\---/''  |_/ |
//               \  .-\__  '-'  ___/-. /
//             ___'. .'  /--.--\  `. .'___
//          ."" '<  `.___\_<|>_/___.' >' "".
//         | | :  `- \`.;`\ _ /`;.`/ - ` : | |
//         \  \ `_.   \_ __\ /__ _/   .-` /  /
//     =====`-.____`.___ \_____/___.-`___.-'=====
//                       `=---='
//
//
//     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
//               佛祖保佑         永无BUG
//
//     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
//
//                  江城子 . 程序员之歌
//
//              十年生死两茫茫，写程序，到天亮。
//                  千行代码，Bug何处藏。
//              纵使上线又怎样，朝令改，夕断肠。
//
//              领导每天新想法，天天改，日日忙。
//                  相顾无言，惟有泪千行。
//              每晚灯火阑珊处，夜难寐，加班狂。
//
//
//     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
//
//          佛曰:  
//                  写字楼里写字间，写字间里程序员；  
//                  程序人员写程序，又拿程序换酒钱。  
//                  酒醒只在网上坐，酒醉还来网下眠；  
//                  酒醉酒醒日复日，网上网下年复年。  
//                  但愿老死电脑间，不愿鞠躬老板前；  
//                  奔驰宝马贵者趣，公交自行程序员。  
//                  别人笑我忒疯癫，我笑自己命太贱；  
//
//
//     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~      
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define chungAC ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define MI 1<<30
typedef struct {
    int l, r, val;
} ti;
bool cmp(ti a, ti b) {
    return a.r < b.r;
}
signed main() {
    int n;
    scanf_s("%d", &n);
    for (int i = 0; i < n; i++) {
        int m;
        scanf_s("%d", &m);
        vector<ti> t(m+1);
        for (int j = 1; j <= m; j++) {
            scanf_s("%d%d%d", &t[j].l, &t[j].r, &t[j].val);
        }
        t[0].r = -1;
        sort(t.begin(), t.end(), cmp);
        vector<int> dp(m+1, 0);
        for (int j = 1; j <= m; j++) {
            int maxi = 0;
            for (int jump = j / 2; jump>0; j >>= 1) {
                while (maxi + jump < j && t[maxi + jump].r < t[j].l) {
                    maxi += jump;
                }
            }
            dp[j] = max(dp[j - 1], dp[maxi] + t[j].val);
        }
        printf("%d\n", dp[m]);
    }
    return 0;
}
