#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SIZE 5
int main()
{
        int answer;
        int slot;
        int apts = 0;
        int schedule[SIZE] = {0,0,0,0,0};
        int i;

        while(1)
        {
                printf("MENU\n 1 - Schedule a Lesson\n 2 - Delete\n 3 - List\n 9 - Quit\n");
                scanf("%d", &answer);
                printf("Option: %d\n", answer);
                switch(answer)
                {
                        case 1:
                                if(apts == 5)
                                        {
                                                printf("There are no available time slots\n");
                                        }

                                for(i=1; i<6; i++)
                                {
                                        if(schedule[i-1] == 0)
                                        {
                                                printf("Your lesson has been scheduled at %d PM\n", i);
                                                schedule[i-1] = 1;
                                                apts++;
                                                break;
                                        }
                                }
                                break;
                        case 2:
                                printf("Please enter the time slot you would like to cancel: ");
                                scanf("%d", &slot);
                                if(schedule[slot-1] == 1)
                                {
                                        printf("Your lesson at %d PM has been cancelled\n", slot);
                                        schedule[slot-1] = 0;
                                        apts--;
                                }
                                else
                                {
                                        printf("There were no lessons previously reserved at this time\n");
                                }
                                break;
                        case 3:
                                for(i=1; i<6; i++)
                                {
                                        if(schedule[i-1] == 0)
                                        {
                                                printf("%d: Open\n", i);
                                        }
                                        else
                                        {
                                                printf("%d: Reserved\n", i);
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