#include <iostream>
#include <limits>
#include <iterator>
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



float GameList::validateRating(){
    float rating;
    while (!(std::cin >> rating) || rating < 1 || rating > 5) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid Rating. Enter 1-5: ";
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return rating;
}

int GameList::valiYear(){
    int choice;
    while (!(std::cin >> choice) || choice < 1000 || choice > 3000) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid Year (valid years: 1000-3000): ";
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return choice;
}

void GameList::addGame(){
    std::string name, genre;
    double year;
    float rating;

    std::cout << "Title: ";
    std::getline(std::cin, name);
    
    std::cout << "Year (valid years: 1000-3000): ";
    year = valiYear();
    
    std::cout << "Genre: ";
    std::getline(std::cin, genre);
    
    std::cout << "Rating (Out of 5): ";
    rating = validateRating();


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
        std::cout << "Year (don't go any further than the year 3000): " << games.at(x).getYear() << "\n";
        std::cout << "Genre: " << games.at(x).getGenre() << "\n";
        std::cout << "Rating (out of 5): " << games.at(x).getRating() << "\n";
    } 
    
    
}



void GameList::changeRating(){
    std::string title;

    std::cout << "Title: ";
    std::getline(std::cin, title);

    for(size_t x = 0; x < games.size(); ++x){
        if(games.at(x).getName() == title){
            float r;
            std::cout << "Your New Rating (out 5): ";
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


