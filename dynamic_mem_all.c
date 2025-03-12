#include <stdio.h>
#include <stdlib.h> 
// /**
//  * @brief This is the main function of the program. It demonstrates dynamic memory allocation in C.
//  *
//  * @return 0 if the program runs successfully, 1 if memory allocation fails.
//  */
int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    /**
     * @brief Dynamically allocate memory for an array of integers.
     *
     * @param size The number of integers to allocate memory for.
     * @return A pointer to the allocated memory, or NULL if allocation fails.
     */
    int* array = (int*)malloc(size * sizeof(int));

    if (array == NULL) {
        printf("Memory allocation failed!\n");
        return 1; 
    }

    printf("Enter %d integers:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }

    printf("You entered:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }

    printf("\n");
    free(array);
    return 0;
}
