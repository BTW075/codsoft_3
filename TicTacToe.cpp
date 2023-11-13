
#include <iostream>
#include <random>
using namespace std;

char GameBoard[9]={' ',' ',' ',' ',' ',' ',' ',' ',' '};
void GameDisplay();
void SysInput();
void UserInput();
int count();
char wincheck();
void Game();

int main() {
    
    int demo[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    int choice;
    cout<<"WELCOME TO TIC-TAC-TOE GAME!"<<endl;
    cout<<"Instructions:-"<<endl;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<"\t"<<demo[i][j];
        }
        cout<<"\n";
    }
    cout<<"Choose any Number from 1-9 to mark 'X' on that position."<<endl;
        do{

    cout<<"To PLAY: Press 1"<<endl;
    cout<<"To EXIT: Press 0"<<endl;
    cin>>choice;
    if(choice==1){
      Game();  
    }
    else cout<<"THANKS FOR PLAYING!";
    }while(choice!=0);
    return 0;
}

void SysInput(){
    srand((unsigned) time(NULL));
    int sysinp;
    do{
         sysinp = rand() % 10;
    }while(GameBoard[sysinp]!=' ');
    
    GameBoard[sysinp]='O';
}

void UserInput(){
    while(true){
    int userinp;
    cout<<"Your Turn: ";
    cin>>userinp;
    userinp--;
    
    if(userinp<0 || userinp>8){
        cout<<"Please select between 1-9"<<endl;
    }else if(GameBoard[userinp]!=' '){
        cout<<"Please select a valid position"<<endl;
    }else{
        GameBoard[userinp]='X';
        break;
    }
  }
}

int count(char symbol){
    int total=0;
    for(int i=0;i<9;i++){
        if(GameBoard[i] == symbol){
            total += 1;
        }
    }
    return total;
}

char wincheck() {
    if(GameBoard[0]==GameBoard[1] && GameBoard[1]==GameBoard[2] && GameBoard[0]!=' ') return GameBoard[0];
    if(GameBoard[3]==GameBoard[4] && GameBoard[4]==GameBoard[5] && GameBoard[3]!=' ') return GameBoard[3];
    if(GameBoard[6]==GameBoard[7] && GameBoard[7]==GameBoard[8] && GameBoard[6]!=' ') return GameBoard[6];
    
    if(GameBoard[0]==GameBoard[3] && GameBoard[3]==GameBoard[6] && GameBoard[0]!=' ') return GameBoard[0];
    if(GameBoard[1]==GameBoard[4] && GameBoard[4]==GameBoard[7] && GameBoard[1]!=' ') return GameBoard[1];
    if(GameBoard[2]==GameBoard[5] && GameBoard[5]==GameBoard[8] && GameBoard[2]!=' ') return GameBoard[2];
    
    if(GameBoard[0]==GameBoard[4] && GameBoard[4]==GameBoard[8] && GameBoard[0]!=' ') return GameBoard[0];
    if(GameBoard[2]==GameBoard[4] && GameBoard[4]==GameBoard[6] && GameBoard[2]!=' ') return GameBoard[2];
    
    if(count('X') + count('O') < 9) return 'C';
    else return 'D';
}

void Game(){
    while(true){
        system("cls");
        GameDisplay();
        if(count('X') == count('O')){
            UserInput();
        }else{
           SysInput(); 
        } 
        char winner =  wincheck();
        if(winner=='X'){
            system("cls");
            GameDisplay();
            cout<<"You Won!"<<endl;
            break;
        }else if(winner=='O'){
            system("cls");
            GameDisplay();
            cout<<"You Lost!"<<endl;
            break;
        } 
        else if(winner=='D'){
            system("cls");
            GameDisplay();
            cout<<"TIE!"<<endl;
            break;
        }
    }
}

void GameDisplay(){
     
    cout<<"\n\t**TIC-TAC-TOE**\n"<<endl;
    cout<<"\t"<<GameBoard[0]<<"  |   "<<GameBoard[1]<<"  |   "<<GameBoard[2]<<endl;
    cout<<"\t---------------"<<endl;
    cout<<"\t"<<GameBoard[3]<<"  |   "<<GameBoard[4]<<"  |   "<<GameBoard[5]<<endl;
    cout<<"\t---------------"<<endl;
    cout<<"\t"<<GameBoard[6]<<"  |   "<<GameBoard[7]<<"  |   "<<GameBoard[8]<<endl;
}
