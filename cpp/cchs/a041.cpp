#include <cstdio>
#include <immintrin.h>
#pragma GCC optimize("Ofast,fast-math")
#pragma GCC target("avx,avx2")

#define MAX_N 50000
#define MAX_Q 200000

int n, q;
int salaries[MAX_N];

// 查詢區間最大值與最小值的差
long long calculate_max_min_diff(int a, int b) {
    int max_salary = -1;
    int min_salary = 1 << 30;

    // 遍歷查詢區間，並使用 AVX2 並行處理 4 個元素
    for (int i = a; i <= b; i += 4) {
        // 如果區間剩餘不足 4 個元素，則單獨處理這部分
        if (i + 3 <= b) {
            __m256i data = _mm256_loadu_si256((__m256i*)&salaries[i]);
            __m256i max_val = _mm256_set1_epi32(-1);  // 初始最大值
            __m256i min_val = _mm256_set1_epi32(1 << 30);  // 初始最小值

            // 計算最大值和最小值
            max_val = _mm256_max_epi32(max_val, data);
            min_val = _mm256_min_epi32(min_val, data);

            int max_arr[4], min_arr[4];
            _mm256_storeu_si256((__m256i*)max_arr, max_val);
            _mm256_storeu_si256((__m256i*)min_arr, min_val);

            // 提取最大最小值
            for (int j = 0; j < 4; ++j) {
                if (max_arr[j] > max_salary) max_salary = max_arr[j];
                if (min_arr[j] < min_salary) min_salary = min_arr[j];
            }
        } else {
            // 處理剩餘不足 4 個元素的部分
            for (int j = i; j <= b; ++j) {
                if (salaries[j] > max_salary) max_salary = salaries[j];
                if (salaries[j] < min_salary) min_salary = salaries[j];
            }
        }
    }

    return (long long)(max_salary - min_salary);
}

int main() {
    // 輸入員工數量和查詢次數
    scanf("%d %d", &n, &q);

    // 輸入員工的薪水
    for (int i = 0; i < n; ++i) {
        scanf("%d", &salaries[i]);
    }

    // 處理每一個查詢
    for (int i = 0; i < q; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; b--;  // 轉換為 0 基索引
        printf("%lld\n", calculate_max_min_diff(a, b));
    }

    return 0;
}
