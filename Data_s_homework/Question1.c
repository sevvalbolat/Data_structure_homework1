/*Write a function that adds all odd numbers to the beginning of the
 list and all even numbers to the end of the list until -1 is 
 entered from the keyboard.*/

#include <stdio.h>

void odd_even_sort(int *arr, int n) {
    int start = 0, end = n - 1;
    while (start < end) {
        // move the start pointer towards right until an odd number is found
        while (arr[start] % 2 == 1 && start < end)
            start++;

        // move the end pointer towards left until an even number is found
        while (arr[end] % 2 == 0 && start < end)
            end--;

        // if start is still less than end, we found an odd number at start and an even number at end. Swap them.
        if (start < end) {
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
        }
    }
}

int main() {
    int n, num;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];

    for (int i = 0; i < n; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &num);
        if (num == -1)
            break;
        arr[i] = num;
    }

    odd_even_sort(arr, n);

    printf("The rearranged list is: \n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}

