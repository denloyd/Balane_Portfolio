#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<conio.h>
# define size 3
# define max 4
# define hard 5
int box[size][size], mid[max][max], diff[hard][hard], score_1 = 0, score_2 = 0, score_3 = 0;
FILE* easysavefile;
FILE* mediumsavefile;
FILE* hardsavefile;
char date_1[100];
char date_2[100];
char date_3[100];
char nameHard[100];
char nameMedium[100];
char nameEasy[100];

void delay(unsigned int secs)
{
    clock_t interval = clock() + secs;
    while(interval > clock());
}

void loading()
{
    system("cls");
    printf("\n\n\n\n");
    printf("\n\n\t\t\t\tPreparing game.... Please wait\n\n");
    for(int i =1; i<= 120; i++)
    {
            Sleep(5);
            printf("\033[0;31m"); printf("%c", 178); //Displayed character during the loading.
    }
    printf("\n\n\t\t\t\t Welcome to the Tile Puzzle Game!");
}

void easy()
{
    int a, b, found, l, y, d, o[size*size];
    srand(time(NULL));
    for (a = 0; a < size*size;)
    {
        l = rand()%(size * size);
        found = 0;

    for (b = 0; b < a; b++)
    {
        if (l == o[b])
        {
            found = 1;
            break;

        }
    }
    if (found == 0)
    {
        o[a] = l;
        y = a/size;
        d = a % size;
        box[y][d] = l;
        a++;
    }
    }
}
void medium()
{
    int a, b, found, l, y, d, o[max*max];
    srand(time(NULL));
    for (a = 0; a < max*max;)
    {
        l = rand()%(max * max);
        found = 0;

    for (b = 0; b < a; b++)
    {
        if (l == o[b])
        {
            found = 1;
            break;

        }
    }
    if (found == 0)
    {
        o[a] = l;
        y = a/max;
        d = a % max;
        mid[y][d] = l;
        a++;
    }
    }
}
void chall()
{
    int a, b, found, l, y, d, o[hard * hard];
    srand(time(NULL));
    for (a = 0; a < hard * hard;)
    {
        l = rand()%(hard * hard);
        found = 0;

    for (b = 0; b < a; b++)
    {
        if (l == o[b])
        {
            found = 1;
            break;

        }
    }
    if (found == 0)
    {
        o[a] = l;
        y = a/hard;
        d = a % hard;
        diff[y][d] = l;
        a++;
    }
    }
}
int display_chall()
{
    int a, b, count = 0;
    printf("\n\n");
    printf("\t--------------------------------\n\t");
    for(a = 0; a < hard ; a++)
    {
        for (b = 0; b < hard; b++)
        {
            if (diff[a][b]== a*hard + b + 1)
                count++;
            if (diff[a][b] == 0)
            {
                printf("| %3c ", ' ');
            }
            else
            {
                printf("| %3d ",diff[a][b]);
            }
        }
        printf ("|\n\t");
    }
     printf("---------------------------------\n");



    return count == hard * hard - 1;
}

