#include <stdio.h>

void matrix_chain_multiplication(int arr[], int n) {
	int i, j, l, k,m, q;
	printf("ENTER THE SIZE OF THE MATRIX: ");
	scanf("%d",&m);
	int min_mul[m+1][m+1];
	
	for(i = 1; i < m+1; i++) {
		for(j = 1; j < m+1; j++) {
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
	
	for(i = 1; i < m+1; i++) {
		for(j = 1; j < m+1; j++) {
			printf("%2d ", min_mul[i][j]);
		}
		printf("\n");
	}
}

int main(void) {
	int n;
	printf("ENTER THE NUMBER OF MATRIX: ");
	scanf("%d",&n);
	int arr[n+1];
	printf("ENTER THE DIMENSIONS OF THE MATRIX: ");
	for(int i=0; i<=n; i++){
		scanf("%d",&arr[i]);
	}
	matrix_chain_multiplication(arr, n+1);
}