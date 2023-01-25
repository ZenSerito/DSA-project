#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include<MMsystem.h>
#include<graphics.h>
#include<dos.h>
#include<process.h>

char square[10]={'O','1','2','3','4','5','6','7','8','9'};
char Dsquare[10]={'O','1','2','3','4','5','6','7','8','9'};
char* squareptr=square;
char playerone[20],playertwo[20];

int checkWin();
void drawBoard();
void namescreen();
void tictactoescr(int ctrl);
void instructionscr();
void Loadingscreen();
void gotoxy(int x,int y);

int main()
{
    FILE* fp;
    fp = fopen("GameRecord.txt","ab");
    Loadingscreen();
    instructionscr();
    namescreen();
    Beginning:
        for(int i=0;i<=9;i++)
        {
            *(squareptr+i) = Dsquare[i];
        }

    system("color b0");

    int player=1,i,j,choice,again;
    char pl_name[100];
    char ch[50];
    char mark;     // X, O

    do{
        drawBoard();
        player = (player % 2) ? 1 : 2;
        mark = (player == 1) ? 'X' : 'O';
        if(player == 1)
        {
           strcpy(pl_name,playerone);
        }
        else{
            strcpy(pl_name,playertwo);
        }
         printf("\t\t\t    %s, mark (%c) Enter the choice from above positions : ",pl_name,mark);
        scanf("%d",&choice);


        if(player == 1){
        PlaySound(TEXT("C:\\Users\\DELL\\Music\\pencilcut.wav"),NULL,SND_SYNC);
        system("color 3f");}
        else{
            PlaySound(TEXT("C:\\Users\\DELL\\Music\\circle.wav"),NULL,SND_SYNC);
            system("color 8f");
        }

        if(choice == 1 && square[1] == '1')
            square[1] =mark;
        else if(choice == 2 && square[2] == '2')
            square[2] = mark;
        else if(choice == 3 && square[3] == '3')
            square[3] = mark;
        else if(choice == 4 && square[4] == '4')
            square[4] = mark;
        else if(choice == 5 && square[5] == '5')
            square[5] = mark;
        else if(choice == 6 && square[6] == '6')
            square[6] = mark;
        else if(choice == 7 && square[7] == '7')
            square[7] = mark;
        else if(choice == 8 && square[8] == '8')
            square[8] = mark;
        else if(choice == 9 && square[9] == '9')
            square[9] = mark;

        else {
                system("color 65");
            printf("\t\t\t\t\t\t Invalid Option !!\n");
            printf("\a\a");
            delay(1200);
             printf("\t\t\t\t\t\t Invalid Option !!\n");
            delay(600);
            printf("\t\t\t\t\t\t Invalid Option !!");
             delay(800);
            player--;
        }
        i=checkWin();
        player++;

    }while(i == -1);

    drawBoard();
    if(i==1){
        printf("\t\t\t\t\t   ==>> %s WON <<==\n\n\n\n",pl_name);
        system("color c0");
        fprintf(fp,"\n-%c %6s VS %6s      || %8s WON ",3,playerone,playertwo,pl_name);
        PlaySound(TEXT("C:\\Users\\DELL\\Music\\winsound.wav"),NULL,SND_SYNC);
        delay(1000);
    }
    else{
        printf("\t\t\t\t\t     ==>> Game Draw <<==\n\n\n\n");
        system("color 3f");
        fprintf(fp,"\n-%c %6s VS %6s      ||      DRAW ",5,playerone,playertwo);
        PlaySound(TEXT("C:\\Users\\DELL\\Music\\lose.wav"),NULL,SND_SYNC);
         delay(1000);
    }
    system("color 3f");
    printf("If You Wanna Play Again (Press 1) : ");
    scanf("%d",&again);
    if(again == 1)
    {
        system("cls");
        tictactoescr(-40);
        gotoxy(35,16);
        printf("Do You Wanna Play Again With :\n");
        gotoxy(35,18);
        printf("Current Players(Press 1) OR Different Players(Press 2) : ");
         scanf("%d",&again);
         if(again == 1)
            {
        goto Beginning;
        }
        else
        {
            namescreen();
            goto Beginning;
        }

    }
    fprintf(fp,"\n-----------------------------------------------------");
    fclose(fp);
    system("cls");
    fp = fopen("GameRecord.txt","rb");
    while(fgets(ch,100,fp))
    {
        printf("\t\t\t\t\t%s\n",ch);
    }

fclose(fp);
    system("color e0");
    return 0;
}
int checkWin(){
if(square[1] == square[2] && square[2] == square[3])
    return 1;
else if(square[4] == square[5] && square[5] == square[6])
    return 1;
else if(square[7] == square[8] && square[8] == square[9])
    return 1;
else if(square[1] == square[4] && square[4] == square[7])
    return 1;
else if(square[2] == square[5] && square[5] == square[8])
    return 1;
else if(square[3] == square[6] && square[6] == square[9])
    return 1;
else if(square[1] == square[5] && square[5] == square[9])
    return 1;
else if(square[3] == square[5] && square[5] == square[7])
    return 1;
else if(square[1] != '1' && square[2] != '2' && square[3] != '3' && square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7] != '7' && square[8] != '8' && square[9] != '9')
     return 0;
