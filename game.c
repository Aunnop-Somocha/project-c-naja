#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#define SIZE 10// เกมงู
#define MAX_PLAYERS 2 // เกมงู

void set_color(int color){
    printf("\033[1;%dm",color);
}

// คำสั่งรีสีให้กลับมาเป็นเหมือนเดิม
void reset_color(){
    printf("\033[0m");
}
// เกมใบ้คำ
struct guess_world
{
    char Hint[200]; 
    char Answer[100]; 
};
//เกมงู
int Head_snack[] = {13,23,25,48,51,63,82,91,98}; 
int tail_snack[] = {10,19,3,34,29,60,80,88,85}; 
int ladder[] ={2,6,12,24,32,42,45,71};
int up_ladder[] = {21,67,30,38,94,100,83,92};

// สำหรับเกม xo
void showtable(char table[4][4]){ 
    for (int i = 1; i < 4; i++)
    {
        for (int j = 1; j < 4; j++)
        {
            printf("%c ",table[i][j]);
        }
        printf("\n");
    }
};

void play_xo_game(){
    char user1 = 'X',user2 = 'O';
    int r,c; 
    printf("User1 = X\n");
    printf("User2 = O\n");
    printf("\n********Table***************\n");
    char table[4][4] = {{'.','.','.','.'}, 
                        {'.','H','H','H'},
                        {'.','H','H','H'},
                        {'.','H','H','H'}};
    showtable(table);
    for (int i = 0; i < 30; i++)
    {
        r = 0, c = 0;
        while (table[r][c] == 'H' || table[r][c] == '.'  || table[r][c] == 'O'|| table[r][c] == 'X')
        {
            reset_color();
            printf("User1 Chose: ");
            scanf(" %d %d",&r,&c);
            if (table[r][c] == 'H')
            {
                table[r][c] = user1;
                set_color(31);
                break;
            }else
            {
                printf("Please Chose again\n");
            } 
        }
        showtable(table);
            if ((table[1][1] == user1 && table[1][2] == user1 && table[1][3] == user1) || 
            (table[2][1] == user1 && table[2][2] == user1 && table[2][3] == user1) || 
            (table[3][1] == user1 && table[3][2] == user1 && table[3][3] == user1) ||
            (table[1][1] == user1 && table[2][1] == user1 && table[3][1] == user1)||
            (table[1][2] == user1 && table[2][2] == user1 && table[3][2] == user1)||
            (table[1][3] == user1 && table[2][3] == user1 && table[3][3] == user1)||
            (table[1][1] == user1 && table[2][2] == user1 && table[3][3] == user1)||
            (table[1][3] == user1 && table[2][2] == user1 && table[3][1] == user1)  )
        {
            printf("\nUser 1 win!!!!!\n");
            break;
        }
        r = 0, c = 0;
        while (table[r][c] == 'H' || table[r][c] == '.' || table [r][c] =='X' || table[r][c] == 'O' ){
            reset_color();
            printf("User2 Chose: ");
            scanf(" %d %d",&r,&c);
            if (table[r][c] == 'H')
            {
                table[r][c] = user2;
                set_color(34);
                break;
            }else
            {
                printf("Please Chose again\n");
            }
        }
        showtable(table);
            if((table[1][1] == user2 && table[1][2] == user2 && table[1][3] == user2) || 
            (table[2][1] == user2 && table[2][2] == user2 && table[2][3] == user2) || 
            (table[3][1] == user2 && table[3][2] == user2 && table[3][3] == user2) ||
            (table[1][1] == user2 && table[2][1] == user2 && table[3][1] == user2)||
            (table[1][2] == user2 && table[2][2] == user2 && table[3][2] == user2)||
            (table[1][3] == user2 && table[2][3] == user2 && table[3][3] == user2)||
            (table[1][1] == user2 && table[2][2] == user2 && table[3][3] == user2)||
            (table[1][3] == user2 && table[2][2] == user2 && table[3][1] == user2)  )
        {
            printf("\nUser 2 win!!!!!\n");
            break;
        }
    }
printf("\n************endgame************\n");
}

