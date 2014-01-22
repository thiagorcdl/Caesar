#include <stdio.h>
#include <time.h>

#define BASE (c>='a'?'a':'A')	// if lower case, base is 'a', else 'A'

char text[1 << 16];
FILE *fp;

int main(){
	int sh=1, i;
	char c, arq[8];

	while(scanf("%c", &c) == 1 && c !=EOF){
		if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ){
			c = (c - BASE + sh) %26 + BASE; // char + shift mod 26
		}
		sprintf(text,"%s%c",text,c);	// stores text in a string
	}

	fp = fopen("1.out","w");	// writes first outcome
	fprintf(fp,"%s",text);
	fclose(fp);

	for(sh=2; sh < 26; sh++){	// cycle through remaining 24 keys
               	sprintf(arq,"%d.out",sh);
		for(i=0; text[i]!='\0'; i++){
			c = text[i];
	                if((c >= 'a' && c <= 'z') || 
			   (c >= 'A' && c <= 'Z') ){
                        	text[i] = (c - BASE +1) %26 + BASE;
                	}
		}
		fp = fopen(arq,"w");	// writes outcomes
		fprintf(fp,"%s",text);
		fclose(fp);
	}
	return 0;
}
