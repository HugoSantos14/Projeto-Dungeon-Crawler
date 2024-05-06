#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <string.h>
#include <time.h>

int i, j;
int player_i, player_j;
int monster_i, monster_j;
int hp = 30;
int hp_max = 30;
char cheat[10];
char fase1[15][15] = 

{
	//0    1    2    3    4    5    6    7    8    9    10   11   12   13   14
    {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*'}, //0
    {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'}, //1
    {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'}, //2
    {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', ' ', ' ', ' ', '*'}, //3
    {'*', '*', '*', '*', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'}, //4
    {'*', '*', '*', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'}, //5
    {'*', '*', '*', '*', '*', ' ', ' ', ' ', ' ', ' ', '*', '*', ' ', '*', '*'}, //6
    {'*', '*', '*', '*', '*', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', '*'}, //7
    {'*', '*', '*', '*', '*', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', '*'}, //8
    {'*', '*', '*', '*', '*', ' ', ' ', ' ', ' ', ' ', '*', ' ', '@', ' ', '*'}, //9
    {'*', '*', '*', '*', '*', ' ', ' ', ' ', ' ', ' ', '*', '*', '*', '*', '*'}, //10
    {'*', '*', '*', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'}, //11
    {'*', '*', '*', '*', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'D'}, //12
    {'*', '*', '*', '*', '*', '*', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'}, //13
    {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*'}, //14
};

char fase2[30][30] =

{
	//0    1    2    3    4    5    6    7    8    9    10   11   12   13   14   15   16   17   18   19   20   21   22   23   24   25   26   27   28   29
	{'*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*'}, //0
	{'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'}, //1
	{'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'}, //2
	{'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'}, //3
	{'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'}, //4
	{'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'}, //5
	{'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'}, //6
	{'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'}, //7
	{'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'}, //8
	{'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'}, //9
	{'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'}, //10
	{'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'}, //11
	{'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'}, //12
	{'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'}, //13
	{'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'}, //14
	{'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'}, //15
	{'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'}, //16
	{'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'}, //17
	{'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'}, //18
	{'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'}, //19
	{'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'}, //20
	{'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'}, //21
	{'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'}, //22
	{'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'}, //23
	{'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'}, //24
	{'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'}, //25
	{'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'}, //26
	{'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'}, //27
	{'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'}, //28
	{'*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*'}, //29
};

void linhaCol(int lin, int col){
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){col - 1,lin - 1}); //coorddenada na tela
    
    //Cursor invisível
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &info);
}

void mov_monstro1(){
	srand(time(NULL));
	switch ((rand() % 4) + 1){
		case 1:
			if (fase2[monster_i - 1][monster_j] != '*'){
				fase2[monster_i][monster_j] = ' ';
                monster_i--;
				fase2[monster_i][monster_j] = 'X';
            } else {
				fase2[monster_i][monster_j] = ' ';
                monster_i++;
				fase2[monster_i][monster_j] = 'X';
			}
            break;
		
		case 2:
			if ((fase2[monster_i][monster_j - 1] != '*')){
				fase2[monster_i][monster_j] = ' ';
                monster_j--;
				fase2[monster_i][monster_j] = 'X';
            } else {
				fase2[monster_i][monster_j] = ' ';
                monster_j++;
				fase2[monster_i][monster_j] = 'X';
			}
			break;
		
		case 3:
			if ((fase2[monster_i + 1][monster_j] != '*')){
				fase2[monster_i][monster_j] = ' ';
                monster_i++;
				fase2[monster_i][monster_j] = 'X';
            } else {
				fase2[monster_i][monster_j] = ' ';
                monster_i--;
				fase2[monster_i][monster_j] = 'X';
			}
			break;
		
		case 4:
			if ((fase2[monster_i][monster_j + 1] != '*')){
				fase2[monster_i][monster_j] = ' ';
                monster_j++;
				fase2[monster_i][monster_j] = 'X';
            } else {
				fase2[monster_i][monster_j] = ' ';
                monster_j--;
				fase2[monster_i][monster_j] = 'X';
			}
			break;
	}
}

void PrimeiraFase();
void SegundaFase();
void cheats();

void cheats(){
	printf("\n\nCodigo de trapaca:\n> ");
	fgets(cheat, 10, stdin);
	fflush(stdin);
}

void GerarFase1(char fase1[15][15]){
	printf("\n\n");
    for (i = 0; i < 15; i++){
		printf("\t");
        for (j = 0; j < 15; j++){ 
        	if (i == player_i && j == player_j){
                printf("&");
            } else {
                printf("%c", fase1[i][j]);
            }
		}
		
		printf("\n");
    }
}

void GerarFase2(char fase2[30][30]){
	printf("\n\n");
    for (i = 0; i < 30; i++){
		printf("\t");
        for (j = 0; j < 30; j++){ 
        	if (i == player_i && j == player_j){
                printf("&");
            } else {
                printf("%c", fase2[i][j]);
            }
		}
		
		printf("\n");
    }
}


void PrimeiraFase(){
	player_i = 1;
	player_j = 1;
	char input;
	linhaCol(1, 1);
	
	while(1){
		system("cls");
		GerarFase1(fase1);
		printf("\n\tHP: %d/%d\n", hp, hp_max);
		input = getch();
		switch (input){
			case 'W':
    		case 'w':
            	if (fase1[player_i - 1][player_j] != '*'){
                	player_i--;
            	}
            	break;
            
            case 'A':
        	case 'a':
        		
				if ((fase1[player_i][player_j - 1] == '@') && (player_i != 7)){
					printf("\n\nAperte I para pegar a chave.\n");
					input = getch();
					switch (input){
						case 'I':
						case 'i':
							printf("Nao aconteceu nada... parece que a chave era falsa.\n\n");
							system("pause");
						
						default:
							break;
					}
				} else if ((fase1[player_i][player_j - 1] == '*') && (player_i == 7) && (player_j - 5 == 0)){
					fase1[7][4] = ' ';
					fase1[7][3] = ' ';
					fase1[7][2] = ' ';
					fase1[7][1] = '@';
					player_j--;
				} else if ((fase1[player_i][player_j - 1] != '*')){
                	player_j--;
            	}

				if ((fase1[7][1] == '@') && (player_i == 7) && (player_j - 1 == 0)){
					printf("\n\nAperte I para pegar a chave.\n");
					input = getch();
					switch (input){
						case 'I':
						case 'i':
							fase1[7][1] = ' ';
							fase1[9][12] = ' ';
							fase1[12][14] = '=';
							player_j++;
							break;

						default:
							player_j++;
							break;
					}
					
				}

            	break;
            
            case 'S':
        	case 's':
				
				if (fase1[player_i + 1][player_j] == '@'){
					printf("\n\nAperte I para pegar a chave.\n");
					input = getch();
					switch (input){
						case 'I':
						case 'i':
							printf("Nao aconteceu nada... parece que a chave era falsa.\n\n");
							system("pause");
						
						default:
							break;
					}
				} else if (fase1[player_i + 1][player_j] != '*'){
                	player_i++;
            	} 
				
            	break;
            
            case 'D':
        	case 'd':
				if (fase1[player_i][player_j + 1] == '@'){
					printf("\n\nAperte I para pegar a chave.\n");
					input = getch();
					switch (input){
						case 'I':
						case 'i':
							printf("Nao aconteceu nada... parece que a chave era falsa.\n\n");
							system("pause");
						
						default:
							break;
					}
				} else if (fase1[player_i][player_j + 1] == 'D'){
					printf("\n\nA porta esta trancada.\n");
					input = getch();
				} else if ((fase1[player_i][player_j + 1] != '*')){
                	player_j++;
            	}

				if ((fase1[12][14] == '=') && (player_i == 12) && (player_j == 14)){
					printf("\n\nFase 1 concluida!\n");
					system("pause");
					SegundaFase();
				}

            	break;
		}
	}
}

void SegundaFase(){
	player_i = 27;
	player_j = 1;
	monster_i = 7;
	monster_j = 14;
	fase2[monster_i][monster_j] = 'X';

	char input;
	linhaCol(27, 1);

	while(1){
		system("cls");
		GerarFase2(fase2);
		printf("\n\tHP: %d/%d\n", hp, hp_max);
		input = getch();
		switch(input){
			case 'w':
				if (fase2[player_i - 1][player_j] != '*'){
                	player_i--;
					mov_monstro1();
            	}
            	break;
			
			case 'a':
				if ((fase2[player_i][player_j - 1] != '*')){
                	player_j--;
					mov_monstro1();
            	}
				break;

			case 's':
				if (fase2[player_i + 1][player_j] != '*'){
                	player_i++;
					mov_monstro1();
            	}

            	break;
			case 'd':
				if ((fase2[player_i][player_j + 1] != '*')){
                	player_j++;
					mov_monstro1();
            	}
				break;

		}
	}
}

int main(){
	
	PrimeiraFase();
	//SegundaFase();
	//cheats();
	
	return 0;
}