void play_Guess_numbergame(){
    srand(time(0)); // เพื่อให้รันใหม่แล้วเลขเปลี่ยนทุกครั้ง
    int numberrandom = (rand() % 100) + 1 ;
    int numuser,round = 0;   // round แทนจำนวนรอบที่เล่น
    while (numuser != numberrandom) 
    {
        printf("Input number: ");
        scanf("%d",&numuser);
        if (numuser == numberrandom)
        {
            set_color(33);
            printf("Correct!!!!!\n");
            reset_color();
            round += 1;
            printf("Selected  %d  time\n",round);
            break;
        }
        else if (numuser > numberrandom)
        {
            set_color(31);
            printf("more than:\n");
            reset_color();
            round += 1;
        }else
        {
            set_color(32);
            printf("less\n");
            reset_color();
            round += 1;
        }   
    }
    printf("*************Endgame*************");
}

int rol(){
    return ((rand() % 10) + 0);
}

void play_Guess_the_word(){
    char user_text ; // ตัวอักษรจาก user 
    int Heart = 10; // หัวใจ คือ โอกาสในการตอบผิด ถ้าผิดจะลบทีละ 1 
    int totalQuestion = 10; // เอามาใช้ให้ loop while หยุดได้แม่นขึ้น
    int CorrectAnswer = 0; // เอามาใช้ให้ loop while หยุดได้แม่นขึ้น
    struct guess_world questions[10] = { // ตัวแรกจะถูกเก็บไว้ใน Hint คำใบ้  ตัวสองจะถูกเก็บไว้ใน Answer  (printf("%s",questions[0].Answer);) เวลาจะprintf
        {"It's sweet, comes from bees, and is golden in color.", "honey"},
        {"It's big, gray, has a trunk, and lives in the jungle.", "elephant"},
        {"It's cold, made of water, and melts in the sun.", "ice"},
        {"It's a fruit that is red, round, and often used to make ketchup.", "tomato"},
        {"It's a type of matter that doesn't have a fixed shape or volume, and it's made of particles that move freely.", "gas"},
        {"It's a chemical element with the symbol 'Au', and it's often used in jewelry and as currency.", "gold"},
        {"It is a celestiatl body that orbits a planet and reflects sunlight at night.", "moon"},
        {"It is the largest ocean on Earth, covering more area than all landmasses combined.", "pacific"},
        {"This large land mammal has a thick skin and is known for its horn on its nose.", "rhinoceros"},
        {"It is the longest river in the world, flowing through multiple countries in Africa.", "nile"}
    };
    while (Heart > 0 && CorrectAnswer < totalQuestion)
    {
        srand(time(NULL));
        int ro = rol();
        int len = strlen(questions[ro].Answer);
        char display[len + 1];
        for (int i = 0; i < len; i++)
        {
            display[i] = '_';
        }
        display[len] = '\0'; 
        printf("***** Question %d *****\n",CorrectAnswer + 1); // show ว่าคำถามที่เท่าไหร่แล้ว
        printf("%s\n",questions[ro].Hint); // show คำใบ้
        while ((strchr(display,'_')) && Heart > 0) // strchr คือค้นหาตัวอักษร '_' ใน display loop นี้ จะทำต่อจนกว่าจะไม่มี _ หรือ Heart จะไม่มากกว่า 0
        {
            printf("%s\n",display);
            printf("Enter a Answer: ");
            scanf(" %c",&user_text);
            user_text = tolower(user_text);
            int correctGuess = 0;
            for (int i = 0; i < len; i++)
            {
                if (tolower(questions[ro].Answer[i]) == user_text) // question[CorrectAnswer] คือดูว่าอยู่ข้อไหน
                {
                    display[i] = questions[ro].Answer[i]; // ถ้าตอบถูกให้ display ถูกแทนด้วยตัวที่ตอบถูก เช่นข้อ 1 ตอบ h ถูก นำ h แทน '_'
                    correctGuess = 1; // เอาไว้เช็คถ้ากรณีตอบ ถูกให้เป็น 1 แต่ถ้าตอบผิดมันจะเป็น 0 เหมือนกับที่ถูกประกาศไว้ด้านบน เมื่อเป็น 0 จะได้เข้ากับเงื่อนไขตอบผิดด้านล่าง หาก ไม่กำหนดให้เป็น 1 จะเข้าเงื่อนไขล่างด้วย
                }   
            }
            // เมื่อตอบผิด ให้ ลบหัวใจ ออก 1 
            if (!correctGuess)
            {
                Heart--;
                printf("Wrong! you have %d hearts\n",Heart);
            }
        }
        if (!strchr(display,'_')) // ถ้า strchr หา '_' ใน display ไม่เจอ ให้ทำเงื่อนไข
        {
            printf("Correct! the word is %s\n",questions[ro].Answer); // show คำที่ถูกว่าคืออะไร
            CorrectAnswer++;
        }
    }
    if(CorrectAnswer == totalQuestion)
        {
            printf("Congratulations! You answered all questions correctly.\n");
        }else // กรณีที่ Heart < 0 ก็ จบเหมือนกัน
        {
            printf("Game Over!\n");
        }
}

