#include <stdio.h>
#include <stdlib.h>

#define RESULT 200

void findExpression(int* arr, int size, int number, int interResult){
    if(number < 0) {
        if(interResult == RESULT) {
            for(int i = 0; i < size; ++i) {
                printf("%c%d", arr[i] >= 0 ? '+' : '-', abs(arr[i]));
            }
            printf(" = 200\n");
        }
        return;
    }
    arr[size++] = number;
    findExpression(arr, size, number - 1 , interResult + arr[size - 1]);
    arr[size - 1] = -number;
    findExpression(arr, size, number - 1, interResult + arr[size - 1]);
    if(size > 1) {
        size--;
        interResult -= arr[size - 1];
        if(arr[size - 1] > 0) {
            arr[size - 1] *= 10;
            arr[size - 1] += number;
        }
        else {
            arr[size - 1] *= 10;
            arr[size - 1] -= number;
        }
    }
    findExpression(arr, size, number - 1, interResult + arr[size - 1]);
    arr[size - 1] /= 10;
}


int main() {
    int *arr;
    arr = malloc(100 * sizeof(int));;
    findExpression(arr, 0, 9, 0);
    free(arr);
    return 0;
}
