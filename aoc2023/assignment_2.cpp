#include <iostream>
#include <fstream>
#include <vector>
#include <vector>
#include <string>

// read file
std::vector<std::string> read_txt_file(const std::string& file_name) {
    
    //define vector with strings
    std::vector<std::string> lines;

    // Open the file
    std::ifstream file(file_name);

    // Check if the file is successfully opened
    if (file.is_open()) {
        std::string line;

        // Read each line from the file and store it in the vector
        while (getline(file, line)) {
            lines.push_back(line);
        }

        // Close the file
        file.close();
    } else {
        // If the file cannot be opened, print an error message
        std::cout << "Unable to open file: " << file_name << std::endl;
        std::cout << "Press Enter to continue...";
        std::cin.get();
    }

    // Return the vector containing the lines
    return lines;
}


struct Colors {
    int r;
    int g;
    int b;
};

std::vector<Colors> extract_draws(const std::string &game) {
    std::vector<Colors> draws;

    std::size_t start = game.find(":");
    std::size_t next = game.find(";");

    while (start != std::string::npos) {
        // Create a subset for the current draw
        std::string subset = game.substr(start + 2, next - start - 2);

        int r = 0, g = 0, b = 0;
        
        // Find color and amount pairs in the subset
        size_t commaPos = 0;
        while ((commaPos = subset.find(",")) != std::string::npos) {
            std::string pair = subset.substr(0, commaPos); // Extract a color and amount pair
            
            // extract number
            std::string number;
            for (char ch : pair){
                if (std::isdigit(ch)) {
                    number += ch;
                }
            } 

            // identify color and add to number
            if (pair.find("red") != std::string::npos){
                r = std::stoi(number);
            } else if (pair.find("green") != std::string::npos) {
                g = std::stoi(number);
            } else if (pair.find("blue") != std::string::npos) {
                b = std::stoi(number);
            }
            
            subset = subset.substr(commaPos + 1); // Move to the next pair
        }

        // Save the draw
        draws.push_back({r, g, b});

        // Find the next draw
        start = next;
        next = game.find(";", next + 1);
    }
    return draws;
}

bool check_draw(Colors draw, Colors ingame){
    // function checks whether game is possible. Returns true 

    if (draw.r <= ingame.r && draw.g <= ingame.g && draw.b <= ingame.b) {
        return true;  // Valid draw
    } else {
        return false; // Invalid draw
    }
}


int main() {
    // Declare variables
    std::vector<std::string> games;
    std::string file_path;
    int pos_games_total = 0, current_game = 1;

    // define ingame characters
    Colors ingame = {12,13,14};
    // Read lines
    file_path  ="C:\\Users\\Gebruiker\\Documents\\coding\\Advent of code 2023\\data\\assignment2_data.txt";
    games = read_txt_file(file_path);

    // loop through each game
    for (std::string& game : games){    
        //identify game_id

        //extract the draws
        std::vector<Colors> draws = extract_draws(game);

        // loop through each draw and check if all possible
        bool possible = true;
        for (Colors& draw : draws){

            if (not check_draw(draw,  ingame)){
                //save game id
                possible = false;
            }
        }
        if (possible){
            // add the current game ID
            pos_games_total += current_game;
        }
        current_game +=1;

    }
    std::cout << "Sum of games assigment 2A: " << pos_games_total << std::endl;
    std::cout << "Press Enter to exit...";
    std::cin.get();
}