#pragma GCC optimize("Ofast,fast-math")
#pragma GCC target("avx,avx2")
#include <cstdio>
#include <immintrin.h>

int n;
__m256i amounts[25010]; 
__m256i prices[25010];  

void init_prices(int n) {
    for (int i = 0; i < n; i += 4) {
        __m256i p = _mm256_set_epi64x(i + 4, i + 3, i + 2, i + 1);
        prices[i >> 2] = p;
    }
}

long long calculate_total_cost(int n) {
    long long total_cost = 0;

    for (int i = 0; i < (n >> 2); ++i) {
        long long *a = (long long*)&amounts[i];
        long long *p = (long long*)&prices[i];
        total_cost += a[0] * p[0];
        total_cost += a[1] * p[1];
        total_cost += a[2] * p[2];
        total_cost += a[3] * p[3];
    }

    for (int i = (n & ~3); i < n; ++i) {
        total_cost += ((long long*)&amounts[i >> 2])[i & 3] * (i + 1);
    }

    return total_cost;
}

int main() {
    // 輸入 n 和購買數量
    scanf("%d", &n);

    // 初始化購買數量向量
    int num_blocks = (n + 3) >> 2; // 每 4 個數據一個區塊
    for (int i = 0; i < num_blocks; ++i) {
        long long temp[4] = {0, 0, 0, 0};
        for (int j = 0; j < 4 && (i * 4 + j) < n; ++j) {
            scanf("%lld", &temp[j]);
        }
        amounts[i] = _mm256_set_epi64x(temp[3], temp[2], temp[1], temp[0]);
    }

    // 初始化價格
    init_prices(n);

    // 計算總成本並輸出
    printf("%lld\n", calculate_total_cost(n));

    return 0;
}
