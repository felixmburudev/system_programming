#include<stdio.h>
#include<string.h>

// /**
//  * @file main.c
//  * @brief A simple C program demonstrating file operations.
//  * @author felix mburu
//  * @date 2025-03-11
//  */
// /**//+
//  * @brief Main function of the program.//+
//  *//+
//  * This function demonstrates the usage of file operations in C.//+
//  * It reads a string into a buffer, writes the buffer content to a file,//+
//  * and then reads the content from the file and prints it to the console.//+
//  *//+
//  * ?@return 0 on successful execution, non-zero otherwise.//+
//  *///+
int main() {
    char buff[30];
    strcpy(buff, "waiting for the day to come");
    FILE *file = fopen("example.txt", "w");
    fprintf(file, "%s", buff);
    fclose(file);
    FILE *filer = fopen("example.txt", "r");
    fgets(buff, 30, filer);
    // fscanf(filer, "%s", buff);
    printf("File content: %s", buff);
    fclose(filer);
    return 0;
}