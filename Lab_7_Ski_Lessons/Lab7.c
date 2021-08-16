#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 5
int main()
{
        int answer;
        int slot;
        int apts = 0;
        int i;
        int j;
        int time[SIZE] = {0,0,0,0,0};
        char schedule[5][20];
        char name[20];
        char letter;

        for(i=0; i<SIZE; i++)
        {
                schedule[i][0] = '\0';
        }

        while(1)
        {
                printf("MENU\n 1 - Schedule a Lesson\n 2 - Delete\n 3 - List\n 4 - Names With Given First Letter\n 9 - Quit\n");
                scanf("%d", &answer);
                printf("Option: %d\n", answer);
                switch(answer)
                {
                        case 1:
                                if(apts == 5)
                                        {
                                                printf("There are no available time slots\n");
                                        }
                                printf("Name: ");
                                scanf("%s", name);
                                for(i=0; i<5; i++)
                                {
                                        if(schedule[i][0] == '\0')
                                        {
                                                for(j=0; j<20; j++)
                                                {
                                                        schedule[i][j] = name[j];
                                                }
                                                printf("Your lesson has been scheduled at %d PM\n", i+1);
                                                apts++;
                                                break;
                                        }
                                }
                                break;
                        case 2:
                                printf("Please enter the name of the reservation you would like to cancel: ");
                                scanf("%s", name);
                                for(i=0; i<5; i++)
                                {
                                        if(strcmp(schedule[i], name) == 0)
                                        {
                                                printf("Your lesson at %d PM has been cancelled\n", i+1);
                                                for(j=0; j<20; j++)
                                                {
                                                        schedule[i][j] = '\0';
                                                }

                                                for(j=i; j<5; j++)
                                                {
                                                        strcpy(schedule[j], schedule[j+1]);
                                                }
                                                apts--;
                                                break;
                                        }
                                        if(schedule[i][0] == '\0')
                                        {
                                                printf("There are no reservations under that name\n");
                                                break;
                                        }
                                }
                                break;
                        case 3:
                                for(i=0; i<5; i++)
                                {
                                        if(schedule[i][0] == '\0')
                                        {
                                                printf("%d: Open\n", i+1);
                                        }
                                        else
                                        {
                                                printf("%d: %s\n", i+1, schedule[i]);
                                        }
                                }
                                break;
                        case 4:
                                printf("Letter: ");
                                scanf(" %c", &letter);
                                for(i=0; i<5; i++)
                                {
                                        if(schedule[i][0] == letter)
                                        {
                                                printf("%s\n", schedule[i]);
                                        }
                                }
                                break;
                        case 9:
                                return 0;
                        default:
                                printf("Please use an available option\n");
                                break;
                }
        }
}

