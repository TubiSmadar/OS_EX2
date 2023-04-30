#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {
    if (argc < 3) {
        printf("The usage should be: cmp <file1> <file2> than an option [-v]/[-i]\n");
        return 1;
    }

    char* file1 = argv[1];
    char* file2 = argv[2];
    int verbose = 0;             // default for -v flag
    int force = 0;               // default for -f flag

    // this loop checking for which flags the  user requested to use.
    for (int i = 3; i < argc; i++) {
        if (strcmp(argv[i], "-v") == 0) {
            verbose = 1;
        } else if (strcmp(argv[i], "-f") == 0) {
            force = 1;
        }
    }

    //opening the files for reading
    FILE *f1Read, *f2Read;
    f1Read = fopen(file1, "r");
    f2Read = fopen(file2, "r");

    if (f2Read != NULL && !force) {             
        printf("Error: target file exists\n");
        return 1;
    }

    f2Read = fopen(file2, "w");         // open the second file for writing

    if (f1Read == NULL || f2Read == NULL) {
        printf("Error in opening one or both files\n");
         return 1;
    }

    int c;

    // while is not the end of the file, keep copying each letter to the second file.
    while ((c = fgetc(f1Read)) != EOF) {
        fputc(c, f2Read);
    }

    //The fclose() function closes a stream pointed to by stream
    fclose(f1Read);
    fclose(f2Read);

    if (verbose) {
        printf("success\n");
    }

    return 0;
}
