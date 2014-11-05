#include "XOR.h"


/*
This file include functions that is used to do XOR encryption
There will be functions to check for hex or dec or base64
*/

#define MAXCHAR 1024

//Functions to compare msg and key then modify key if needed



//Functions to encrypt 2 Dec messages with Xor
//Take in 2 int arguments
//Xor them together to produce the encrypt message
int int_xor(int num1, int num2)
{
	int xor_num = 0;
	
	xor_num = num1 ^ num2;
	
	return xor_num;
}

//Functions to encrypt 2 Hex messages with XOR
//Take in 2 Hex arguments
//Xor them together to produce the encrypt message
//Algorithm:
//First compare size between msg and key
//If msg > key, repeat the key until msg = key
//encrypt every bytes then concatenate the out result
char* hex_xor( char *msg, char *key)
{
	char* out;
	int i;
	char a[2];
	char b[2];
	int len = strlen(msg) + 1;
	out = malloc((len)*sizeof(char));
	memset(out, 0, (len)*sizeof(char));
	
	//Functions to compare msg and key then modify key if needed
	
	//
	//Xor every char 
	while(msg[0]!='\0')
	{
		for(i=0; i<2; i++)
		{
			a[i] = msg[i];
			b[i] = key[i];
		}
		a[1] = '\0';
		b[1] = '\0';
		out = strcat(out, dec_to_hex(int_xor(hex2int(a) ,hex2int(b))));
		msg = msg + 1;
		key = key + 1;
	}
	
	return out;
}

char* char_xor(char* msg, char* key)
{

	char* msghex = hex_encode(msg);
	char* keyhex = hex_encode(key);
	char* out = hex_xor(msghex, keyhex);
	
	out = hex_decode(out);
	return out;

}

/*
int main(int argc, char *argv[])
{
//char tmp[2];

char hex1[1024];
char hex2[1024];
char* he1 = "a";
char* he2;
char* out;
char* in;
int a,b;
int i = 1;
while(i==1)
{
	//scanf("%s", &a);
	//scanf("%s", &b);
	//hex1 = "42f10";
	scanf("%s", &hex1);
	out  = check_hex(hex1);
	//scanf("%s", &hex2);
	out = hex_decode(out);
	printf("%s\n", out);
	
	out = char_xor(out, he1);
	printf("%s\n", out);
	out = char_xor(out, he1);
	in = hex_encode(out);
	printf("in = %s", in);
	//he1 = check_hex(hex1);
	//he2 = check_hex(hex2);
	//out = hex_xor( he1, he2);
	//printf("%s\n", out);
	//printf("%s\n", he2);
	//printf("%s\n", he1);
	//he1 = hex_xor( out, he2);
	//printf("%s\n", he1);

	scanf("%d", &i);
}
return 0;
}*/
