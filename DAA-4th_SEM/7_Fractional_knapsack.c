#include <stdio.h>


struct Item {
    int weight;
    int value;
};


int compare(const void *a, const void *b) {
    double ratio1 = (double)(((struct Item *)b)->value) / ((struct Item *)b)->weight;
    double ratio2 = (double)(((struct Item *)a)->value) / ((struct Item *)a)->weight;
    return ratio1 > ratio2 ? 1 : -1;
}


void fractionalKnapsack(int knapsackCapacity, struct Item items[], int numItems) {
   
    qsort(items, numItems, sizeof(items[0]), compare);

    int currentWeight = 0; 
    double totalValue = 0.0;
	int i; 

    
    for (i = 0; i < numItems; i++) {
        
        if (currentWeight + items[i].weight <= knapsackCapacity) {
            currentWeight += items[i].weight;
            totalValue += items[i].value;
        } else {
            
            int remainingCapacity = knapsackCapacity - currentWeight;
            totalValue += ((double)remainingCapacity / items[i].weight) * items[i].value;
            break;
        }
    }

    printf("Maximum value that can be obtained: %.2lf\n", totalValue);
}

int main() {
    int numItems, knapsackCapacity;
    int i;

    printf("Enter the number of items: ");
    scanf("%d", &numItems);

    struct Item items[numItems];

   
    for (i = 0; i < numItems; i++) {
        printf("Enter weight and value of item %d: ", i + 1);
        scanf("%d %d", &items[i].weight, &items[i].value);
    }

    printf("Enter the knapsack capacity: ");
    scanf("%d", &knapsackCapacity);

    fractionalKnapsack(knapsackCapacity, items, numItems);

    return 0;
}