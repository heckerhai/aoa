#include <stdio.h>

int n = 3;
int weight[10] = {18, 15, 10};
int value[10] = {25, 24, 15};
int capacity = 20;

void simple_fill() {
    int used[10] = {0};
    int cur_w = capacity;
    float total_value = 0.0;

    while (cur_w > 0) {
        int max = -1;

        // Find the item with the best value/weight ratio
        for (int i = 0; i < n; i++) {
            if (!used[i] && (max == -1 || 
                (float)value[i] / weight[i] > (float)value[max] / weight[max])) {
                max = i;
            }
        }

        used[max] = 1;
        cur_w -= weight[max];
        total_value += value[max];

        if (cur_w >= 0)
            printf("Added item %d (%d$, %dKg). Space left: %d.\n",
                   max + 1, value[max], weight[max], cur_w);
        else {
            float fraction = 1 + (float)cur_w / weight[max];
            printf("Added %.0f%% of item %d (%d$, %dKg).\n",
                   fraction * 100, max + 1, value[max], weight[max]);
            total_value -= value[max];
            total_value += value[max] * fraction;
            break;
        }
    }

    printf("Total value in bag: %.2f$\n", total_value);
}

int main() {
    simple_fill();
    return 0;
}
