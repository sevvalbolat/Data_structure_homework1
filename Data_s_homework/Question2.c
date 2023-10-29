/*Add 100 randomly generated numbers to the list,
write the c code that sorts all the numbers 
entered from largest to smallest and prints them 
on the screen.*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sort(int *arr, int n) {
    int i, j, max, temp;
    for (i = 0; i < n - 1; i++) {
        max = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] > arr[max])
                max = j;
        }
        temp = arr[i];
        arr[i] = arr[max];
        arr[max] = temp;
    }
}

int main() {
    int i, n;
    int num[100];
    srand((unsigned int) time(NULL));

    printf("Enter the number of elements (max 100): ");
    scanf("%d", &n);

    if (n < 1 || n > 100) {
        printf("Invalid input. Number of elements should be between 1 and 100.\n");
        return 1; // Exit with an error code
    }

    for (i = 0; i < n; i++) {
        num[i] = rand() % 1000 + 1;
    }

    sort(num, n);

    printf("The rearranged list is: \n");
    for (i = 0; i < n; i++)
        printf("%d ", num[i]);

    return 0;
}
