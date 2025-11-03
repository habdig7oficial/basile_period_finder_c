#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"
#include "ctype.h"

char *decompress(char *text, int len){
    int reapeat_num = 0;
    int num = 0 ;

    char allocated_area = pow(len, 2);
    char *buffer = (char *) calloc(allocated_area, allocated_area);

    for(int c = 0; c < len; c++){

        if(isdigit(text[c])){
            reapeat_num = atoi(&text[c]) * (pow(10, num++));
            printf("%d %c", reapeat_num, text[c]);
        }
        else if((text[c] != '-') && (c != '\n')){
            if(strlen(buffer) + 1 < allocated_area){
                strcat(buffer, &text[c]);
                printf("Buffer %s\n", buffer);
            }
            else{
                allocated_area += (int) allocated_area * 0.5;
            }            
        }
        else {
            reapeat_num = 0;
            num = 0;
        }
        printf("\n");
    }


    return text;
}