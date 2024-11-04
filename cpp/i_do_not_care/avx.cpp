#pragma GCC optimize("Ofast,fast-math")
#pragma GCC target("avx,avx2")
#include <cstdio>
#include <immintrin.h>

int n, m, l, r;
__m256i a[25010];

// 初始化数据
inline void init_data() {
    for (int i = 0; i < (n + 3) / 4; ++i) {
        int x[4] = {0, 0, 0, 0};  // 暂存读取的4个元素，初始为0
        for (int j = 0; j < 4 && i * 4 + j < n; ++j) {
            scanf("%d", &x[j]);
        }
        a[i] = _mm256_set_epi64x(x[3], x[2], x[1], x[0]);
    }
}

// 使用暴力方法计算区间 [l, r] 的和
inline long long query(int l, int r) {
    long long ans = 0;
    
    // 对齐到4的边界
    while ((l & 3) && l <= r) {
        ans += ((long long*)&a[l / 4])[(l % 4)];
        ++l;
    }
    
    // 以4元素为单位累加
    __m256i sum = _mm256_setzero_si256();
    while (l + 3 <= r) {
        sum = _mm256_add_epi64(sum, a[l / 4]);
        l += 4;
    }
    
    // 累加 sum 寄存器中的4个元素到 ans
    long long temp[4];
    _mm256_storeu_si256((__m256i*)temp, sum);
    for (int i = 0; i < 4; ++i) {
        ans += temp[i];
    }
    
    // 处理剩余的元素
    while (l <= r) {
        ans += ((long long*)&a[l / 4])[(l % 4)];
        ++l;
    }
    
    return ans;
}

int main() {
    scanf("%d%d", &n, &m);
    
    // 初始化数组
    init_data();
    
    // 处理每个查询
    while (m--) {
        scanf("%d%d", &l, &r);
        --l; --r;  // 将输入的 1-based 索引转换为 0-based
        printf("%lld\n", query(l, r)%10009);
    }
    
    return 0;
}