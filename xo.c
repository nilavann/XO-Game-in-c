#include<stdio.h>

int turn;
int check[8] = {1,00,11,10,01,12,21,};
int xo_data[3][3];
int played = 0;
int wins = 0;
int position[] = {20,21,22,10,11,12,00,01,02};

//function to intialize function 
void init(){
        turn = 0;
        for (int i = 0; i < 3; ++i)
        {
                for (int j = 0; j < 3; ++j)
                {
                        xo_data[i][j] = 2;
                }
        }
}

//function to display print xo data
void print(){
        for (int i = 0; i < 3; ++i){
        	printf("                        ");
                for (int j = 0; j < 3; ++j){
                        if(xo_data[i][j] == 3)
                                printf("X\t");
                        else if (xo_data[i][j] == 5)
                                printf("O\t");
            else
                    printf("empty\t");
                }
                printf("\n");
        }
        printf("\n\n");
}

//function to place system move
void place_x(){
  int flag = 1;
  while(flag){
        int next_position = check[check[0]];
        if(xo_data[next_position % 10][next_position / 10] == 2){
           xo_data[next_position % 10][next_position / 10] = 3;
           flag = 0;
        }
        check[0] += 1;
  }
        print();
}

//to move place system moves when user has wining probability
void move_x(int i,int j,int key){
  if(key == 27){
    wins = 1;
    printf("-----------------------------System wins-------------------------\n");
    return;
  }
  if(key == 125){
    wins = 1;
    printf("-----------------------------User wins----------------------------\n");
    return;
  }
  played = 1;
  xo_data[i][j] = 3;
  print();
}

//function to check key in dynamic elements
void check_dynamic(int key){
        int i,j;
        int mul = 1;
        for (i = 0; i < 3; ++i){
                mul *= xo_data[i][i];
        }
        if((mul == 27 && key == 27) || (mul == 125 && key ==125)){
                  move_x(0,0,key);
                  return;
                }
        if(mul == key){
                for (i = 0; i < 3; ++i){
                        if(xo_data[i][i] ==2){
                                move_x(i,i,key);
                                return;
                        }
                }
        }
        mul = 1;
        for (i = 0,j = 2; i < 3; ++i,j--)
        {
                mul *= xo_data[i][j];
        }
        if((mul == 27 && key == 27) || (mul == 125 && key ==125)){
                  move_x(0,0,key);
                  return;
                }
        if(mul == key){
                for (i = 0,j = 2; i < 3; ++i,j--){
                        if(xo_data[i][j] ==2){
                                move_x(i,j,key);
                                return;
                        }
                }
        }
        //printf("check_dynamic completed\n");
}

//function to check key in column elements
void check_col(int key){
        int i=0,j=0,mul;
        for (i = 0; i < 3; ++i){
                mul = 1;
                for (j = 0; j < 3; ++j){
                        mul *= xo_data[j][i];
                }
                if((mul == 27 && key == 27) || (mul == 125 && key ==125)){
                  move_x(0,0,key);
                  return;
                }
                if(mul == key){
                        for (int j = 0; j < 3; ++j)
                        {
                                if(xo_data[j][i] == 2){
                                        move_x(j,i,key);
                                        return;
                                }
                        }
                        break;
                }
        }
        //printf("check_col completed\n");
        check_dynamic(key);
}

//function to check key in row elements
void check_row(int key){
        int i,j,mul,flag = 0;
        for (i = 0; i < 3; ++i){
                mul = 1;
                for (j = 0; j < 3; ++j){
                        mul *= xo_data[i][j];
                }
                if((mul == 27 && key == 27) || (mul == 125 && key ==125)){
                  move_x(0,0,key);
                  return;
                }
                if(mul == key){
                        for (int j = 0; j < 3; ++j)
                        {
                                if(xo_data[i][j] == 2){
                                        move_x(i,j,key);
                                        return;
                                }
                        }
                        break;
                }
        }
        //printf("check_row completed\n");
        check_col(key);
}
void instruction(){
	printf("                         welcome to xo game\n\n");
	printf("    1.In this game the first move will be performed by system\n");
	printf("    2.The user can give the input to the program as number pad format like below\n");
	printf("                            7   8   9\n");
	printf("                            4   5   6\n");
	printf("                            1   2   3\n");
	printf("                     the number is the position\n\n");
}
void main()
{
        init();
        int p,move;
        instruction();
        for(move = 1; move <= 9; move++){
          printf("                                  Move:%d\n\n",move);
                if(move <= 4){
                        if(move % 2 == 0){
                        	int flag1 = 1;
                        	while(flag1){
                        		printf("                         Enter your move:");
                      	        scanf("%d",&p);
                      	        if(xo_data[position[p-1]/10][position[p-1]%10] == 2){
                         	    	xo_data[position[p-1]/10][position[p-1]%10] = 5;
                         	    	flag1 = 0;
                         	    }else{
                         	    	printf("sry please place your move in empty place\n");
                         	    }
                      	    }
                            print();
                        }else{
                                place_x();
                        }
                        }else{
                          if(move % 2 == 0){
                            int flag1 = 1;
                        	while(flag1){
                        		printf("                          Enter your move:");
                      	        scanf("%d",&p);
                      	        if(xo_data[position[p-1]/10][position[p-1]%10] == 2){
                         	    	xo_data[position[p-1]/10][position[p-1]%10] = 5;
                         	    	flag1 = 0;
                         	    }else{
                         	    	printf("sry please place your move in empty place\n");
                         	    }
                      	    }
                            print();
                          }else{
                          played = 0;
                            check_row(18);
                          if(played != 1)
                            check_row(50);
                          if(played != 1)
                            place_x();
                          }
                }
                if(move>=4){
                  if(move % 2 == 0)
                    check_row(125);
                  else
                    check_row(27);
                }
                if(wins == 1)
                  break;
        }
        if(move == 10)
        	printf("-------------------------------Match draw-------------------------------------------\n");
        printf("------------------------------Thanks for playing by nilavann---------------------------------\n");
}

