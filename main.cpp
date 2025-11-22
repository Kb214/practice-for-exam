#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

void choices(){
    std::cout << "\n======== Would you like to:========\n";
    std::cout << "1) ADD Game\n";
    std::cout << "2) REMOVE Game\n";
    std::cout << "3) CHANGE Rating\n";
    std::cout << "4) SHOW games\n";
    std::cout << "5) Exit\n";
}

class Game{
    public:
    
    double year;
    float rating;
    std::string name;
    std::string genre;

    Game(std::string n, double y, std::string g, float r)
    : name(n), year(y), genre(g), rating(r){}
    
};

class GameList{
    private: 

    std::vector<Game> games;

    public:

    void addGame(){
        std::string name, genre;
        double year;
        float rating;

        std::cout << "Title: ";
        std::getline(std::cin, name);
        
        std::cout << "Year: ";
        std::cin >> year;
        std::cin.ignore();
        
        std::cout << "Genre: ";
        std::getline(std::cin, genre);
        
        std::cout << "Rating(Out of 5): ";
        std::cin >> rating;  

        games.push_back(Game(name,year,genre,rating));
    }


    void removeGame(){
        std::string title;
        std::cout << "Remove Game: ";
        std::getline(std::cin, title);
        
        for(size_t x = 0; x < games.size(); ++x){ //go through the game vector

            if(games.at(x).name == title){ //if game is at this name and the name equals the title
                games.erase(games.begin() + x); //remove game
                return;
            }
        }
    }


    void getGames(){

        for(size_t x = 0; x < games.size(); ++x){
            std::cout << "\n";
            
            std::cout << "Title: " << games.at(x).name << "\n";
            std::cout << "Year: " << games.at(x).year << "\n";
            std::cout << "Genre: " << games.at(x).genre << "\n";
            std::cout << "Rating: " << games.at(x).rating << "\n";
        }      
    }


    void changeRating(){
        std::string title;

        std::cout << "Title: ";
        std::getline(std::cin, title);

        for(size_t x = 0; x < games.size(); ++x){
            if(games.at(x).name == title){
                std::cout << "Your New Rating: ";
                std::cin >> games.at(x).rating; 
                std::cin.ignore();
            }
        }
    }

    void sortByRating() {
        std::sort(games.begin(), games.end(),[] (const Game& a, const Game& b){
            return a.rating > b.rating;
        });
    }

};



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
            mygames.sortByRating();
            
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
            mygames.sortByRating();


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