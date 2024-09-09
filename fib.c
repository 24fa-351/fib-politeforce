#include <stdio.h>
#include <stdlib.h>

int iterative(int cycles) {
   int x = 0;
   int y = 1;
   int z = 1;

   for(int i = 0; i < cycles-2; i++) {
      x = y;
      y = z;
      z = x + y;
   }
   return z;
}

int recursive(int cycles) {
   if(cycles == 0 || cycles == 1)
      return cycles;
   return recursive(cycles - 1) + recursive(cycles - 2);
}


int main(int argc, char *argv[]) {
   auto FILE* fptr;
   char fileName[100];
   int firstInteger;
   int numInFile;
   int n;
   int nthFibNum;
   char rorI;
   
   printf("Please insert an integer: ");
   scanf("%d%*c", &firstInteger);
   printf("Your integer was %d\n\n", firstInteger);
   
   printf("Please insert either \"r\" or \"i\": ");
   scanf("%c", &rorI);
   printf("You chose %c\n\n", rorI); 

   printf("Please insert the file name: ");
   scanf("%s", fileName);
   fptr = fopen(fileName, "r");
   if (fptr = NULL) {
      perror("Error opening file");
      return 1;
   }

   numInFile = fscanf(fptr, "%s", fileName);
   numInFile = atoi(fileName);
   printf("The number in the file was %d\n\n", numInFile);
   n = numInFile + firstInteger;
   printf("N is %d\n", n);
   
   if(rorI == 'i')
      nthFibNum = iterative(n);
   else
      nthFibNum = recursive(n);

   printf("Your nth Fibonacci number is: %d\n", nthFibNum);
   
   return 0;
}
