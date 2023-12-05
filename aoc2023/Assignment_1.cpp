#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <vector>
#include <string>
#include <map>


// Define a macro to read and print the contents of a text file
std::vector<std::string> read_txt_file(const std::string& file_name) {
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
    }

    // Return the vector containing the lines
    return lines;
}

std::string correct_string(std::string line){

    std::map<std::string, std::string> possible_names;
    possible_names = {{"one", "1"}, {"two", "2"}, {"three", "3"}, {"four", "4"}, {"five", "5"},{"six", "6"}, {"seven", "7"}, {"eight", "8"}, {"nine", "9"}};

    for (const auto& string_and_numb : possible_names){
        
        // find the string index
        std::size_t found;
        found = line.find(string_and_numb.first);

        // Check if all intances were found
        while (found != std::string::npos){
            // replace entire word with letter.
            //line.replace(found, string_and_numb.first.length(), string_and_numb.second);
            // WE NEED TO INSERT, BC ONEIGHT COULD REPLACE EIGHT FIRST AND THEN ONE DOES NOT COUNT!
            line.insert(found+2, string_and_numb.second);
            std::cout << line << std::endl;
            //find next name string and replace.
            //found = line.find(string_and_numb.first, found + string_and_numb.second.length());
            found  = line.find(string_and_numb.first, found + string_and_numb.first.length());
        }
    }
    return line;
}

std::vector<std::string> replace_numbers_by_int_string(std::vector<std::string> lines){

    // loop through the string and grab each set of 3 and each set of 4.
    for (std::string& line : lines){
        std::cout << line << std::endl;    
        // loop through all possible sting names WRONG FIND FIRST WORD  in string
        line = correct_string(line);
    }
    // return lines to
    
    return lines;
}


int read_outer_numbers(std::vector<std::string> lines){
    // declare vars
    bool first_int_bool;
    bool last_int_bool;
    int first_int;
    int last_int;
    int final_int;
    std::vector<int> final_numbers = {};

    //loop through lines
    for (const std::string& line : lines) {

        first_int_bool = true;
        last_int_bool = true;
        first_int = 0;
        last_int = 0;
        final_int = 0;


        // loop through characters in line
        for (char entry : line){

            // select first integer 
            if (std::isdigit(entry))
                if (first_int_bool){
                    first_int_bool=false;
                    first_int = entry-'0';
                }

            //select last integer
            else if(std::isdigit(entry)){
                last_int_bool = false;
                last_int = entry-'0';
                
            }
        }
        if (last_int_bool){
            //there is only 1 char in the string
            last_int = first_int;
        }

        // save first and last integer as number
        final_int = first_int*10 + last_int;
        
        // append final number
        final_numbers.push_back(final_int);
    }

    //sum numbers
    int sum;
    sum = 0;
    for (int numb: final_numbers){
        sum += numb;
    }

    // return sum for print
    return sum;
}



int main() {
    // Declare variables
    std::vector<std::string> lines, lines_corrected;
    std::string file_path;
    int sum;


    // Read lines
    file_path  ="C:\\Users\\Gebruiker\\Documents\\coding\\Advent of code 2023\\data\\assigment1_data.txt";
    lines = read_txt_file(file_path);

    //calc assignment 1 part 1
    sum = read_outer_numbers(lines);

    std::cout << "Sum of numbers assignment 1A: " << sum << std::endl;


    // start part 2 replace all string numbers in the strings with the integer numbers
    lines_corrected = replace_numbers_by_int_string(lines);
    sum = read_outer_numbers(lines_corrected);


    std::cout << "Sum of numbers assignment 1B: " << sum << std::endl;
    std::cout << "Press Enter to exit...";
    std::cin.get();

    return 0;
}