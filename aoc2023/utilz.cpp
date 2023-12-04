
#include <iostream>
#include <string>
#include <sstream>
#include <curl/curl.h>

using namespace std;



#include <iostream>
#include <string>
#include <sstream>
#include <curl/curl.h>

using namespace std;

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, std::string *s) {
    size_t newLength = size * nmemb;
    try {
        s->append((char*)contents, newLength);
    }    catch(std::bad_alloc &e) {
        // handle memory problem
        return 0;
    }
    return newLength;
}

int read_website_URL(const string& site_url) {
    CURL *curl;
    CURLcode res;
    string readBuffer;

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, site_url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);

        if (res != CURLE_OK) {
            cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << endl;
            return 1; // Indicates failure
        }

        cout << readBuffer << endl; // Print the contents of the website
    } else {
        cerr << "Failed to initialize CURL." << endl;
        return 1; // Indicates failure
    }
    return 0; // Indicates success
}

int main() {
    string url = "...";
    int result = read_website_URL(url);

    if (result != 0) {
        cerr << "Failed to read from the website" << endl;
        return 1;
    }

    return 0;
}