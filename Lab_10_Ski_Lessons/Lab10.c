#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 5

int apts = 0;
int i;
int j;
char schedule[5][20];
char name[20];
char contact[5][20];
char phone[20];
char letter;
int gsize[5];
int group;
int prioritynum = 0;

void schedulef(void);
void cancel(void);
void list(void);
void firstletter(void);
void groupsize(void);
void priority(void);
int countletters(char c);

int main(void)
{
        int answer;

        for(i=0; i<SIZE; i++)
        {
                schedule[i][0] = '\0';
        }

        while(1)
        {
                printf("MENU\n 1 - Schedule a Lesson\n 2 - Delete\n 3 - List\n 4 - Names With Given First Letter\n 5 - Groups\n 6 - Priority\n 7 - Count Letters\n 9 - Quit\n");
                scanf("%d", &answer);
                printf("Option: %d\n", answer);
                switch(answer)
                {
                        case 1:
                                schedulef();
                                break;
                        case 2:
                                cancel();
                                break;
                        case 3:
                                list();
                                break;
                        case 4:
                                firstletter();
                                break;
                        case 5:
                                groupsize();
                                break;
                        case 6:
                                priority();
                                break;
                        case 7:
                                printf("Letter: ");
                                scanf(" %c", &letter);
                                printf("There are %d occurences of %s\n", countletters(letter), &letter);
                                break;
                        case 9:
                                return 0;
                        default:
                                printf("Please use an available option\n");
                                break;
                }
        }
}

void schedulef()
{
        if(apts == 5)
        {
                printf("There are no available time slots\n");
                return;
        }
        printf("Name: ");
        scanf("%s", name);
        for(i=0; i<5; i++)
        {
                while(strcmp(name, schedule[i]) == 0)
                {
                        printf("Input a unique name: ");
                        scanf("%s", name);
                }
        }
        printf("Phone Number: ");
        scanf("%s", phone);
        printf("Group Size: ");
        scanf("%d", &group);
        while(group < 1 ||  group > 5)
        {
                printf("Please enter a group size between 1-5: ");
                scanf("%d", &group);
        }
        for(i=0; i<5; i++)
        {
                if(schedule[i][0] == '\0')
                {
                        for(j=0; j<20; j++)
                        {
                                schedule[i][j] = name[j];
                                contact[i][j] = phone[j];
                        }
                        gsize[i] = group;
                        printf("Your lesson has been scheduled at %d PM\n", i+1);
                        apts++;
                        break;
                }
        }
}

void cancel()
{
        if(apts == 0)
        {
                printf("No Appointments\n");
        }
        else
        {
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
                                        contact[i][j] = '\0';
                                        gsize[i] = 0;
                                }

                                for(j=i; j<5; j++)
                                {
                                        if(schedule[j][0] != '\0')
                                        {
                                                printf("Time changed for %s, %s, %d, from %d to %d\n", schedule[j], contact[j], gsize[j], j+1, j);
                                        }
                                        strcpy(schedule[j], schedule[j+1]);
                                        strcpy(contact[j], contact[j+1]);
                                        gsize[j] = gsize[j+1];
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
        }
}       
        
void list()
{               
        for(i=0; i<5; i++)
        {               
                if(schedule[i][0] == '\0')
                {
                        printf("%d: Open\n", i+1);
                }
                else
                {
                        printf("%d: %s, %s, %d\n", i+1, schedule[i], contact[i], gsize[i]);
                }
        }
}               
                
void firstletter()
{       
        if(apts == 0)
        {       
                printf("No Appointments\n");
        }               
        else            
        {                       
                printf("Letter: ");
                scanf(" %c", &letter);
                for(i=0; i<5; i++) 
                {       
                        if(schedule[i][0] == letter)
                        {
                                printf("%d: %s, %s, %d\n", i+1, schedule[i], contact[i], gsize[i]);
                        }
                }
        }
}

void groupsize()
{       
        if(apts == 0)
        {
                printf("No Appointments\n");
        }
        else    
        {       
                printf("Group Size: ");
                scanf("%d", &group);
                for(i=0; i<5; i++)
                {       
                        if(gsize[i] == group)
                        {       
                                printf("%d: %s, %s, %d\n", i+1, schedule[i], contact[i], gsize[i]);
                        }               
                }                       
        }                               
}                               

void priority()                 
{                               
        if(prioritynum == 0)            
        {                               
                if(apts == 5)                   
                {                       
                        printf("Time deleted for %s, %s, %d\n", schedule[4], contact[4], gsize[4]);
                        for(i=0; i<20; i++)
                        {               
                                schedule[4][i] = '\0';
                                contact[4][i] = '\0';
                                gsize[4] = 0;
                        }
                }       
                for(i=4; i>=0; i--)
                {               
 if(schedule[i-1][0] != '\0')
                        {
                                printf("Time changed for %s, %s, %d, from %d to %d\n", schedule[i-1], contact[i-1], gsize[i-1], i, i+1);
                        }
                        strcpy(schedule[i], schedule[i-1]);
                        strcpy(contact[i], contact[i-1]);
                        gsize[i] = gsize[i-1];
                }

                printf("Name: ");
                scanf("%s", name);
                for(i=0; i<5; i++)
                {
                        while(strcmp(name, schedule[i]) == 0)
                        {
                                printf("Input a unique name: ");
                                scanf("%s", name);
                        }
                }
                printf("Phone Number: ");
                scanf("%s", phone);
                printf("Group Size: ");
                scanf("%d", &group);
                while(group < 1 ||  group > 5)
                {
                        printf("Please enter a group size between 1-5: ");
                        scanf("%d", &group);
                }
                for(j=0; j<20; j++)
                {
                        schedule[0][j] = name[j];
                        contact[0][j] = phone[j];
                }
                gsize[0] = group;
                printf("Your lesson has been scheduled at 1 PM\n");
                apts++;
                prioritynum++;
        }
        else
        {
                printf("Priority has already been used \n");
        }
}

int countletters(char c)
{
        char *p;
        int lettercount = 0;

        for(i=0; i<5; i++)
        {
                p = schedule[i];

                while(*p != '\0')
                {
                        if(*p == letter)
                        {
                                lettercount++;
                        }
                        p++;
                }
        }
        return lettercount;
}
