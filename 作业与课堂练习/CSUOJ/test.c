#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
   char *str = (char *) malloc(15);
   str = (char *) calloc(15,sizeof(char));
   strcpy(str, "tutorialspoint");
   free(str);
   return 0;
}