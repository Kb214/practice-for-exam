#include <iostream>
#include <vector>
#include <string>


/* Gaming list sorted from good to bad
    we need:
        name
        genre 
        year
        rating out of 5 stars
    STORE:
        into a class
        store that class into a vector
        make functions

*/

class Game{

};

class GameList{

};

int main(){
    int choice{0};
    double year;
    float rating;
    std::string name;
    std::string genre;
    
    
    std::cout << "\n======== Gaming List ========\n";
    std::cout << "Input your game, the genre, and rate it out of 5 stars    :    Your games will be automatically sorted from good to bad\n";
    
    std::cout << "\n======== Would you like to:========\n";
    std::cout << "1) ADD Game\n";
    std::cout << "2) REMOVE Game\n";
    std::cout << "3) CHANGE Rating\n";
    std::cout << "4) Exit\n";
    
    
    std::cout << "\nChoice: ";
    std::cin >> choice;
    std::cin.ignore();
    
    while(choice != 4){

        if (choice == 1){
        
            std::cout << "\n======== Enter Your Game's Details: ========\n";
            std::cout << "Name: ";
            std::getline(std::cin, name);
            
            std::cout << "Year: ";
            std::cin >> year;
            std::cin.ignore();
            
            std::cout << "Genre: ";
            std::getline(std::cin, genre);
            
            std::cout << "Rating(Out of 5): ";
            std::cin >> rating;
            
            
            std::cout << "\n======== Your Added Game ========\n";
            std::cout << "Game: " << name << "\n" << "Year: " << year << "\n" << "Genre: " << genre << "\n" << "Rating: " << rating << "\n";
            

            std::cout << "\n======== Would you like to:========\n";
            std::cout << "1) ADD Game\n";
            std::cout << "2) REMOVE Game\n";
            std::cout << "3) CHANGE Rating\n";
            std::cout << "4) Exit\n";


        }else if (choice == 2){
            std::cout << "\n======== Enter your game you want to remove: ========\n";
            
            std::cout << "Remove Game:";
            std::getline(std::cin, name); 
            
            std::cout << "\n======== Remove Game! ========\n";
        
        }else if (choice == 3 ){
            std::cout << "What game rating do you want to choose? \n";
            
            std::cout << "Game Name: ";
            std::getline(std::cin, name);
            
            std::cout << "Change your rating: ";
            std::cin >> rating; 
            
        }else{
            choice == 4; 
        }

        std::cout << "\nChoice: ";
        std::cin >> choice;
        std::cin.ignore();
    
    }
    
    
    
    return 0;
}