int display_medium()
{
    int a, b, count = 0;
    printf("\n\n");
    printf("\t-------------------------\n\t");
    for(a = 0; a < max; a++)
    {
        for (b = 0; b < max; b++)
        {
            if (mid[a][b]== a*max + b + 1)
                count++;
            if (mid[a][b] == 0)
            {
                printf("| %3c ", ' ');
            }
            else
            {
                printf("| %3d ",mid[a][b]);
            }
        }
        printf ("|\n\t");
    }
     printf("--------------------------\n");



    return count == max * max - 1;
}
int display_easy()
{
    int a, b, count = 0;
    printf("\n\n");
    printf("\t--------------------\n\t");
    for(a = 0; a < size; a++)
    {
        for (b = 0; b < size; b++)
        {
            if (box[a][b]== a*size + b + 1)
                count++;
            if (box[a][b] == 0)
            {
                printf("| %3c ", ' ');
            }
            else
            {
                printf("| %3d ",box[a][b]);
            }
        }
        printf ("|\n\t");
    }
     printf("---------------------\n");



    return count == size * size - 1;
}
void play_chall()
{
    int choice;
    if (display_chall())
    {
        score_3++;
        printf("Congratulations, You Won!!");
        hardsavefile = fopen("HardCompleters.txt", "a");
        printf("\nUsername: ");
        scanf("%s", nameHard);
        printf("Enter the date (mm/dd/yyyy): ");
        scanf("%s", date_3);
        fprintf(hardsavefile, "\n%s          %d       %s", nameHard, score_3, date_3);
        fclose(hardsavefile);
        getch();
        main();

    }
    printf("Enter [%d] for reset, [%d] for menu, [%d] for exit\nEnter the number you want to move: ",
           (hard * hard), (hard * hard)+1, (hard * hard)+2);
    scanf("%d", &choice);
    if (choice == (hard * hard))
    {
        system("cls");
        chall();
        play_chall();
    }
    else if (choice == (hard * hard)+1)
    {
        main();
    }
    else if (choice == (hard * hard)+2)
    {
        exit(0);
    }
    else if (choice == (hard * hard)+3)
    {
        score_3++;
        printf("\n\nCongratulations, You Won!!");
        hardsavefile = fopen("HardCompleters.txt", "a");
        printf("\nPlease Enter your Username: ");
        scanf("%s", nameHard);
        printf("Enter the date (mm/dd/yyyy): ");
        scanf("%s", date_3);
        fprintf(hardsavefile, "\n%s          %d       %s", nameHard, score_3, date_3);
        fclose(hardsavefile);
        getch();
        main();

    }
    else
    {
        int swap, a = 0, b = 0;
        swap = choice - 0;
        if (swap >= 1 && swap <= hard * hard)
        {
            for (a = 0; a < hard; a++)
            {
                for (b = 0; b < hard; b++)
                {
                    if (diff[a][b]== swap)
                    {
                        printf("\nFOUND");
                        goto o;
                    }
                }
            }
        }
        o:
        if (b > 0) //left
        {
            if(diff[a][b -1] == 0)
            {
                // swap with left zero
                diff[a][b - 1] = diff[a][b];
                diff[a][b] = 0;
                score_3 = score_3 + 1;
                printf("\nNumber of Move\s: %i", score_3);
            }
        }
        if (b < hard - 1)
        {
            // swap right
            if(diff[a][b + 1] == 0)
            {
                diff[a][b + 1] = diff[a][b];
                diff[a][b] = 0;
                score_3 = score_3 + 1;
                printf("\nNumber of Move\s: %i", score_3);
            }

        }
        if (a > 0) //top
        {
            if(diff[a - 1][b] == 0)
            {
                // swap with left zero
                diff[a - 1][b] = diff[a][b];
                diff[a][b] = 0;
                score_3 = score_3 + 1;
                printf("\nNumber of Move\s: %i", score_3);
            }
        }
        if (a < hard - 1)
        {
            // bot
            if(diff[a + 1][b] == 0)
            {
                diff[a + 1][b] = diff[a][b];
                diff[a][b] = 0;
                score_3 = score_3 + 1;
                printf("\nNumber of Move\s: %i", score_3);
            }

        }
        if(diff[a][b] != 0)
        {
            printf("\nInvalid Move");
        }
        else if (a >= 9 || b >= 9)
        {
            printf("Wrong number");
        }
        printf("\nContinue.......");
        getch();
        system("cls");
        play_chall();
    }
}

