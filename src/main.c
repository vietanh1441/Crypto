#include "base_conversion.h"
#include "XOR.h"
#include "freq_analyze.h"



int main(int argc, char *argv[])
{
	FILE *in;
	//int high_freq[10];
	
	read_file(&in);
	
	//char file[1024];
	
	find_freq(in,1);
	
	
	
	fclose(in);
	return 0;
}
