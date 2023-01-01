#include <stdio.h>

void goUp(int whereToGo, int currentElevatorPosition);
void goDown(int whereToGo, int currentElevatorPosition);

int main(){
    int currentElevatorPos;
    int whereToGo;

    currentElevatorPos = 0;
    printf("Where do you want to go?\n");
    scanf("%i", &whereToGo);

    if (currentElevatorPos < whereToGo){
        goUp(whereToGo, currentElevatorPos);
        currentElevatorPos = whereToGo;
    }
    if (currentElevatorPos > whereToGo){
        goDown(whereToGo, currentElevatorPos);
        currentElevatorPos = whereToGo;
    }

}



void goUp(int whereToGo, int currentElevatorPosition){
    for (currentElevatorPosition; currentElevatorPosition <= whereToGo; currentElevatorPosition++){
        printf("You are on floor %i\n", currentElevatorPosition);
        printf("Do you want to exit?\n");
        int daNe;
        scanf("%i", &daNe);

        if (daNe == 1 || whereToGo == currentElevatorPosition){
            printf("You have exited the elevator\n");
            break;
        }else if (daNe == 0 ){
            printf("Going to the next floor\n");
        }else{
            printf("Please enter either 0 or 1\n");
        } 
    }
}

void goDown(int whereToGo, int currentElevatorPosition){
    for (currentElevatorPosition; currentElevatorPosition >= whereToGo; currentElevatorPosition--){
        printf("You are on floor %i\n", currentElevatorPosition);
        printf("Do you want to exit?\n");
        int daNe;
        scanf("%i", &daNe);
    
        if (daNe == 1 || whereToGo == currentElevatorPosition){
            printf("You have exited the elevator\n");
            break;
        }else if (daNe == 0 ){
            printf("Going to the next floor\n");
        }else{
            printf("Please enter either 0 or 1\n");
        }  
    }
}



