#include "freq_analyze.h"
#include "base_conversion.h"

/*This file try to analyze file and look for chars with highest frequency
 *Algorithm:
 *
 *Read file
 *
 *Make an array of "ETAOIN SHRDLU"
 *
 *Make an int array with 256 slot.
 *For every ASCII char, increment its according slot by 1
 *Return 10 highest frequency words
 */

//Readfile
void read_file(FILE **in)
{
	char *mode = "r";
	*in = fopen("hello.txt", mode);
	if (*in == NULL) {
  		fprintf(stderr, "Can't open input file in.list!\n");
  		exit(1);
	}else{
		fprintf(stdout, "Open file sucecssfully\n");
	}
}

//Find the max num and its index in an array
int max_index(int array[])
{
	int k = 0;
	int max = array[k];
	int i;
	for (i = 0; i < 256; ++i)
	{
		if (array[i] > max)
		{
		    max = (int)array[i];
		    k = i;
		}
	}
	return k;
}

//Find the highest frequency char
/*void find_freq(FILE *in)
{
	char string[1024];
	int i,j;
	int char_table[256];
	for(i=0;i<256;i++){
		char_table[i] = 0;
		}
	while (fscanf(in, "%s", string) != EOF) {
  		fprintf(stdout, "%s\n", string);
  		for(i=0; i<strlen(string); i++){
  			char_table[(int)string[i]]++;
  			} 
	}	
	j = max_index(char_table);
	fprintf(stdout, "max number is:%d, %c, in %d times \n", j, (char)j, char_table[j]);
	
}*/

void find_freq(FILE *in, int hex, int array[])
{
	
	char string[1024];
	char* hex_string;
	int i,j;
	int char_table[256];
	for(i=0;i<256;i++){
		char_table[i] = 0;
		}
	if(hex==1){
		while (fscanf(in, "%s", string) != EOF) {
	  		//fprintf(stdout, "%s\n", string);
	  		hex_string = check_hex(string);
	  		hex_string = hex_decode(hex_string);
	  		for(i=0; i<strlen(hex_string); i++){
	  			char_table[(int)hex_string[i]]++;
	  		} 
	  		free(hex_string);
		}	
	}else{
		while (fscanf(in, "%s", string) != EOF) {
  		//fprintf(stdout, "%s\n", string);
  		for(i=0; i<strlen(string); i++){
  			char_table[(int)string[i]]++;
  		} 
	}
	}	
	
	//Now that we have all char_table, find the 10 max char and put t in array
	for(i=0; i<10;i++){
		j = max_index(char_table);
		fprintf(stdout, "max number is:%d, %c, in %d times \n", j, (char)j, char_table[j]);
		char_table[j] = 0;
		array[i] = j;
	}
	
	return;
}

/*int main()
{
	FILE *in;
	int high_freq[10];
	
	read_file(&in);
	
	char file[1024];
	//Read file
	//scanf() for now
	//fgets (file,1024, stdin);
	//printf("%s" , file);
	
	find_freq(in,1);
	
	fclose(in);

	return 0;
}*/
