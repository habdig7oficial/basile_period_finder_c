#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"

char *compress_legacy(char *text, int len){
    size_t text_len = strlen(text);
    size_t allocated_area = text_len / 3;
    char *string_builder = (char *) malloc(text_len);

    if(string_builder == NULL){
        printf("Error could not alloc Memory!");
        return "";
    }

    for(int i = 0, counter = 1; i <= text_len; i++){
        if(text[i] == text[i + 1])
            counter++;
        else{
            char buffer_size = (sizeof(char) * 2) + sizeof(char)*(int)log10(counter);
            char *buffer = (char *) malloc(buffer_size); // + 2 because of the char &text[i]
            sprintf(buffer, "%c%d-", text[i], counter);

            if(buffer_size + strlen(string_builder) > allocated_area){
                allocated_area += allocated_area * 0.5;
                string_builder = realloc(string_builder, allocated_area);
                printf("\nReallocing...\n%zu Bytes total\n", allocated_area);
            }

            strcat(string_builder, buffer);

            printf("%s", buffer);
            counter = 1;
        }
    }

    string_builder[strlen(string_builder) - 1] = '\0';

    return string_builder;
}