void show_boardgame_snack(int positipms[MAX_PLAYERS]){
    int board[SIZE][SIZE];
    int num = 100; 
    for (int i = 0; i < SIZE; i++)
    {
        if (i % 2 == 0)
        {
            for (int j = 0 ; j < SIZE; j++) // 0--> 9
            {
                board[i][j] = num--;
            }
        }else // แถวเลขคู่
        {
            for (int j = SIZE - 1; j >= 0; j--) 
            {
                board[i][j] = num--;
            }
        }
    }
    //แสดงตาราง
    for (int i = 0; i < SIZE; i++)
    {
        printf("|"); 
        for (int j = 0; j < SIZE; j++)
        {
            int player1_here = (board[i][j] == positipms[0]);
            int player2_here = (board[i][j] == positipms[1]);
            // แสดงตำแหน่งผู้เล่น
            if (player1_here && player2_here)
            {
                set_color(36);
                printf("P1P2|");
                reset_color();
            }else if (player1_here)
            {
                set_color(34);
                printf(" P1 | ");
                reset_color();
            }else if (player2_here)
            {
                set_color(35);
                printf(" P2 | ");
                reset_color();
            }
            // นี้คือ set สีช่อง 31 เป็นสีแดง จะกำหนดให้สีแดงเป็นหัวงูไว้ ตก เหลือสร้างสีเขียวไว้เป็นทางขึ้น สีทองจะเป็นเส้นชัย   (32 จะเป็นสีเขียว)
            else if (board[i][j] == 13 || board[i][j] == 23 || board[i][j] == 25 || board[i][j] == 48 || board[i][j] == 51 || board[i][j] == 63 || board[i][j] == 82 ||board[i][j] == 91 || board[i][j] == 98 )
            {
               set_color(31); // เปลี่ยนเป็นสีแดง
               printf("%3d | ",board[i][j]);
               reset_color(); // ต้องรีกลับให้มาเป็นสีเดิมด้วยไม่นั้นตัวเลขหลังจากนั้นจะติดสีอื่นนี้ไปด้วย
        
            }
            else if (board[i][j] == 100) // เปลี่ยนสีตำแแหน่งเส้นชัย
            {
                set_color(33); //เปลี่ยนเป็นสีเหลือง
                printf("%3d | ",board[i][j]);
                reset_color();
            }
            
            //ท่อนเปลี่ยนสีเอาไว้แสดงตำแหน่งที่เป็นบรรได ถ้าลงช่องนี้จะขึ้นไปที่ตำแหน่งไหน (สีฟ้าคือตำแหน่งที่สีเขียวจะขึ้นไปถึง)
            else if (board[i][j] == 2 || board[i][j] == 6 || board[i][j] == 12 || board[i][j] == 24 ||  board[i][j] == 32 ||  board[i][j] == 42 ||  board[i][j] == 45 ||  board[i][j] == 71 )
            {
                set_color(32); // เปลี่ยนเป็นสีเขียว
                printf("%3d | ",board[i][j]);
                reset_color();
            }
            // ตำแหน่งปกติ ที่ไม่ได้เป็นบรรไดหรือหัวงู
            else
            {
                printf("%3d |",board[i][j]);
            }    
        }
        printf("\n===================================================\n");
    }
}

