#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100

struct Item {
    int weight;
    int value;
};

int max(int a, int b) {
    return (a > b) ? a : b;
}

float bound(int level, int weight, int n, int W, struct Item arr[]) {
    float profit_bound = 0;
    int totweight = weight;
    for (int j = level + 1; j < n && totweight <= W; ++j) {
        if (totweight + arr[j].weight <= W) {
            totweight += arr[j].weight;
            profit_bound += arr[j].value;
        } else {
            profit_bound += (W - totweight) * arr[j].value / arr[j].weight;
        }
    }
    return profit_bound;
}

int knapsack(int W, struct Item arr[], int n) {
    int maxProfit = 0;
    struct Node {
        int level;
        int profit;
        int weight;
        float bound;
    } u, v;
    u.level = -1;
    u.profit = u.weight = 0;
    u.bound = bound(u.level, u.weight, n, W, arr);
    struct Node *Q = (struct Node*)malloc(sizeof(struct Node) * MAX_ITEMS);
    int front = -1, rear = -1;
    Q[++rear] = u;
    while (front != rear) {
        u = Q[++front];
        if (u.level == n - 1)
            continue;
        v.level = u.level + 1;
        v.weight = u.weight + arr[v.level].weight;
        v.profit = u.profit + arr[v.level].value;
        if (v.weight <= W && v.profit > maxProfit)
            maxProfit = v.profit;
        v.bound = bound(v.level, v.weight, n, W, arr);
        if (v.bound > maxProfit)
            Q[++rear] = v;
        v.weight = u.weight;
        v.profit = u.profit;
        v.bound = bound(v.level, v.weight, n, W, arr);
        if (v.bound > maxProfit)
            Q[++rear] = v;
    }
    free(Q);
    return maxProfit;
}

int main() {
    int W = 50;
    struct Item arr[] = {{10, 60}, {20, 100}, {30, 120}};
    int n = sizeof(arr) / sizeof(arr[0]);
    int maxProfit = knapsack(W, arr, n);
    printf("Maximum profit: %d\n", maxProfit);
    return 0;
}
