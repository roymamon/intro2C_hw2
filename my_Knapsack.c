#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
#define itemslength 5
#define knapsacksize 20

int knapSack(int[], int[], int[]);


int main(){

    char* strings[itemslength];
    int weights[itemslength];
    int values[itemslength];
    int selected_bool[itemslength] = {0};
    
    for (int i = 0; i < itemslength; i++) {
        strings[i] = (char*)malloc(2 * sizeof(char));  
    }


    /*
    algorithm based on how we were taught
    in algorithms 1 course, building a table
    by considering if we should take or not take
    a certain item.
    */
    int knapSack(int weights[], int values[], int selected_bool[]) {
    int i, w;

    int knap[itemslength + 1][knapsacksize + 1];

    for (i = 0; i <= itemslength; i++) {
        for (w = 0; w <= knapsacksize; w++) {
            if (i == 0 || w == 0)
                knap[i][w] = 0;
            else if (weights[i - 1] <= w) {
                int withItem = values[i - 1] + knap[i - 1][w - weights[i - 1]];
                int withoutItem = knap[i - 1][w];

                if (withItem > withoutItem) {
                    knap[i][w] = withItem;
                    selected_bool[i - 1] = 1;  

                } else {
                    knap[i][w] = withoutItem;

                }
            } else {
                knap[i][w] = knap[i - 1][w];
            }
        }
    }
    
    //printing selected_bool
    char* selected_items[itemslength];
    for (int i = 0; i < itemslength; i++) {
        selected_items[i] = NULL;
    }

    int s = knapsacksize;
    int res = knap[itemslength][knapsacksize];

    for (int i = itemslength; i > 0 && res > 0; i--) {
        if (res == knap[i - 1][s]) {
            continue;
        } else {
            selected_items[i - 1] = (char*)malloc(2 * sizeof(char));
            strcpy(selected_items[i - 1], strings[i - 1]);
            s -= weights[i - 1];
            res -= values[i - 1];
        }
    }

    printf("Maximum profit: %d\n", knap[itemslength][knapsacksize]);
    printf("Selected items:");
    for (int i = 0; i < itemslength; i++) {
        if (selected_items[i] != NULL) {
            printf(" %s", selected_items[i]);
            free(selected_items[i]);  
        }
    }

        return knap[itemslength][knapsacksize];

}
    
    //scanning from the user
    for (int i = 0; i < itemslength; i++) {
        scanf("%s", strings[i]);
        scanf("%d", &values[i]);
        scanf("%d", &weights[i]);
    }

    knapSack(weights, values, selected_bool);

    for (int i = 0; i < itemslength; i++) {
        if (selected_bool[i] == 1) {
        }
    }


  for (int i = 0; i < itemslength; i++) {
        free(strings[i]);
    }

}