else
    return -1;
}

void drawBoard(){
system("cls");
printf("\n\n\t\t\t\t\t\t Tic Tac Toe \n\n");
printf("\t\t\t\t\t %8s (X) VS%7s (O) \n\n\n",playerone,playertwo);
printf("\t\t\t\t\t           |     |     \n");
printf("\t\t\t\t\t        %c  |  %c  |  %c  \n",square[1],square[2],square[3]);
printf("\t\t\t\t\t      _____|_____|_____     \n");
printf("\t\t\t\t\t           |     |     \n");
printf("\t\t\t\t\t        %c  |  %c  |  %c  \n",square[4],square[5],square[6]);
printf("\t\t\t\t\t      _____|_____|_____     \n");
printf("\t\t\t\t\t           |     |     \n");
printf("\t\t\t\t\t        %c  |  %c  |  %c  \n",square[7],square[8],square[9]);
printf("\t\t\t\t\t           |     |     \n\n\n");

}
void Loadingscreen()
{
    int r,q;
    system("color 5b");
    gotoxy(55,12);
    printf("LOADING...");

    gotoxy(46,14);
    for(r=1;r<=14;r++)
    {
     delay(260);
        for(q=0;q<=1;q++)
        {
            printf("%c",178);
        }

    }
    PlaySound(TEXT("C:\\Users\\DELL\\Music\\loading.wav"),NULL,SND_SYNC);
    delay(50);



}
void namescreen()
{
    system("cls");
    system("color af");
    tictactoescr(-50);
    PlaySound(TEXT("C:\\Users\\DELL\\Music\\name.wav"),NULL,SND_SYNC);
    gotoxy(35,14);
    printf("Enter the name of 1st Player : ");
    scanf("%s",playerone);
    gotoxy(35,16);
    printf("Enter the name of 2nd Player : ");
    scanf("%s",playertwo);
    PlaySound(TEXT("C:\\Users\\DELL\\Music\\vsst.wav"),NULL,SND_SYNC);
    system("cls");
    system("color f0");
    system("color 0f");
    system("color af");
    system("cls");
}

