#include <stdio.h>
#include <stdlib.h>

struct Item {
    int value;
    int weight;
    float ratio;
};

void main() {
    int n, W;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    struct Item items[n];
    printf("Enter the maximum weight of the knapsack: ");
    scanf("%d", &W);

    for (int i = 0; i < n; i++) {
        printf("Item %d - Weight: ", i+1);
        scanf("%d", &items[i].weight);
        printf("Item %d - profit: ", i+1);
        scanf("%d", &items[i].value);
        items[i].ratio = (items[i].weight == 0) ? 0 : (float)items[i].value / items[i].weight;
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (items[j].ratio < items[j + 1].ratio) {
                struct Item temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }

    float totalValue = 0.0f, currentWeight = 0.0f;


    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= W) {
            currentWeight += items[i].weight;
            totalValue += items[i].value;
        } else {
            int remainingWeight = W - currentWeight;
            totalValue += items[i].value * ((float)remainingWeight / items[i].weight);
            break;
        }
    }

    printf("Maximum value : %.2f\n", totalValue);

}

