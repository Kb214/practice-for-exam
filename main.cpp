#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "gamelist.cpp"


void choices(){
    std::cout << "\n======== Would you like to:========\n";
    std::cout << "1) ADD Game\n";
    std::cout << "2) REMOVE Game\n";
    std::cout << "3) CHANGE Rating\n";
    std::cout << "4) SHOW games\n";
    std::cout << "5) Exit\n";
}


int main(){
    int choice{0};
    GameList mygames;
    
    std::cout << "\n======== Gaming List ========\n";
    std::cout << "Input your game, the genre, and rate it out of 5 stars    :    Your games will be automatically sorted from good to bad\n";
    
    choices();
    
    std::cout << "\nChoice: ";
    std::cin >> choice;
    std::cin.ignore();
    
    while(choice != 5){

        if (choice == 1){
        
            std::cout << "\n======== Enter Your Game's Details: ========\n";
            mygames.addGame();
            
            std::cout << "\n======== Your Added Games ========\n";
            mygames.getGames();
            
            choices();

        }else if (choice == 2){
            std::cout << "\n======== Enter your game you want to remove: ========\n";

            mygames.removeGame();
            
            std::cout << "\n======== Removed Game! ========\n";

            choices();

        }else if (choice == 3 ){
            std::cout << "What game rating do you want to choose? \n";

            mygames.changeRating();


            std::cout << "\n======== Your New Game Rating ========\n";
            mygames.getGames();

            choices();
            
        }else if(choice == 4){
            std::cout << "\n======== Your Games ========\n";
            mygames.getGames();

            choices();

        }else{
            choice == 5; 
        }

        std::cout << "\nChoice: ";
        std::cin >> choice;
        std::cin.ignore();
    
    }
    
    return 0;
}