#include <stdio.h>
#include "stdlib.h"

void trup(int n, int m, float M[n][m]) {
    for (int j = 0; j < n; j++) {
        int i = j;
        while (M[i][j] == 0)
            i = i + 1;
        for (int k = j; k < m; k++) {
            float c = M[i][k];
            M[i][k] = M[j][k];
            M[j][k] = c;
        }
        for (int t = j + 1; t < n; t++) {
            float h = -M[t][j] / M[j][j];
            for (int s = j; s < m; s++) {
                M[t][s] += h * M[j][s];
            }
        }

    }
}

void trdown(int n, int m, float M[n][m]) {
    for (int j = n - 1; j >= 0; j--) {
        int i = j;
        while (M[i][j] == 0)
            i = i - 1;
        for (int k = 0; k < m; k++) {
            float c = M[i][k];
            M[i][k] = M[j][k];
            M[j][k] = c;
        }
        for (int t = j - 1; t >= 0; t--) {
            float h = -M[t][j] / M[j][j];
            for (int s = 0; s < m; s++) {
                M[t][s] += h * M[j][s];
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    const int row=n, col = 2*n;
    float ma[row][col];

    int i, j;
    for (i = 0; i < n; i++)
        for (int k = 0; k < n; ++k)
            scanf("%f", &ma[i][k]);

    for (int f = 0; f < n; f++)
        for (int y = n; y < col; y++)
            if (y == f+n)
                ma[f][y] = 1;
            else
                ma[f][y] =0;

    trup(n, col, ma);
    trdown(n, col, ma);

    for (int k = 0; k < row; ++k) {
        float c=ma[k][k];
        for (int l = 0; l < col; ++l) {
            printf("%f ", ma[k][l]/c);
        }
        printf("\n");
    }

    return 0;
}