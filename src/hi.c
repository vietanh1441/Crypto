#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

int hex2int(char* hexStr) {
 char *offset; 
 return strtol(hexStr, &offset, 16);
}


int main( ) {
 char* str2 = "12AB";
 fprintf(stdout, "%d \n", hex2int(str2));
 getchar();
}
