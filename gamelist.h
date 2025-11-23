#pragma once
#include <vector>
#include <algorithm>

class Game{
    private:
    
    double year;
    float rating;
    std::string name;
    std::string genre;
    
    public: 
    Game(std::string n, double y, std::string g, float r);

    std::string getName();
    std::string getGenre();
    float getRating();
    double getYear();


    float setRating(float r);
    
};

class GameList{
    private: 

    std::vector<Game> games;
    void sortByRating();


    public:

    void addGame();
    void removeGame();

    void changeRating();

    void getGames();

    float validateRating();
    int valiYear();

};
