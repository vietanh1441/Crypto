#include "base_conversion.h"

/*
This library simply try to convert number from this base to another base
So far, I'm working on:
+Hex to binary
+Dec to binary
+base64 to binary
+binary to something else.
Probably gonna try to put ASCII somewhere in there but C could probablly do enough
*/


//This method using string compare to convert from 
//decimal to others, thus the table.

//To convert Hex, first build a libary of Hex table
static char hex_table[16] = {'0','1','2','3','4','5','6','7',
							 '8','9','A','B','C','D','E','F'};
							 
//Same thing with Base64, this is the Base 64 table
static char  base64_table[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
                                'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
                                'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
                                'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
                                'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
                                'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
                                'w', 'x', 'y', 'z', '0', '1', '2', '3',
                                '4', '5', '6', '7', '8', '9', '+', '/'};

//static int mod_table[] = {0, 2, 1};

//A custom string reverse
char *strrev(char *str)
{
      char *p1, *p2;

      if (! str || ! *str)
            return str;
      for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
      {
            *p1 ^= *p2;
            *p2 ^= *p1;
            *p1 ^= *p2;
      }
      return str;
}

char* dec_to_base64(int n) {

	//Find length of string hex, in this case, use log 16
	int len = floor(log10(n)/log10(64)) + 1;
	int num, i;
	int str_len = len+1;
	//printf("%d", n);
	//printf("string len = %d\n", str_len);
	//Set string size and set int to string
	char* base64;
	base64 = malloc(sizeof(char)*str_len);
	memset((base64), 0, (str_len) * sizeof(char)); //Safe 
	for (i=0; i<str_len-1; i++)
	{
	//printf("%d", i);
	num = n%64;
	base64[i] = base64_table[num];
	n=n/64;
	};
	
	
	base64[i] = '\0';
	strrev(base64);
	return base64;
}

char* hex_decode(char* in)
{
	char* out;
	int i, b;
	int len = strlen(in);
	
	len = len/2 + 1;
	out = malloc(len * sizeof(char));
	memset(out, 0, len*sizeof(char));
	
	for(i=0; i<len-1; i++)
	{
		sscanf(in, "%2X", &b);
		out[i] = b;
		in = in + 2;
	}
	return out;
}

char* hex_encode(char* in)
{
	int i;
	int chars = 0;
	char tmp[3];
	char* out;

	chars = strlen(in) * 2;
	out = malloc((chars+1) * sizeof(char));
	memset(out, 0, (chars+1) * sizeof(char));

	for(i=0; (i<strlen(in)); i++) {
		sprintf(tmp, "%02x", (char) in[i]);
		strncat(out, tmp, 3);
	}

	return out;
}


int hex2int(char *a)
{
    char *offset; 
 	return strtol(a, &offset, 16);
}

//Functions to directly convert Hex to base64
//To do this, take every 6 char from hex, convert it to dec then convert 
//it to Base64 then use strcat to concatenate them up
char* hex_to_base64(char *hex)
{
	//Take 6 char from hex
	char new_str[1];
	int num;
	char* base64;
	char* full;
	
	//malloc full by using length of hex time 4 divide 6 + 1
	int len = strlen(hex);
	int str_len = (len * 4 / 6) + 1;
	full = malloc(sizeof(char)*str_len);
	
	int i;
	//printf("%s",hex);
	while(hex[0] != '\0')
	{
	//printf("%s",hex);
	for(i=0; i<1; i++)
	{
		new_str[i] = hex[i];
	}
	//printf("%s",new_str);
	hex = hex + 1;
	//Now convert it to int
	num = hex2int(new_str);
	
	//Then convert it to Base64
	base64 = dec_to_base64(num);
	full = strcat(full, base64);
	
	free(base64);
	}
	
	return full;
}


//Functions to check each hex character to make sure 
//that this is a legal hex character
//Also convert lower case hex char "a..f" to upper case "A..F"
char* check_hex(char* hi)
{
	int i;
	int len = strlen(hi);
	len = len;
	char* hex;
	//printf("%d", len);
	hex = malloc(sizeof(char)*len);
	memset((hex), 0, (len) * sizeof(char));
	//Convert lowercase to uppercase
	for(i=0; hi[i]!='\0'; i++)
	{
		if(hi[i] >= 'a' && hi[i] <= 'z'){
		        hex[i] = ('A' + hi[i] - 'a');
		  }
		  else
		  {
            hex[i] = hi[i];
      }
      
      //Check if character is legal:
		if(hex[i] > 'F' || hex[i] < '0')
		{
			printf("Error, incorrect hex character.\n");
			exit(-1);
		}
		if(hex[i] > '9' && hex[i] < 'A')
		{
			printf("Error, incorrect hex character.\n");
			exit(-1);
		}
    }
    hex[i] = '\0';
    //printf("%s", hex);
    return hex;
}


//Functions to convert an int number to char
void in_to_char(int num, char **string)
{
	//Calculate length of number
	int len = floor(log10(abs(num))) + 1;
	int str_len = len + 1;
	
	//Set string size and set int to string
	*string = malloc(sizeof(char)*str_len);
	memset((*string), 0, (str_len) * sizeof(char)); //Safe side
	sprintf(*string, "%d", num);
	//*string[0] = '2';
}

//Functions to convert a char to an int number
int char_to_int(char string[])
{
	int c, n;
	n = 0;
 
  	for (c = 0; string[c] != '\0'; c++) {
    	n = n * 10 + string[c] - '0';
	}
 
  	return n;
}

//Convert from Decimal to Hex
char* dec_to_hex(int n) 
{
	//Guard against 0
	if(n == 0)
	{
	char* hex = "0";
	return hex;
	}
	
	//Find length of string hex, in this case, use log 16
	int len = floor(log10(abs(n))/log10(16)) + 1;
	int num, i;
	int str_len = len+1;
	//printf("%d", n);
	//printf("string len = %d\n", str_len);
	//Set string size and set int to string
	char* hex;
	hex = malloc(sizeof(char)*str_len);
	memset((hex), 0, (str_len) * sizeof(char)); //Safe 
	for (i=0; i<str_len-1; i++)
	{
	//printf("%d", i);
	num = n%16;
	hex[i] = hex_table[num];
	//printf("%c",hex[i]);
	n=n/16;
	};
	//printf("%d", i);
	hex[i] = '\0';
	strrev(hex);
	
	//strrev(hex);
	return hex;
}

//Main functions for debug
/*int main(int argc, char *argv[])
{

}
return 0;
}*/