void play_medium()
{
    int choice;
    if (display_medium())
    {
        score_2++;
        printf("\n\nCongratulations, You Won!!");
        mediumsavefile = fopen("MediumCompleters.txt", "a");
        printf("\nPlease Enter your Username: ");
        scanf("%s", nameMedium);
        printf("Enter the date (mm/dd/yyyy): ");
        scanf("%s", date_2);
        fprintf(mediumsavefile, "\n%s          %d       %s", nameMedium, score_2, date_2);
        fclose(mediumsavefile);
        getch();
        main();
    }
    printf("Enter [%d] for reset, [%d] for menu, [%d] for exit\nEnter the number you want to move: ",
           (max * max), (max * max)+1, (max * max)+2);
    scanf("%d", &choice);
    if (choice == (max * max))
    {
        system("cls");
        medium();
        play_medium();
    }
    else if (choice == (max * max)+1)
    {
        main();
    }
    else if (choice == (max * max)+2)
    {
        exit(0);
    }
    else if (choice == (max * max)+3)
    {
        score_2++;
        printf("\n\nCongratulations, You Won!!");
        mediumsavefile = fopen("MediumCompleters.txt", "a");
        printf("\nPlease Enter your Username: ");
        scanf("%s", nameMedium);
        printf("Enter the date (mm/dd/yyyy): ");
        scanf("%s", date_2);

        fprintf(mediumsavefile, "\n%s          %d       %s", nameMedium, score_2, date_2);
        fclose(mediumsavefile);
        getch();
        main();
    }
    else
    {
        int swap, a = 0, b = 0;
        swap = choice - 0;
        if (swap >= 1 && swap <= max * max)
        {
            for (a = 0; a < max; a++)
            {
                for (b = 0; b < max; b++)
                {
                    if (mid[a][b]== swap)
                    {
                        printf("\nFOUND");
                        goto o;
                    }
                }
            }
        }
        o:
        if (b > 0) //left
        {
            if(mid[a][b -1] == 0)
            {
                // swap with left zero
                mid[a][b - 1] = mid[a][b];
                mid[a][b] = 0;
                score_2 = score_2 + 1;
                printf("\nNumber of Move\s: %i", score_2);
            }
        }
        if (b < max - 1)
        {
            // swap right
            if(mid[a][b + 1] == 0)
            {
                mid[a][b + 1] = mid[a][b];
                mid[a][b] = 0;
                score_2 = score_2 + 1;
                printf("\nNumber of Move\s: %i", score_2);
            }

        }
        if (a > 0) //top
        {
            if(mid[a - 1][b] == 0)
            {
                // swap with left zero
                mid[a - 1][b] = mid[a][b];
                mid[a][b] = 0;
                score_2 = score_2 + 1;
                printf("\nNumber of Move\s: %i", score_2);
            }
        }
        if (a < max - 1)
        {
            // bot
            if(mid[a + 1][b] == 0)
            {
                mid[a + 1][b] = mid[a][b];
                mid[a][b] = 0;
                score_2 = score_2 + 1;
                printf("\nNumber of Move\s: %i", score_2);
            }

        }
        if(mid[a][b] != 0)
        {
            printf("\nInvalid Move");
        }
        else if (a >= 9 || b >= 9)
        {

             printf("\nWrong Number");

        }
        printf("\nContinue.......");
        getch();
        system("cls");
        play_medium();
    }
}

