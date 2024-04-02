#include <stdio.h>

void matrix_chain_multiplication(int arr[], int n) {
	int i, j, l, k, q;
	int min_mul[4][4];
	
	for(i = 1; i < 4; i++) {
		for(j = 1; j < 4; j++) {
			if (i < j)
				min_mul[i][j] = 9999999;
            else
                min_mul[i][j]=0;
		}
	}
	
	for(i = 1; i <= n - 1; i++) {
		min_mul[i][i] = 0;
	}
	for(l = 2; l <= n - 1; l++) {
		for(i = 1; i <= n - l + 1; i++) {
			j = i + l - 1;
			min_mul[i][j] = 9999999;
			for(k = i; k <= j - 1; k++) {
				q = min_mul[i][k] + min_mul[k + 1][j] + (arr[i - 1] * arr[k] * arr[j]);
				if (q < min_mul[i][j]) {
					min_mul[i][j] = q;
				}
			}
		}
	}
	
	for(i = 1; i < 4; i++) {
		for(j = 1; j < 4; j++) {
			printf("%2d ", min_mul[i][j]);
		}
		printf("\n");
	}
}

int main(void) {
	int arr[] = {2, 3, 4, 2};
	int n = 4;
	matrix_chain_multiplication(arr, n);
}