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
    SORT:
        with a lambda 
        BUT only after you've put in your GameList class
        and made a game class

*/

struct Game{
    double year;
    float rating;
    std::string name;
    std::string genre;
};


void addGame(std::vector<Game>& game){
    Game g;

    std::cout << "Title: ";
    std::getline(std::cin, g.name);
    
    std::cout << "Year: ";
    std::cin >> g.year;
    std::cin.ignore();
    
    std::cout << "Genre: ";
    std::getline(std::cin, g.genre);
    
    std::cout << "Rating(Out of 5): ";
    std::cin >> g.rating;  
    
    game.push_back(g);            


}


void removeGame(std::vector<Game>& game){
    std::string title;
    
    std::cout << "Remove Game: ";
    std::getline(std::cin, title);
    
    for(size_t x = 0; x < game.size(); ++x){ //go through the game vector

        if(game.at(x).name == title){ //if game is at this name and the name equals the title
            game.erase(game.begin()+1); //remove game
        }
    }

}


void showGames(std::vector<Game>& game){

    for(size_t x = 0; x < game.size(); ++x){
        std::cout << "\n";
        
        std::cout << "Title: " << game.at(x).name << "\n";
        std::cout << "Year: " << game.at(x).year << "\n";
        std::cout << "Genre: " << game.at(x).genre << "\n";
        std::cout << "Rating: " << game.at(x).rating << "\n";
    }      
}


void changeRating(std::vector<Game>& game){
    std::string title;
    Game g;

    std::cout << "Title: ";
    std::getline(std::cin, title);

    for(size_t x = 0; x < game.size(); ++x){
        if(game.at(x).name == title){
            std::cout << "Your New Rating: ";
            std::cin >> game.at(x).rating; 
        }
    }
}


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

    void addGame(const Game& g){
        games.push_back(g);
    }


    void removeGame(std::string title){
        std::cout << "Remove Game: ";
        std::getline(std::cin, title);
        
        for(size_t x = 0; x < games.size(); ++x){ //go through the game vector

            if(games.at(x).name == title){ //if game is at this name and the name equals the title
                games.erase(games.begin() + x); //remove game
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

};






int main(){
    std::vector<Game> game;
    int choice{0};
    
    std::cout << "\n======== Gaming List ========\n";
    std::cout << "Input your game, the genre, and rate it out of 5 stars    :    Your games will be automatically sorted from good to bad\n";
    
    choices();
    
    
    std::cout << "\nChoice: ";
    std::cin >> choice;
    std::cin.ignore();
    
    while(choice != 5){

        if (choice == 1){
        
            std::cout << "\n======== Enter Your Game's Details: ========\n";
            addGame(game);
            
            std::cout << "\n======== Your Added Games ========\n";
            showGames(game);
            

            choices();

        }else if (choice == 2){
            std::cout << "\n======== Enter your game you want to remove: ========\n";

            removeGame(game);
            
            std::cout << "\n======== Removed Game! ========\n";


            choices();

        
        }else if (choice == 3 ){
            std::cout << "What game rating do you want to choose? \n";

            changeRating(game);

            std::cout << "\n======== Your New Game Rating ========\n";
            showGames(game);

            choices();

            
        }else if(choice == 4){
            std::cout << "\n======== Your Games ========\n";
            showGames(game);

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