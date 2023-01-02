#include <stdio.h>

void goUp(int whereToGo, int currentElevatorPos);
void goDown(int whereToGo, int currentElevatorPos);

int main(){
    int currentElevatorPos = 0;
    int whereToGo;


    //based on users input we will choose whether user should go down or up in relation to the elevators position
    for (int i = 0; i < 10000; i++){
        printf("\n---------------------------\nWelcome to the elevator\nPlease choose one of the following floors\n-3     -2      -1      0       1       2       3       4       5\n");
        printf("Where do you want to go?\n");
        scanf("%i", &whereToGo);
        if (whereToGo < 6 && whereToGo > -4){
            if (currentElevatorPos < whereToGo){
            goUp(whereToGo, currentElevatorPos);
            currentElevatorPos = whereToGo;
            }
            if (currentElevatorPos > whereToGo){
                goDown(whereToGo, currentElevatorPos);
                currentElevatorPos = whereToGo;
            }   
        }else{
            printf("Please insert a number between -3 and 5\n");
        }
        
           
    }
}



void goUp(int whereToGo, int currentElevatorPos){
    for (currentElevatorPos; currentElevatorPos <= whereToGo; currentElevatorPos++){
        printf("Do you want to exit?\n");
        int yesNo;
        scanf("%i", &yesNo);
        if (yesNo == 0 || yesNo == 1){
            if (yesNo == 1 || whereToGo == currentElevatorPos){
            printf("You are on floor %i\n", currentElevatorPos);
            printf("You have exited the elevator\n");
            break;
        }else if (yesNo == 0){
            printf("You are on floor %i\n", currentElevatorPos);
            printf("Going to the next floor\n");
        }
        }else{
            printf("Please insert either 0 or 1\n");
        }
    }
        
        
}

void goDown(int whereToGo, int currentElevatorPos){
    for (currentElevatorPos; currentElevatorPos >= whereToGo; currentElevatorPos--){
        printf("Do you want to exit?\n");
        int yesNo;
        scanf("%i", &yesNo);
        if (yesNo == 0 || yesNo == 1){
            if (yesNo == 1 || whereToGo == currentElevatorPos){
            printf("You are on floor %i\n", currentElevatorPos);
            printf("You have exited the elevator\n");
            break;
        }else if (yesNo == 0 ){
            printf("You are on floor %i\n", currentElevatorPos);
            printf("Going to the next floor\n");
        } 
        }else{
            printf("Please insert either 0 or 1\n");
        }
    }
}



