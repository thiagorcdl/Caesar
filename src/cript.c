#include <stdio.h>
#include <time.h>

#define BASE (c>='a'?'a':'A')	// if lower case, base is 'a', else 'A'

int main(){
	int sh;		 				// shift
	char c;		  				// character
	srand(time(NULL));
	sh = (random() % 25) +1;	 	 	// random key
	fprintf(stderr,"Generated key: %d\n",sh);	// prints key
	while(scanf("%c", &c) == 1 && c !=EOF){
		if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ){
			c = (c - BASE + sh) %26 + BASE; // char + shift mod 26
		}
		printf("%c",c);
	}
	return 0;
}
