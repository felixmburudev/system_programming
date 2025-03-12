#include <unistd.h>
#include <stdlib.h>
/**
 * @brief Writes an integer to the standard output in decimal format.
 *
 * This function converts an integer to a string and writes it to the standard output.
 * If the integer is negative, it is written as a negative number.
 *
 * @param num The integer to be written.
 *
 * @return void
 */
void write_int(int num) {
    char buffer[20];
    int length = 0;

    if (num == 0) {
        buffer[length++] = '0';
    } else {
        if (num < 0) {
            write(STDOUT_FILENO, "-", 1);
            num = -num;
        }
        int temp = num;
        while (temp > 0) {
            buffer[length++] = '0' + (temp % 10);
            temp /= 10;
        }
    }
    for (int i = length - 1; i >= 0; i--) {
        write(STDOUT_FILENO, &buffer[i], 1);
    }
}

/**
 * @brief The main function of the program.
 *
 * This function reads an array size from the standard input, dynamically allocates memory for the array,
 * reads integers from the standard input, and prints them to the standard output.
 *
 * @return 0 if the program runs successfully, 1 if an error occurs.
 */
int main() {

    int size;
    write(STDOUT_FILENO, "Enter array size: ", 18);
    char size_buffer[20];
    int bytes_read = read(STDIN_FILENO, size_buffer, sizeof(size_buffer));
    if (bytes_read <= 0) {
        write(STDERR_FILENO, "Failed to read input.\n", 22);
        return 1;
    }
    size = 0;
    for (int i = 0; i < bytes_read && size_buffer[i] >= '0' && size_buffer[i] <= '9'; i++) {
        size = size * 10 + (size_buffer[i] - '0');
    }
    int* array = (int*)malloc(size * sizeof(int));
    if (array == (void*)-1) {
        write(STDERR_FILENO, "Memory allocation failed!\n", 26);
        return 1;
    }
    write(STDOUT_FILENO, "Enter ", 6);
    write_int(size);
    write(STDOUT_FILENO, " integers:\n", 11);
    for (int i = 0; i < size; i++) {
        char num_buffer[20];
        bytes_read = read(STDIN_FILENO, num_buffer, sizeof(num_buffer));
        if (bytes_read <= 0) {
            write(STDERR_FILENO, "Failed to read input.\n", 22);
            free(array); 
            return 1;
        }
        array[i] = 0;
        for (int j = 0; j < bytes_read && num_buffer[j] >= '0' && num_buffer[j] <= '9'; j++) {
            array[i] = array[i] * 10 + (num_buffer[j] - '0');
        }
    }
    write(STDOUT_FILENO, "You entered:\n", 13);
    for (int i = 0; i < size; i++) {
        write_int(array[i]);
        write(STDOUT_FILENO, " ", 1);
    }
    write(STDOUT_FILENO, "\n", 1);
    free(array);
    return 0;
}
