#include <iostream>
#include "gamelist.h"


void GameList::sortByRating(){
    std::sort(games.begin(), games.end(),[] (Game& a, Game& b){
        return a.getRating() > b.getRating();
    });

    
}


/* ================= Game Class =================*/

Game::Game(std::string n, double y, std::string g, float r)
    : name(n), year(y), genre(g), rating(r){}

std::string Game::getName(){
    return name; 
}

std::string Game::getGenre(){
    return genre; 
}

float Game::getRating(){
    return rating;
}

double Game::getYear(){
    return year;
}

float Game::setRating(float r){
    return rating = r;
}



/* ================= Game List Class =================*/


void GameList::addGame(){
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

    sortByRating();
}


void GameList::removeGame(){
    std::string title;

    std::cout << "Remove Game: ";
    std::getline(std::cin, title);

    for(auto it = games.begin(); it != games.end(); ++it){
        if(it->getName() == title){ //if game is at this name and the name equals the title
            games.erase(it); //remove game
            return;
        }
    }
}

void GameList::getGames(){
    for(size_t x = 0; x < games.size(); ++x){
        std::cout << "\n";
        
        std::cout << "Title: " << games.at(x).getName() << "\n";
        std::cout << "Year: " << games.at(x).getYear() << "\n";
        std::cout << "Genre: " << games.at(x).getGenre() << "\n";
        std::cout << "Rating: " << games.at(x).getRating() << "\n";
    } 
    
    
}



void GameList::changeRating(){
    std::string title;

    std::cout << "Title: ";
    std::getline(std::cin, title);

    for(size_t x = 0; x < games.size(); ++x){
        if(games.at(x).getName() == title){
            float r;
            std::cout << "Your New Rating: ";
            std::cin >> r;

            std::cin.ignore();

            games.at(x).setRating(r); 
            sortByRating();

            return;
        }
    }


    // for (auto& g : games) {
    //     if (g.getName() == title) {
    //         float r;
    //         std::cout << "New rating: ";
    //         std::cin >> r; 
    //         std::cin.ignore();
    //         g.setRating(r);
    //         sortByRating();
    //         return;
    //     }
    // }
}


