#include "assert.h"

bool test_all(){

    
    char *compress_cases[][2]= {
        {"a", "a1"},
        {"abcdfabcdfabcdfabcdf", "abcdf4"},
        //{"ab", "a1-b1"},
        //{"abcdfabcdfabcdfabcdfcaabbabab", "abcdf4-c1-a2-b2-ab2"},
        {"aaaaaaabbbbbaaaaaaaaaa", "a7-b5-a10"},
        /* Basile Tests */          
        {"ababababababababababab", "ab11"},
        {"ababababababaaaaaaaaaaaaaaa", "ab6-a15"},
        {"abcabcabcabcxyxyxyccccccc", "abc4-xy3-c7"},
        {"antonioantonioantoniocarloscarlos", "antonio3-carlos2"},
    };

    for(int i = 0; i < sizeof(compress_cases) / sizeof(compress_cases[0]); i++){
        char *compressed_str = compress(compress_cases[i][0], strlen(compress_cases[i][0]));
        printf("%s\n", compressed_str);

        assert(strcmp(compressed_str, compress_cases[i][1]) == 0);

        free(compressed_str);
    }

    char *decompress_cases[][2]= {
        {"a", "a1"},
        {"abcdfabcdfabcdfabcdf", "abcdf4"},
        {"ab", "a1-b1"},
        {"abcdfabcdfabcdfabcdfcaabbabab", "abcdf4-c1-a2-b2-ab2"},
        {"aaaaaaabbbbbaaaaaaaaaa", "a7-b5-a10"},
        /* Basile Tests */          
        {"ababababababababababab", "ab11"},
        {"ababababababaaaaaaaaaaaaaaa", "ab6-a15"},
        {"abcabcabcabcxyxyxyccccccc", "abc4-xy3-c7"},
        {"antonioantonioantoniocarloscarlos", "antonio3-carlos2"},
        {"aaaaaaabbbbbaaaaaaaaaa", "a7-b5-a10"},
        {"aaaaaabbbbbbbbbbbbbbbcd", "-a6-b15-c1-d1"}
    };

       for(int i = 0; i < sizeof(decompress_cases) / sizeof(decompress_cases[0]); i++){
            char *decompress_str = decompress(decompress_cases[i][1], strlen(decompress_cases[i][1]));
            printf("%s\n", decompress_str);

            assert(strcmp(decompress_str, decompress_cases[i][0]) == 0);

            free(decompress_str);
    }


    return true;
}