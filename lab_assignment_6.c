#include <stdio.h>
#include <stdlib.h>

int search(int numbers[], int low, int high, int value) {
    if (low > high)
        return -1;

    int mid = low + (high - low) / 2;

    if (numbers[mid] == value)
        return mid;
    else if (numbers[mid] < value)
        return search(numbers, mid + 1, high, value);
    else
        return search(numbers, low, mid - 1, value);
}

void printArray(int numbers[], int sz) {
    printf("Number array : ");
    for (int i = 0; i < sz; ++i) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
}

int main(void) {
    int numInputs;
    FILE* inFile = fopen("input.txt", "r");

    fscanf(inFile, "%d", &numInputs);
    
    while (numInputs-- > 0) {
        int countOfNums;
        fscanf(inFile, "%d", &countOfNums);
        int* numArray = (int *)malloc(countOfNums * sizeof(int));
        float average = 0;

        for (int i = 0; i < countOfNums; i++) {
            fscanf(inFile, "%d", &numArray[i]);
            average += numArray[i];
        }

        printArray(numArray, countOfNums);
        int value = average / countOfNums;
        int index = search(numArray, 0, countOfNums - 1, value);

        if (index >= 0) {
            printf("Item %d exists in the number array at index %d!\n", value, index);
        } else {
            printf("Item %d does not exist in the number array!\n", value);
        }

        free(numArray);
    }

    fclose(inFile);
    return 0;
}