void play_easy()
{
    char name[100];
    int choice;
    if (display_easy())
    {
        score_1++;
        printf("\n\nCongratulations, You Won!!");
        easysavefile = fopen("EasyCompleters.txt", "a");
        printf("\nPlease Enter your Username: ");
        scanf("%s", nameEasy);
        printf("Enter the date (mm/dd/yyyy): ");
        scanf("%s", date_1);
        fprintf(easysavefile, "\n%s          %d       %s", nameEasy, score_1, date_1);
        fclose(easysavefile);
        getch();
        main();
    }
    printf("Enter [%d] for reset, [%d] for menu, [%d] for exit\nEnter the number you want to move: ",
           (size * size), (size * size)+1, (size * size)+2);
    scanf("%d", &choice);
    if (choice == (size * size))
    {
        system("cls");
        easy();
        play_easy();
    }
    else if (choice == (size * size)+1)
    {
        main();
    }
    else if (choice == (size * size)+2)
    {
        exit(0);
    }
    else if (choice == (size * size)+3)
    {
        score_1++;
        printf("\n\nCongratulations, You Won!!");
        easysavefile = fopen("EasyCompleters.txt", "a");
        printf("\nPlease Enter your Username: ");
        scanf("%s", nameEasy);
        printf("Enter the date (mm/dd/yyyy): ");
        scanf("%s", date_1);
        fprintf(easysavefile, "\n%s          %d       %s", nameEasy, score_1, date_1);
        fclose(easysavefile);
        getch();
        main();
    }
    else
    {
        int swap, a = 0, b = 0;
        swap = choice - 0;
        if (swap >= 1 && swap <= size * size)
        {
            for (a = 0; a < size; a++)
            {
                for (b = 0; b < size; b++)
                {
                    if (box[a][b]== swap)
                    {
                        printf("\nFOUND");
                        goto o;
                    }
                }
            }
        }
        o:
        if (b > 0) //left
        {
            if(box[a][b -1] == 0)
            {
                // swap with left zero
                box[a][b - 1] = box[a][b];
                box[a][b] = 0;
                score_1 = score_1 + 1;
                printf("\nNumber of Move\s: %i", score_1);
            }
        }
        if (b < size - 1)
        {
            // swap right
            if(box[a][b + 1] == 0)
            {
                box[a][b + 1] = box[a][b];
                box[a][b] = 0;
                score_1 = score_1 + 1;
                printf("\nNumber of Move\s: %i", score_1);
            }

        }
        if (a > 0) //top
        {
            if(box[a - 1][b] == 0)
            {
                // swap with left zero
                box[a - 1][b] = box[a][b];
                box[a][b] = 0;
                score_1 = score_1 + 1;
                printf("\nNumber of Move\s: %i", score_1);
            }
        }
        if (a < size - 1)
        {
            // bot
            if(box[a + 1][b] == 0)
            {
                box[a + 1][b] = box[a][b];
                box[a][b] = 0;
                score_1 = score_1 + 1;
                printf("\nNumber of Move\s: %i", score_1);
            }

        }
        if(box[a][b] != 0)
        {
            printf("\nInvalid Move");
        }
        else if (a >= 9 || b >= 9)
        {
            printf("\nWrong Number");
        }
        printf("\nContinue.......");
        getch();
        system("cls");
        play_easy();
    }
}

int help()
{
    printf("\033[0;35m");printf("\n\n\t\t\t\t---------Help/Instructions-----------");
    printf("\033[0;35m");printf("\n\n\t1. The player will choose what puzzle they wants to play on [easy, medium, hard].");
    printf("\033[0;35m");printf("\n\n\t2. A puzzle of his/her choosing will be displayed containing random numbers in each tile in random order, and an empty tile. ");
    printf("\033[0;35m");printf("\n\n\t3. The player will enter a number adjacent to the empty tile in order to make a move, otherwise it is an invalid mode");
    printf("\033[0;35m");printf("\n\n\t4. The player's goal is to arrange the numbers in ascending order. ");
    printf("\033[0;35m");printf("\n\n\t5. Once the puzzle is done, they will have the opportunity to enter their username with the number of moves they made to complete the puzzle,  to be recorded as one of the completers. ");
    getch();
    main();
}

