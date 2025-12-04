#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

int main(){
    //name the file that you want to open
    /*we want to open the reading.txt file and we're naming it the reading file
     we use ifstream to read from it*/
    std::ifstream readingFile("reading.txt");

    /*if readingFile won't open, then the file must be created. 
     if stream cannot create a file, it can only read file that already exits*/
    if(!readingFile){
        std::cout << "Couldn't open file!\n";
        return 1;
    }

    std::string line;
    
    if(readingFile.is_open()){

        while(getline(readingFile,line)){
            std::stringstream ss(line);

            std::string name;
            int age;
            std::string occupa;
            std::string address;
            std::string hobby;

            if( ss >> name >> age >> occupa >> address >> hobby){
                std::cout << "Name: " << name << "\n";
                std::cout << "Age: " << age << "\n";
                std::cout << "Occupation: " << occupa << "\n";
                std::cout << "Address: " << address << "\n";
                std::cout << "hobby: " << hobby << "\n";

            }else{
                std::cout << "Invalid information on line: " << line << "\n";
            }

        }

    }


    /*same concept as ifstream but now we can actually create a 
     file outselfves and write to it */
    std::ofstream writingFile("writing.txt");
    std::vector<int> num{1, 2, 3, 4, 5};


    /* wrting the num vector into the writingFile using ranged-based for loop*/
    if(writingFile.is_open()){
        for( int n : num){

            writingFile << n << "\n";

        }
    }
    /* Closing file */
    writingFile.close();


    /*Creating a stream to read from writing.txt*/
    std::ifstream readingFileTwo("writing.txt");

    /*same concepts like above for readingFile.txt*/
    if(!readingFileTwo.is_open()){
        std::cout << "opening file...\n\n";
        readingFileTwo.open("writing.txt");
    }

    /*Establishes the full lines you will read*/
    std::string linesTwo;

    if(readingFile.is_open()){
        /*while function that reads the entire line including spaces. 
         it reads the input stream and stores it into linesTwo
         
                      inputStream     targetString*/
        while(getline(readingFileTwo, linesTwo)){
            /* stores linesTwo into ssTwo, turning into a streamString object to read in the numbers*/
            std::stringstream ssTwo(linesTwo);
            int numbers;

            if(ssTwo >> numbers){
                /* while ssTwo reads the numbers, output them*/
                std::cout << "Number " << numbers << "\n";
            }
        }

    }

   
    

    return 0;
}