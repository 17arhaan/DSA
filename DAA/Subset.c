#include <stdio.h>

#define MAX_SIZE 100

int count = 0;

void subsetSum(int set[], int n, int target, int sum, int index, int subset[]) {
    if (sum == target) {
        printf("Subset %d: ", ++count);
        for (int i = 0; i < index; ++i)
            printf("%d ", subset[i]);
        printf("\n");
        return;
    }
    if (sum > target || index == n)
        return;
    subset[index] = set[index];
    subsetSum(set, n, target, sum + set[index], index + 1, subset);
    subsetSum(set, n, target, sum, index + 1, subset);
}

int main() {
    int set[] = {1, 2, 5, 6, 8};
    int n = sizeof(set) / sizeof(set[0]);
    int target = 9;
    int subset[MAX_SIZE];
    subsetSum(set, n, target, 0, 0, subset);
    if (count == 0)
        printf("No subset found with sum equal to %d.\n", target);
    return 0;
}
