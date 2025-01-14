#include <stdio.h>
#include <stdlib.h>
 
// This program prints the size of a specified file in bytes
int main(int argc, char** argv) {
    // Ensure that the user supplied exactly one command line argument
    if (argc != 2) { 
        fprintf(stderr, "Please provide the address of a file as an input.\n");
        return -1;
    }

    // Open the file in read mode
    FILE *file = fopen(argv[1], "rb");
    if (file == NULL) {
        perror("Error opening file");
        return -1;
    }

    // Determine the size of the file
    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);


    fclose(file);

    if (fileSize == -1) {
        perror("Error determining file size");
        return -1;
    }

    printf("File size: %ld bytes\n", fileSize);
    return 0;
}
