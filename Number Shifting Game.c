#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

void Game_Rule()
{
    int ch;
    printf("\t\t\tRule Of This Game\n\n");

    printf("1. You can move only 1 step at a time by arrow key\n");
    printf("Move Up    : By Up Arrow Key\n");
    printf("Move Down  : By Down Arrow Key\n");
    printf("Move Left  : By Left Arrow Key\n");
    printf("Move Right : By Right Arrow Key\n\n");

    printf("2. You Can Move Number At Empty Position Only\n");

    printf("3. For Each Valid Move : Your TOtal Number Of Move Decrease By 1\n");

    printf("4. Winning Situation   : Number In a 4*4 Matrix Should Be in a order from 1-15\n\n");
    printf("\t Winning Situation :\n\n");
    printf("\t.....................\n");
    printf("\t| 1  | 2  | 3  | 4  |\n");
    printf("\t| 5  | 6  | 7  | 8  |\n");
    printf("\t| 09 | 10 | 11 | 12 |\n");
    printf("\t| 13 | 14 | 15 |    |\n");
    printf("\t.....................\n");

    printf("Press Esc Key Any Time To Exit The game\n");

    printf("Press Any Key To Start");
    ch = readenteredkey();
}
int winner(int arr[][4])
{
    int i,j,k=1;

    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++,k++)
        {
            if(arr[i][j] != k && k!=16)
                break;
        }
        if(j<4)
            break;
    }
    if(j<4)
        return 0;
    return 1;
}
void create_matrix(int arr[][4])
{
 int i,j;
  int num[15],n=15;

  int lastindex = n-1,index;

  for(i=0;i<15;i++)
      num[i] = i+1;

  srand(time(NULL));    //gen

  for(i=0;i<4;i++)
  {
     for(j=0;j<4;j++)
     {
       if(lastindex >=0)
       {
           index = rand()%(lastindex+1);
           arr[i][j] = num[index];
           num[index] = num[lastindex--];
       }
     }
  }
  arr[i-1][j-1] = 0;
}
void show_matrix(int arr[][4])
{
    int i,j;
    printf("\n\n --------------------\n");
    for(i=0;i<4;i++)
    {
        printf(" |");
        for(j=0;j<4;j++)
        {
            if(arr[i][j] != 0)
                printf("%2d | ",arr[i][j]);
            else
                printf("   | ");
        }
    printf("\n");
    }
    printf(" --------------------\n");
}
int Shift_Up(int arr[][4])
{
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(arr[i][j]==0)
                break;
        }
        if(j<4)
            break;
    }
    if(i==3)
        return 0;
    swap(&arr[i][j],&arr[i+1][j]);
    return 1;
}
int Shift_Down(int arr[][4])
{
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(arr[i][j]==0)
                break;
        }
        if(j<4)
            break;
    }
    if(i==0)
        return 0;
    swap(&arr[i][j],&arr[i-1][j]);
    return 1;
}
int Shift_Left(int arr[][4])
{
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(arr[i][j]==0)
                break;
        }
        if(j<4)
            break;
    }
    if(j == 3)
        return 0;
    swap(&arr[i][j],&arr[i][j+1]);
    return 1;
}
int Shift_Right(int arr[][4])
{
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(arr[i][j] == 0)
                break;
        }
        if(j<4)
            break;
    }
    if(j == 0)
       return 0;

    swap(&arr[i][j],&arr[i][j-1]);
    return 1;
}
void swap(int *x,int *y)
{
    *x = *x+*y;
    *y = *x-*y;
    *x = *x-*y;
    printf("");
}
int readenteredkey()
{
    char c;
    c = _getch();

    if(c == 0 || c == 224)
        c = _getch();

    return c;
}
int main()
{
    int i,key,move=300;
    int arr[4][4];
    char player_name[30];

    //Taking Players Name
    printf("\t\tEnter Your Name :- ");
    //Taking Input From User
    scanf("%s",&player_name);
    system("cls");

    Game_Rule();

    while(1)
    {
        create_matrix(arr);

        while(!winner(arr)) //for checking winner situation
        {
            system("cls");

            if(!move)  //For Checking Move is Left Or Not
                break;

            printf("Hello %s,   Move Reamaining = %d\n",player_name,move);

            show_matrix(arr);

            key = readenteredkey();
            switch(key)
            {
                case 101: //Ascii Code Of 'E'
                case 69 : //Ascii Code Of 'e'
                        printf("Thanks For Playing\n");
                        printf("Press Enter Key To Exit");
                        key = readenteredkey();
                        return 0;

                case 72 : //Ascii Code Of Up Arrow Key
                        if(Shift_Up(arr))
                           move--;
                        break;

                case 80 ://Ascii Code Of Down Arrow Key
                        printf("inside down arrow key");
                        if(Shift_Down(arr))
                           move--;
                        break;

                case 77 : //Ascii Code Of Right Arrow Key
                        if(Shift_Right(arr))
                           move--;
                        break;

                case 75 : //AScii Code Of Left Arrow Key
                        if(Shift_Left(arr))
                           move--;
                        break;
                default :
                        printf("Not matched any cases");
            }
        }
        if(!move)
            printf("Sorry You Lose !");
        else
            printf("You win");

        fflush(stdin);
        char check;
        printf("Enter 'Y' or 'y' to play again ");
        scanf("%c",&check);

        if(check != 'y' && check != 'Y')
           break;

        move = 300;
    }
    return 0;
}
