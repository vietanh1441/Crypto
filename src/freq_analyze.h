#ifndef FREQ_ANALYZE_H
#define FREQ_ANALYZE_H

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

void read_file(FILE **in);
int max_index(int array[]);
void find_freq(FILE *in, int hex);

#endif /*FREQ_ANALYZE_H*/
