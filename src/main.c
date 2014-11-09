#include "base_conversion.h"
#include "XOR.h"
#include "freq_analyze.h"



int main(int argc, char *argv[])
{
	FILE *in;
	int i;
	int array[16];
	for(i=0;i<10;i++)
	{
		array[i] = 0;
	}
	//int high_freq[10];
	
	read_file(&in);
	
	//char file[1024];
	
	find_freq(in,1, array);
	
	
	for(i=0;i<10;i++)
	{
		fprintf(stdout, "%d \n", array[i]);
	}
	
	fclose(in);
	return 0;
}
