#ifndef XOR_H
#define XOR_H

#include "base_conversion.h"

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

int int_xor(int num1, int num2);
char* hex_xor( char *msg, char *key);
char* char_xor(char* msg, char* key);

#endif /*XOR_H*/
