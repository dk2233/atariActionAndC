#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N  200
#define EOL_ATARI  0x9b
#define EOL     0x0a
#define ADDITIONAL_CHARS   3

long int FileSize(FILE* file);

char *strAtari="_atr";

char ending[]={0xa,0xd,0};

long int FileSize(FILE* file)
{
    long int size=0;
    if (0==fseek(file,0L, SEEK_END))
    {
        size = ftell(file);
        /*         (void)fseek(file,0L,SEEK_SET);
        */
        rewind(file);
    }
    return size;

}

int main(int argc, char** argv)
{
    FILE* file;
    FILE * file2;
    if (argc<1)
    {
        printf("give file name in argument\n");
        return 1;
    }

    printf("%s \n", argv[1]);
    file = fopen(argv[1],"r");
    

    char *newFileName = calloc(strlen(argv[1])+strlen(strAtari),sizeof(char));
    
    char *dotLocation = strchr(argv[1],'.');
/* if no .act on the end */

    if (dotLocation == NULL)
    {
        newFileName = strcpy(newFileName, argv[1]);
        strcat(newFileName,strAtari);
    }
    else
    {
        int i= dotLocation-argv[1];
        strncpy(newFileName, argv[1],i);
        strcat(newFileName,strAtari);
        strcat(newFileName,dotLocation);
        printf("%s\n",newFileName);
    }



    file2 = fopen(newFileName,"w");
    free(newFileName);

    char *buffer;

    buffer=calloc(FileSize(file)+ADDITIONAL_CHARS,sizeof(char));


    char c;
    //line=fgets(line,N,file);
    c=fgetc(file);
    long int n=0;
    while(c!=EOF)
    {
        /*printf("%s\n",line);
        printf("%c %c \n",*(line+strlen(line)-1),*(line+strlen(line)-2));
        line=fgets(line,N,file);*/

        if (c==0x0a)
                c=EOL_ATARI;

        //printf("%c",c);

        buffer[n++]=(char)c;
        printf("%c",buffer[n-1]);

        c=fgetc(file);

    }

    strcat(buffer,ending);
    fputs(buffer,file2);

    fclose(file);
    fclose(file2);
    free(buffer);

    return 0; 

}
