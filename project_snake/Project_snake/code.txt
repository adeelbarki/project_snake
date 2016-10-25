#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <termios.h>
#include <tar.h>
#define BLU "\x1B[34m"
#define CYN "\x1B[36m"
#define RED "\x1B[31m"
#define N 20
#define M 40


int main()
{
    int Field [N][M], i, j, x, y, speed, Gy, Tail, Head, Game, Frogs, score, a, b, highscore;
    char pos, Var;

    printf( CYN "\n");
    printf("\n \n \n \n \n                            Snake Game    \n \n");
    printf("                      Copyright: Adeel Barki. \n");
    printf("                            Have Fun!   \n \n \n \n \n") ;
    //system("Pause");
    char pb;
    struct termios tcattr;
    //Spacing of the ellipsis
    printf("Press any key to continue..... \n");
    tcgetattr(0, &tcattr);
    //Disable canonical mode, assumes we want line buffering
    tcattr.c_lflag &= ~ICANON;
    tcattr.c_cc[VTIME] = 0;
    tcattr.c_cc[VMIN] = 1;
    //Engage now
    tcsetattr(0, TCSANOW, &tcattr);
    read(0, &pb, 1);
    system("clear");


    FILE *f;
    void snakeinitialization(){

        f =fopen ("high.txt", "r");
        fscanf(f,"%d",&highscore);
        fclose(f);

        for(i=0; i<N; i++){
                for(j=0; j<M; j++){
                Field[i][j]=0;

                }
        }
    x = N/2; y = M/2; speed=99; Head = 5; Tail =1; score=0; Frogs =0;
    Gy=y; pos ='d'; Game =0;
    for(i=0; i<Head; i++){

    Gy++;
    Field[x][Gy-Head]= i+1;

    }
}
    void TailRemove(){

        for(i=0; i<N; i++){
            for(j=0; j<M; j++){
                if(Field[i][j] == Tail){
                    Field[i][j] = 0;
                }
            }
        }
        Tail++;
    }

    int getch_noblock(){
        if(_kbhit())
            return -getch();
        else
            return -1;

    }

    void Random(){
        a = 1 + rand()%17;
        b = 1 + rand()%37;
        if(Frogs == 0 & Field [a][b] == 0){
            Field [a][b] = -1;
            Frogs = 1;
            if (speed > 10 && score !=0)
            speed--;
        }


    }

    void Print(){
        for(i=0; i<=M+1; i++){
            if(i == 0) printf("%c", 201);
            else if (i == M+1) printf("%c", 187);
            else printf("%c, 205");
        }

        printf("Current score: %d        HighScoree: %d", score, highscore);
        printf("\n");

        for(i=0; i<N; i++){

            printf("%c", 186);
            for(j=0; j<M; j++){

                if(Field[i][j] == 0) printf(" ");
                if(Field[i][j] > 0 && Field[i][j] != Head)
                    printf("%c", 176);

                if(Field[i][j] == Head)
                    printf("%c", 178);
                if(Field[i][j] == -1)
                    printf("%c", 15);
                if(j == M-1)
                    printf("%c", 186);

            }
        }

        for(i=0; i<=M+1; i++){
            if(i==0)
                printf("%c", 200);
            else if(i == M+1)
                printf("%c", 188);
            else
                printf("%c, 205");

        }
    }

    void GameOver(){
        printf("\a");
        sleep(1500);
        system("Clear");
        if(score>highscore)
        {
            printf("New Highscore %d!!! \n \n", score);
            //system("pause")

    //Spacing of the ellipsis
            tcgetattr(0, &tcattr);
    //Disable canonical mode, assumes we want line buffering
            tcattr.c_lflag &= ~ICANON;
            tcattr.c_cc[VTIME] = 0;
            tcattr.c_cc[VMIN] = 1;
    //Engage now
            tcsetattr(0, TCSANOW, &tcattr);
            read(0, &pb, 1);

            f = fopen("high.txt", "w");
            fprintf(f, "%d", score);
            fclose(f);
            }
        system("Clear");

        printf("                      Game Over!! \n \n");
        printf("                       Score %d \n\n", score);
        printf("Press Enter to play again or Esc to Exit... \n");

        while(1){
            Var = getch_noblock();
            if(Var == 13){

                Game = 0;
                snakeinitialization();
                break;
            }
            else if (Var == 27){
                Game = 1;
                break;
            }
        }
        system("Clear");

    }

    void Pozition(){

        Var = getch_noblock();
        Var = tolower(Var);  //undeclared
        if(((Var == 'd' || Var == 'a') || (Var == 'w' || Var == 's')) && (abs(pos-Var)>5))
            pos = Var;
        if(pos == 'd'){
            y++;
            if(Field[x][y] !=0 && Field[x][y] != -1)
                GameOver();
            if(y==M)
                y =0;
            if(Field[x][y]==-1){
                score = score+5;
                Tail--;
                Tail--;
                Frogs = 0;
            }
        Head++;
        Field[x][y] = Head;
        }

        if(pos=='a'){
            y--;
            if(y==-1)
                y = M-1;
            if(Field[x][y] == -1)
            {
                score = score +5;
                Tail--;
                Tail--;
                Frogs =0;
            }
        Head++;
        Field[x][y] = Head;

        }

        if(pos == 'w'){

            x--;
            if(x == -1)
                x = N-1;
            if (Field[x][y] != 0 && Field[x][y] != -1)
                GameOver();
            if(Field[x][y] == -1){
                score = score+5;
                Tail--;
                Tail--;
                Frogs=0;
            }
            Head++;
            Field[x][y] = Head;

        }

        if(pos == 's'){
            x++;
            if(x==N)
                x=0;
            if(Field[x][y] != 0 && Field[x][y] != -1)
                GameOver();
        if(Field[x][y] == -1){
            score = score+5;
            Tail--;
            Tail--;
            Frogs = 0;
        }

        }
    }

    if(pos == 'a')
    {

    }

    /*void ResetScreenPosition(){
        HANDLE hOut;
        COORD Position;
        hout = GetStdHandle(STD_OUTPUT_HANDLE);
        Position.X = 0;
        Position.Y 0;
        SetConsolePosition(hout, Position);
    }*/
    snakeinitialization();
    while(Game == 0){

    Print();
    Random();
    Pozition();
    TailRemove();
    sleep(speed);
    //ResetScreenPosition();
    }

    return 0;
}
