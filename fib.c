#include <stdio.h>
#include <stdlib.h>

// Iterative method for fibonacci
long iterative(int cycles) {
    
    // Initialize variables
    long x = 0;
    long y = 1;
    long z = 1;
    
    for(int i = 0; i < cycles-2; i++) {
        x = y;
        y = z;
        z = x + y;
    }
    return z;
}

// Recursive method for fibonacci
long recursive(long cycles) {
    if(cycles == 0 || cycles == 1)
        return cycles;

    return recursive(cycles-1) + recursive(cycles-2);
}

int main(int argc, char **argv) {
    // Initialize variables
    auto FILE* fptr;
    char* fileName = argv[3];
    int firstInteger = *(argv[1]) - '0';
    int fileInteger;
    int N;
    int nthFibonacciNumber;
    char recursiveOrIterate = *(argv[2]);
    // Ask user for initial integer

    /*
    printf("Enter an integer: ");
    scanf("%d%*c", &firstInteger);
    printf("Your integer was %d\n\n", firstInteger);

    // Ask user for iterative or recursive commands
    printf("Enter i or r: ");
    scanf("%c", &recursiveOrIterate);
    printf("You chose %c\n\n", recursiveOrIterate);

    // Ask user for file name
    printf("Enter file name: ");
    scanf("%s", fileName);

    */

    fptr = fopen(fileName, "r");
    if (fptr == NULL) {  
        perror("Error opening the file");  
        return 0;  
    }  
    fileInteger = fscanf(fptr, "%s", fileName);
    fileInteger = atoi(fileName);
    //printf("The number in file was %d\n\n", fileInteger);
    N = fileInteger + firstInteger;
    // printf("N is: %d\n", N);
    N -= 1;
    // Run iterative or recursive methods
    if(recursiveOrIterate == 'i')
        nthFibonacciNumber = iterative(N);
    else
        nthFibonacciNumber = recursive(N);

    printf("%ld", nthFibonacciNumber);
    
    return nthFibonacciNumber;
}