void gotoxy(int x,int y)
{
    COORD coord;
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
void instructionscr()
{
    system("color b0");
    system("cls");
    tictactoescr(-20);
    gotoxy(6,9);
    printf("Instructions:\n");
     gotoxy(6,11);
    printf("1) You will be given mark(X) or (O).");
     gotoxy(6,13);
    printf("2) You have to choose a position (from 1 to 9) from");
     gotoxy(6,15);
    printf("above boxes to where you wanna place your mark.");
     gotoxy(6,17);
    printf("3) Try to complete the linear pattern in any direction");
     gotoxy(6,19);
    printf("faster than your opponent.");
     gotoxy(6,21);
    printf("4) So be aware of all your as well as your opponent");
     gotoxy(6,23);
    printf("moves.");

    delay(8000);
}
void tictactoescr(int ctrl)
{
int i;
system("cls");

printf("   ");
//t ///////////////////////
for(i=0;i<13;i++)  // - above one
{
    delay(60+ctrl);
    printf("%c",176);
}
for(i=0;i<5;i++) // | down
{
    gotoxy(8,1+i);
    delay(60+ctrl);
    printf("%c%c",178,177);
}
//i  ////////////////////////////

for(i=0;i<3;i++)
{
    gotoxy(17,3+i);
    delay(60+ctrl);
    printf("%c%c",177,177);
}
gotoxy(17,1);//.
printf("%c%c",178,177);

//c  ////////////////////////////
gotoxy(23,2);
for(i=0;i<8;i++) // - above one
{
    delay(60+ctrl);
    printf("%c",176);
}

for(i=0;i<3;i++) // | down before
{
    gotoxy(23,3+i);
    delay(60+ctrl);
    printf("%c%c",177,178);
}

gotoxy(25,5); // - below one
for(i=0;i<6;i++)
{
    delay(60+ctrl);
    printf("%c",176);
}

// 2nd t   ///////////////////////////////
gotoxy(36,0);
for(i=0;i<13;i++)
{
    delay(60+ctrl);
    printf("%c",176);
}
for(i=0;i<5;i++)
{
    gotoxy(41,1+i);
    delay(60+ctrl);
    printf("%c%c",177,177);
}

//a  ////////////////////////////////
gotoxy(49,2);  //- above one
for(i=0;i<8;i++)
{
    delay(60+ctrl);
    printf("%c",176);
}
for(i=0;i<3;i++)   //| before one
{
    gotoxy(49,3+i);
    delay(60+ctrl);
    printf("%c%c",177,178);
}
gotoxy(51,5);  //- below one
for(i=0;i<9;i++)
{
    delay(60+ctrl);
    printf("%c",176);
}
printf("%c",178);
for(i=0;i<3;i++)  //|  later ones
{
    gotoxy(57,2+i);
    delay(60+ctrl);
    printf("%c%c",178,177);
}

//2nd c   ////////////////////////////////////
gotoxy(62,2); //-
for(i=0;i<8;i++)
{
    delay(60+ctrl);
    printf("%c",176);
}

for(i=0;i<3;i++)  // |
{
    gotoxy(62,3+i);
    delay(60+ctrl);
    printf("%c%c",177,177);
}

gotoxy(64,5);  //-
for(i=0;i<6;i++)
{
    delay(60+ctrl);
    printf("%c",176);
}

//3rd t   ///////////////////////////////
gotoxy(75,0);
for(i=0;i<13;i++)
{
    delay(60+ctrl);
    printf("%c",176);
}
for(i=0;i<5;i++)
{
    gotoxy(80,1+i);
    delay(60+ctrl);
    printf("%c%c",177,178);
}

//o  ////////////////////////////////
gotoxy(89,2);  //-
for(i=0;i<8;i++)
{
    delay(60+ctrl);
    printf("%c",176);
}
for(i=0;i<3;i++)   //|
{
    gotoxy(89,3+i);
    delay(60+ctrl);
    printf("%c%c",177,178);
}
gotoxy(91,5);  //- below one
for(i=0;i<7;i++)
{
    delay(60+ctrl);
    printf("%c",176);
}
for(i=0;i<3;i++)  //| later one
{
    gotoxy(96,2+i);
    delay(60+ctrl);
    printf("%c%c",178,177);
}

//e  ////////////////////////////////
gotoxy(100,1);  //- above one
for(i=0;i<6;i++)
{
    delay(60+ctrl);
    printf("%c",176);
}
for(i=0;i<4;i++)   //| before one
{
    gotoxy(100,2+i);
    delay(60+ctrl);
    printf("%c%c",177,178);
}

gotoxy(102,3);  //- middle one
for(i=0;i<6;i++)
{
    delay(60+ctrl);
    printf("%c",176);
}

for(i=0;i<2;i++)  //|  later ones
{
    gotoxy(106,1+i);
    delay(60+ctrl);
    printf("%c%c",178,177);
}
gotoxy(102,5);  //- below one
for(i=0;i<8;i++)
{
    delay(60+ctrl);
    printf("%c",176);
}
delay(60+ctrl);
}