int roll(){
    return (rand() % 6) + 1 ;
} 

int check_snake_or_kadder(int position){
    for (int i = 0; i < 9 ; i++)
    {
        // เช็คว่าตกหัวงูไม่
        if (position == Head_snack[i])
        {
            printf("no!!! Snake at %d. go down to %d!\n",position,tail_snack[i]); // ใช้แบบนี้ได้เลยเพราะเราเรียงตำแหน่ง array ให้เท่ากันอยู่แล้วแบบลง 13ก็ ไป10 ได้เลย
            return tail_snack[i]; // เปลี่ยนตำแหน่งไปหางงูแทน
        }
    }
    for (int i = 0; i < 8 ; i++)
    {
        //เช็คว่าตกช่องบรรไดไม่
        if (position == ladder[i])
        {
            printf("Wow let's go Ladder at %d. go up to %d!\n",position,up_ladder[i]);
            return up_ladder[i];
        }
    }
    return position; //กรณีไม่ตกทั้งหัวงูและบรรได ให้อยู่ตำแหน่งเดิม
}

void play_game_snack(){
    int positions[MAX_PLAYERS] = {1,1};
    int turn = 0;
    srand(time(NULL));
    while (1) //วนเรื่อยๆ
    {
        
        getchar();
        system("cls");
        show_boardgame_snack(positions); // show board game
        printf("\nplayer %d's turn . Press enter to roll.. ",turn +1);
        getchar(); // รับ user กด enter
        int dice = roll(); // ทอยลูกเต๋า
        printf("Player %d rolled a %d\t",turn+1,dice);
        positions[turn] += dice; // update ตำแหน่งผู้เล่น
        printf("player %d at Channel %d\n",turn+1,positions[turn]);
        if (positions[turn] > 100)
        {
            positions[turn] -= dice; //กรณีทอยแล้วตำแหน่งเกิน 100 จะไม่นับการทอยครั้งนั้น
        }
        positions[turn] = check_snake_or_kadder(positions[turn]); // ส่งค่าไป check กับตำแหน่งว่าลงหัวงูหรือบรรไดไม่
        if (positions[turn] == 100)
        {
            printf("\nPlayer %d win!!!!!\n",turn+1);
            break;  
        }
        turn = (turn + 1) % MAX_PLAYERS; // สลับturn ผู้เล่น 0,1 ไปมา
    }
}

int main(){
    int chosen = 1 ;
    do{
    set_color(35);
    if (chosen < 1 || chosen > 4)
    {
        printf("wrong number please select again\n");
    }
    printf("Welcome to game!!!!\n");
    printf("Choose please select game:\n");
    reset_color();
    
    set_color(33);
    printf("1: Xo game\n");
    reset_color();
    
    set_color(34);
    printf("2: Guess number game\n");
    reset_color();
    
    set_color(31);
    printf("3: Guess The Word\n");
    reset_color();
    
    set_color(32);
    printf("4: Board Game Snack\n");
    reset_color();
    
    scanf("%d",&chosen);
    system("cls");
    }while(chosen < 1 || chosen > 4);
    switch (chosen)
    {
    case 1:
        play_xo_game();
        break;
    case 2:
        set_color(36);
        printf("Welcome to game Guess_number\n");
        reset_color();
        play_Guess_numbergame();
        break;
    case 3:
        set_color(33);
        printf("Welcome to Guess the word game\n");
        reset_color();
        play_Guess_the_word();
        break;
    case 4:
        play_game_snack();
        break;
    default:
        printf("Please chossen again");
        break;
    }
}