void completers()
{
    int number, choic;
    printf("\n\n\n\n\n\n\t\t\t\t\t*****************************************");
    printf("\n\t\t\t\t\t|             Hall of Completers        |\n");
    printf("\n\t\t\t\t\t|[1] Easy Hall                          |\n");
    printf("\n\t\t\t\t\t|[2] Medium Hall                        |\n");
    printf("\n\t\t\t\t\t|[3] Hard Hall                          |\n");
    printf("\n\t\t\t\t\t|[4] Main Menu                          |\n");
     printf("\t\t\t\t\t*****************************************");
    printf("\n\t\t\t\t\tPlease Enter your choice: ");
    scanf("%d", &choic);

    if(choic == 1)
    {
        system("cls");
        char read;
        easysavefile = fopen("EasyCompleters.txt", "r");
        if (!easysavefile) {
        printf("Error opening EasyCompleters.txt\n");
        return 0;
        }
        printf("Username\tMoves\t    Date\n");
        do
        {
            read = fgetc(easysavefile);
            printf("%c", read);
        }while(read != EOF);
        fclose(easysavefile);
        getch();
        main();

    }
    else if(choic == 2)
    {
        system("cls");
        char read;
        mediumsavefile = fopen("MediumCompleters.txt", "r");
        if (!mediumsavefile) {
        printf("Error opening MediumCompleters.txt\n");
        return 0;
        }

        printf("Username\tMoves/t    Date\n");
        do
        {
            read = fgetc(mediumsavefile);
            printf("%c", read);
        }while(read != EOF);
        fclose(mediumsavefile);
        getch();
        main();
    }
    else if(choic == 3)
    {
        system("cls");
        char read;
        hardsavefile = fopen("HardCompleters.txt", "r");
        if (!hardsavefile) {
        printf("Error opening HardCompleters.txt\n");
        return 0;
        }

        printf("Username/tMoves/t    Date\n");
        do
        {
            read = fgetc(hardsavefile);
            printf("%c", read);
        }while(read != EOF);
        fclose(hardsavefile);
        getch();
        main();
    }
    else if(choic == 4)
    {
        main();
    }
    else
    {
        printf("Please choose from [1, 2, 3, 4] only");
        return completers();
    }
    getch();
    main();

}

int main()
{
    int choice;
    char ch;
    do{
        system("cls");
        printf("\033[0;36m");printf("\n\n\n\n\n\n\t\t\t\t**************************************************");
        printf("\033[0;36m"); printf("\n\t\t\t\t|                                                |");
        printf("\033[0;36m"); printf("\n\t\t\t\t|   <--    WELCOME TO THE TILE PUZZLE      -->   |");
        printf("\033[0;36m"); printf("\n\t\t\t\t|                                                |");
        printf("\033[0;36m");printf("\n\t\t\t\t**************************************************");
        printf("\033[0;31m"); printf("\n\n\t\t\t\tPress 1. Start Game");
        printf("\033[0;32m"); printf("\n\n\t\t\t\tPress 2. Leaderboard");
        printf("\033[0;35m");printf("\n\n\t\t\t\tPress 3. Help/Instructions");
        printf("\033[0;33m");printf("\n\n\t\t\t\tPress 4. Exit");
        printf("\033[0;36m");printf("\n\n\n\t\t\t\tEnter your choice from 1 to 4 only: ");
        scanf("%i",&choice);
        switch(choice)
        {
            case 1: system("cls");

            printf("\n\n\n\n\n\n\t\t\t\t\t**********************************");
            printf("\n\t\t\t\t\t|<--         [E] EASY         -->|");
            printf("\n\n\t\t\t\t\t|<--         [M] MEDIUM       -->|");
            printf("\n\n\t\t\t\t\t|<--         [H] HARD         -->|");
            printf("\n\t\t\t\t\t**********************************");
            printf("\n\n\t\t\t\t\tSelect Difficulty: ");
            scanf(" %c", &ch);
            switch(ch)
                {
                    case 'E':  system("cls"); loading(); system("cls");score_1 = 0; printf("\033[0;36m"); easy(); play_easy(); getch(); main();
                    case 'e':  system("cls"); loading(); system("cls");score_1 = 0; printf("\033[0;36m"); easy(); play_easy(); getch(); main();
                    case 'M':  system("cls"); loading(); system("cls");score_2 = 0; printf("\033[0;32m"); medium(); play_medium(); getch(); main();
                    case 'm':  system("cls"); loading(); system("cls");score_2 = 0; printf("\033[0;32m"); medium(); play_medium(); getch(); main();
                    case 'H':  system("cls"); loading(); system("cls");score_3 = 0; chall(); play_chall(); getch(); main();
                    case 'h':  system("cls"); loading(); system("cls");score_3 = 0; chall(); play_chall(); getch(); main();
                }
            case 2: system("cls"); completers();
            case 3: system("cls"); help();
            case 4: exit(0); break;
            default: printf("Invalid choice. Please try again (1 - 4)."); getch();
        }
    }while(choice != 4);
}



