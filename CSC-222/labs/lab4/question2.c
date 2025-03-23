#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    if (argc != 3){
        printf("Usage: ./question2 <source_file> <destination_file>\n");
    } else {
        if (access(argv[1], F_OK) != 0) {
            printf("Error opening source file: No such file %s\n", argv[1]);
        } else {
            FILE *sourcePtr;
            sourcePtr = fopen(argv[1], "rb");
            FILE *destPtr;
            destPtr = fopen(argv[2], "wb");
            char c = fgetc(sourcePtr);
            while (c != EOF){
                fputc(c, destPtr);
                c = fgetc(sourcePtr);
            }
            fclose(sourcePtr);
            fclose(destPtr);

            printf("Files copied successfully.\n");

            char *args[] = {
                "md5sum",
                "--tag",
                argv[1],
                NULL
            };

            int pid = fork();
            if (pid == 0){
                args[2] = argv[2];
                execvp(args[0], args);
            } else {
                args[2] = argv[1];
                execvp(args[0], args);
            }
        }

        
    }
}