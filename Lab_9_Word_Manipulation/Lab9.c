#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void);
void input(void);
void reverse(void);
void convert(void);
void info(void);
void output(void);

char words[10][20];
int length[10];
int counter = 0;
int avg = 0;
int sum = 0;
int i = 0;
int j = 0;
char temp[20];
char *p;

int main(void)
{
        input();
        reverse();
        convert();
        info();

        return 1;
}

void input(void)
{
        printf("Input up to 10 words: \n");
        for(i=0; i<10; i++)
        {
                if(scanf("%s", words[i]) != 1)
                {
                        break;
                }

                for(j=0; j<10; j++)
                {
                        if(strcmp(words[i], words[j]) < 0 && words[j][0] != '\0')
                        {
                                strcpy(temp, words[i]);
                                strcpy(words[i], words[j]);
                                strcpy(words[j], temp);
                        }
                }
                counter++;
        }
        printf("In Order: ");
        output();

}

void reverse(void)
{
        for(i=0, j=counter - 1; i<j; i++, j--)
        {
                strcpy(temp, words[i]);
                strcpy(words[i], words[j]);
                strcpy(words[j], temp);

        }
        printf("Reverse Order: ");
        output();
}

void convert(void)
{
        int wordlength = 0;
        for(i=0; i<counter; i++)
        {
                p = words[i];
                wordlength = 0;
                while(*p != '\0')
                {
                        if(islower(*p))
                        {
                                *p = toupper(*p);
                        }
                        p++;
                        wordlength++;
                }
                length[i] = wordlength;
        }

        printf("Uppercase: ");
        output();
}

void info(void)
{
        int shortest = 21;
        int shorter = 0;
        int longest = 0;
        int longer = 0;

        printf("Words that don't start with a letter: \n");
        for(i=0; i<counter; i++)
        {
                if(isalpha(words[i][0]) < 1)
                {
                        printf("%s \n", words[i]);
                }
                sum+=length[i];
        }

        for(i=0; i<counter; i++)
        {
                if(shortest > length[i])
                {
                        shortest = length[i];
                        shorter = i;
                }
        }

        printf("The Shortest String is %s \n", words[shorter]);

        for(i=0; i<counter; i++)
        {
                if(longest < length[i])
                {
                        longest = length[i];
                        longer = i;
                }
        }

        printf("The Longest String is %s \n", words[longer]);

        avg = (sum/(counter));
        printf("The Average String is %d \n", avg);
}
void output(void)
{
        for(i=0; i<counter; i++)
        {
                printf("%s \n", words[i]);
        }
        printf("\n");
}
