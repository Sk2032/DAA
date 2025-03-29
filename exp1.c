#include <stdio.h>


void findMinMax(int arr[], int n, int *max, int *min) {
    *max = arr[0];
    *min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > *max)
            *max = arr[i];
        if (arr[i] < *min)
            *min = arr[i];
    }
}

int main() {
    int arr[10],w;
    printf("Enter array Size: ");
    scanf("%d", &w);

    printf("Enter array elements: ");
    for(int i=0;i<w;i++)
        {
          scanf("%d",&arr[i]);
        }

    int max, min;
    findMinMax(arr, w, &max, &min);

    printf("max %d\n", max);
    printf("min %d\n", min);
    return 0;
}
