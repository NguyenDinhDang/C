#include <stdio.h>

void outputArr(int n, int a[]);
void swap(int *a, int *b);

void quickSort(int a[], int n, int left, int right);

void selectionSort(int a[], int n, long long *cmp, long long *swp);
void insertionSort(int a[], int n, long long *cmp, long long *mve);
void bubbleSort(int a[], int n, long long *cmp, long long *swp);
void interChangeSort(int a[], int n, long long *cmp, long long *swp);

void heapSort(int a[], int n, long long *cmp, long long *swp);
void shift(int a[], int l, int r, long long *cmp, long long *swp);

int main() {
    int n = 8;
    int left = 1;
    int right = n;

    long long cmp, swp;

    printf("\n Quick Sort \n");
    {
        int arr[] = {0, 9, 19, -3, 5, -12, 22, 17, 20};
        quickSort(arr, n, left, right);
    }

    printf("\n\n Selection Sort \n");
    {
        int arr[] = {0, 9, 19, -3, 5, -12, 22, 17, 20};
        selectionSort(arr, n, &cmp, &swp);
        printf("\nComparisons: %lld", cmp);
        printf("\nSwaps: %lld\n", swp);
    }

    printf("\n Heap Sort \n");
    {
        int arr[] = {0, 9, 19, -3, 5, -12, 22, 17, 20};
        heapSort(arr, n, &cmp, &swp);
        printf("\nComparisons: %lld", cmp);
        printf("\nSwaps: %lld\n", swp);
    }

    printf("\n Bubble Sort \n");
    {
        int arr[] = {0, 9, 19, -3, 5, -12, 22, 17, 20};
        bubbleSort(arr, n, &cmp, &swp);
        printf("\nComparisons: %lld", cmp);
        printf("\nSwaps: %lld\n", swp);
    }

    printf("\n Insertion Sort \n");
    {
        int arr[] = {0, 9, 19, -3, 5, -12, 22, 17, 20};
        insertionSort(arr, n, &cmp, &swp);
        printf("\nComparisons: %lld", cmp);
        printf("\nSwap: %lld\n", swp);
    }

    printf("\n Interchange Sort \n");
    {
        int arr[] = {0, 9, 19, -3, 5, -12, 22, 17, 20};
        interChangeSort(arr, n, &cmp, &swp);
        printf("\nComparisons: %lld", cmp);
        printf("\nSwaps: %lld\n", swp);
    }

    return 0;
}

void inputArr(int a, int arr[]) {
    for (int i = 0; i < a; i++) {
        scanf("%d", &arr[i]);
    }
}

void outputArr(int n, int a[]) {
    for (int i = 1; i <= n; i++) { 
        printf("%d ", a[i]);
    }
}
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void linearSearch(int a, int arr[], int key) {
    for (int i = 0; i < a; i++) {
        if (arr[i] == key) printf("Found in Array[%d]\n", i + 1);
        else printf("Not found in Array[%d]\n", i + 1);
    }
}

void selectionSort(int a[], int n, long long *cmp, long long *swp) {
	*cmp = 0; *swp = 0;
	for (int i = 1; i < n; i++) {
		int min = i;
		for (int j = i + 1; j <= n; j++) {
			(*cmp)++;
			if (a[j] < a[min]) min = j;
		}
		swap(&a[min], &a[i]);
		(*swp)++;
		printf("Buoc %d: ", i);
        outputArr(n, a);
        printf("\n");
	}
}

void interChangeSort(int a[], int n, long long *cmp, long long *swp) {
	*cmp = 0; *swp = 0;
	for (int i = 1; i < n; i++) {
		for (int j = i + 1; j <= n; j++) {
			(*cmp)++;
			if (a[j] < a[i]) {
				swap(&a[i], &a[j]);
				(*swp)++;
			}
		}
		printf("Buoc %d: ", i);
        outputArr(n, a);
        printf("\n");
	}
}

void bubbleSort(int a[], int n, long long *cmp, long long *swp) {
	*cmp = 0; *swp = 0;
	for (int i = 1; i < n; i++) {
		for (int j = n; j > i; j--) {
			(*cmp)++;
			if (a[j] < a[j - 1]) {
				swap(&a[j], &a[j - 1]);
				(*swp)++;
			}
		}
		printf("Buoc %d: ", i);
        outputArr(n, a);
        printf("\n");
	}
}

void insertionSort(int a[], int n, long long *cmp, long long *mve) {
	*cmp = 0; *mve = 0;
	for (int i = 2; i <= n; i++) {
		int x = a[i];
		(*mve)++;
		int j = i - 1;
		while (j >= 1) {
			(*cmp)++;
			if (a[j] > x) {
				a[j + 1] = a[j];
				(*mve)++;
				j--;
			} else break;
		}
		a[j + 1] = x;
		(*mve)++;
		printf("Buoc %d: ", i);
        outputArr(n, a);
        printf("\n");
	}
}

void shift(int a[], int l, int r, long long *cmp, long long *swp) {
	int i = l, j = 2 * i;
	int x = a[i];
	while (j <= r) {
	if (j < r) {
		(*cmp)++;
		if (a[j] < a[j + 1]) j++;
		}
		(*cmp)++;
		if (a[j] <= x) break;
		a[i] = a[j];
		i = j; j = 2 * i;
	}
	a[i] = x;
}

void heapSort(int a[], int n, long long *cmp, long long *swp) {
	*cmp = 0; *swp = 0;
	for (int l = n / 2; l >= 1; l--) {
		shift(a, l, n, cmp, swp);
	}
	int r = n;
	while (r > 1) {
		swap(&a[1], &a[r]);
		(*swp)++;
		r--;
		shift(a, 1, r, cmp, swp);
		printf("Buoc %d: ", r);
        outputArr(n, a);
        printf("\n");
	}
}
void quickSort(int a[], int n, int left, int right) {
    int i = left;
    int j = right;
    int pivot = a[(left + right) / 2];

    while (i <= j) {
        while (a[i] < pivot) i++;
        while (a[j] > pivot) j--;

        if (i <= j) {
            swap(&a[i], &a[j]);
            i++;
            j--;
        }
        printf("Buoc %d: ", i);
        outputArr(n, a);
        printf("\n");
    }

    if (left < j)
        quickSort(a, n, left, j);

    if (i < right)
        quickSort(a, n, i, right);
}