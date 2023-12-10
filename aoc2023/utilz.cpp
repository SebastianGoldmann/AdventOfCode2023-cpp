
#include <iostream>
#include <string>
#include <sstream>
#include <iostream>
#include <string>
#include <sstream>
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

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
