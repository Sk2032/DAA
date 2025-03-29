#include <stdio.h>

void findSubsets(int arr[], int subset[], int n, int index, int sum, int target) {
    if (sum == target) {
        printf("{ ");
        for (int i = 0; i < index; i++)
            printf("%d ", subset[i]);
        printf("}\n");
        return;
    }

    for (int i = index; i < n; i++) {
        if (sum + arr[i] <= target) {
            subset[index] = arr[i];
            findSubsets(arr, subset, n, index + 1, sum + arr[i], target);
        }
    }
}

void main() {
    int n, target;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n], subset[n];
    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter target sum: ");
    scanf("%d", &target);

    printf("Subsets with sum %d:\n", target);
    findSubsets(arr, subset, n, 0, 0, target);
}
