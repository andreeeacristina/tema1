#include <stdio.h>

int solve_sums(int n, int *v) {
    int dp[n][3];
    dp[0][0] = 0;
    dp[0][1] = 0;
    dp[0][2] = 0;

    int sum_0 = 0;
    int sum_1 = 0;
    int sum_2 = 0;
    int i;
    for(i=0; i < n; ++i) {
        if(v[i] % 3 == 0) {
            dp[i][0] = 1;
            dp[i][1] = 0;
            dp[i][2] = 0;
        } else if(v[i] % 3 == 1) {
            dp[i][0] = 0;
            dp[i][1] = 1;
            dp[i][2] = 0;
        } else
        {
            dp[i][0] = 0;
            dp[i][1] = 1;
            dp[i][2] = 0;
        }

        dp[i][0] = dp[i][0] + sum_0;
        dp[i][1] = dp[i][1] + sum_1;
        dp[i][2] = dp[i][2] + sum_2;
        sum_0 = sum_0 + dp[i][0];
        sum_1 = sum_1 + dp[i][1];
        sum_2 = sum_2 + dp[i][2];
    }
    printf( "%d", sum_0);
    return 0;
}