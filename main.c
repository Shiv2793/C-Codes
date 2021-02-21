#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char ch;
    int i=0;
    char c[10];
    char s2[]="Electronic";
    int n=0;
    int m=0;
    char s1[100];
    FILE *fptr;
    int len = strlen(s2);
    char* filename = "C:\\Users\\R.A.Pal\\Desktop\\test.txt";
    int Length;
    fptr = fopen(filename, "r");
if ((fptr) == NULL)
    {
        printf("Error! opening file");
        // Program exits if file pointer returns NULL.
    }
else
    {
while((ch=fgetc(fptr))!=EOF)
{
// if(ch=='\n'){
fscanf(fptr,"%[^\n]",s1);
printf("%s ",s1);
Length=strlen(s1);
printf("%d ",Length);
     // contains the length of search string

    for (n=0;n<=Length;n++)
     {
        if (s1[n] == s2[m])
        {
            while (s1[n] == s2[m] && s1[n] != '\0')
            {
                n++;
                m++;
            }

            // if we sequence of characters matching with the length of searched string
            if (m == len && (s1[n] == ' ' || s1[n] == '\0'))//if match
            {

                // BINGO!! we find our search string.
                printf(" Got string %s, Play Something Here\n ",s2);
                int L=Length-10;
                for(i=L;i<=Length;i++)
                {
                    c[i]=s1[i];
                    //printf("Hello");
                    printf("%c",c[i]);
                }
              break;
            }
        else
        { // if first character of search string DOES NOT match
            while (s1[n] != ' ')
            { // Skip to next word
                n++;
                if (s1[n] == '\0')
                    printf("'%s' does not appear in the sentence.\n", s2);
                   break;
            }
        }

        //n++;
        m = 0; // reset the counter to start from first character of the search string.
    }
    }

}
    fclose(fptr);
}
  return 0;
    }
