#include <stdio.h>


                                        //Iterative Approach
int iterative(int n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else if (n == 2)
        return 2;

    int a = 0, b = 1, c = 2, i;
    int result;
    for (i = 3; i <= n; i++) {
        result = a + b;
        a = b;
        b = c;
        c = result;
    }
    return result;
}

int main() {
    int n = 10;
    int result = iterative(n);
    printf("F(%d) = %d\n", n, result);
    return 0;
}


                                      //Recursive Approach
int recursive(int n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else if (n == 2)
        return 2;
    else
        return recursive(n - 3) + recursive(n - 2);
}

int main() {
    int n = 10;
    int result = recursive(n);
    printf("F(%d) = %d\n", n, result);
    return 0;
}

                                      //Memoization Approach
#define MAXN 100
int memo[MAXN];

int memoization(int n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else if (n == 2)
        return 2;

    if (memo[n] != -1)
        return memo[n];

    memo[n] = memoization(n - 3) + memoization(n - 2);
    return memo[n];
}

int main() {
    int n = 10;
    for (int i = 0; i < MAXN; i++) {
        memo[i] = -1;
    }
    int result = memoization(n);
    printf("F(%d) = %d\n", n, result);
    return 0;
}
