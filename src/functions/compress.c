#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"

char *find_period(char *text, int *counter, int *buffer_size){
    char str[] = "he";
    char *hello = (char *) malloc(sizeof(str));

    memcpy(hello, str, sizeof(str));

    *counter = 1;
    *buffer_size = sizeof(str);

    return hello;
}

char *compress(char *text){
    size_t allocated_area, text_len;
    allocated_area = text_len = strlen(text);
    char *string_builder = (char *) malloc(allocated_area);

    if(string_builder == NULL){
        printf("Error could not alloc Memory!");
        return "";
    }

    for(int i = 0, counter = 0, buffer_size = 0; i < text_len; i += counter * buffer_size){
        char *new_slice = find_period(&text[i], &counter, &buffer_size);

        char *buffer_size_str = malloc(sizeof(char)*(int)log10(10));
        sprintf(buffer_size_str, "%d", buffer_size);

        strcat(string_builder, "-");
        strcat(string_builder, new_slice);
        strcat(string_builder, buffer_size_str);

        printf("Slice: %d %s %s\n", buffer_size, string_builder, &string_builder[i]);
    }

    string_builder++;

    printf("Slice: %s\n",string_builder);

    return string_builder;
}