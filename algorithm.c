#include<stdio.h>
#include<math.h>
int alg3rc,alg3pc,alg3sc=0;//used for algorithm 3 (alg3rc = rock count to be used for algorithm 3, and so on)
int playerMoves[5];/*array of past 5 player inputs;implement as a stack and add the last player throw to
                      top of stack each time they throw. If rock is thrown, add int 1 to stack, 2 for paper
                      3 for scissors*/
int rockCount,paperCount,scissorsCount=0; /*keeps track of how many of each throw was done;increment relevant
                                            value each time the player throws it*/
int calcChoice=0; /* used to choose which of the 3 algorithms to implement (random,past input based,
                    most common throw based*/
//each throw calcChoice randomly selects from 1-3, and uses algorithm based on no selected
calcChoice = rand() % 3 + 1;

//ALGORITHM 1 (normal rand function)/////////////
if (calcChoice==1)
{
    //normal random computer throw function
}

//ALGORITHM 2 (based on most common player inputs)///////////////
else if (calcChoice==2)
{
    if(rockCount>papercount && rockCount > scissorsCount)
        computerMove=Game.PAPER;//if player has thrown rock the most times, comp responds with paper
    else if(paperCount>rockCount && paperCount > scissorsCount)
        computerMove=Game.SCISSORS;
    else
        computerMove=Game.ROCK;
    
}
//ALGORITHM 3 (based on player's past 5 inputs)////////
else if(calcChoice==3)
{
    alg3rc=alg3pc=alg3sc=0;//resetting count of last 5 throws
    for(i=0;i<5;i++)
    {
        if(playerMoves[i]==1)
            alg3rc++;//so whenever a player throws a rock, 1 is added to the playerMoves stack to denote rock
        else if(playerMoves[i]==2)
            alg3pc++;
        else
            alg3sc++;
        if(alg3rc > alg3pc && alg3rc > alg3sc)
            computerMove = Game.PAPER;/*rock was highest no of player throws in last 5 moves, so comp responds
                                        with paper*/
        else if(alg3pc > alg3rc && alg3pc > alg3sc)
            computerMove = Game.SCISSORS;/*paper most common throw in last 5 moves, so respond with scissors*/
        else
            computerMove = Game.ROCK;
            
    }
}
