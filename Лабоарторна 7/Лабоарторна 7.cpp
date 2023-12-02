#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class StringArrayProcessor {
private:
    std::vector<std::string> strings;

public:
    
    void inputStrings(int n) {
        strings.resize(n);
        std::cout << "Enter the lines :\n";
        for (int i = 0; i < n; ++i) {
            std::cout << "Line " << i + 1 << ": ";
            std::getline(std::cin, strings[i]);
        }
    }

    
    void sortStrings() {
        std::sort(strings.begin(), strings.end());
    }

   
    void displaySortedStrings() const {
        std::cout << "\nSorted rows:\n";
        for (const auto& str : strings) {
            std::cout << str << '\n';
        }
    }

    
    void countWordsInEachString() const {
        std::cout << "\nNumber of words in each line:\n";
        for (const auto& str : strings) {
            int wordCount = 0;
            bool inWord = false;

            for (char ch : str) {
                if (std::isalnum(ch)) {
                    if (!inWord) {
                        inWord = true;
                        ++wordCount;
                    }
                }
                else {
                    inWord = false;
                }
            }

            std::cout << "line: " << str << ", Number of words: " << wordCount << '\n';
        }
    }
};

int main() {
    StringArrayProcessor processor;

    
    int n;
    std::cout << "Enter the number of lines: ";
    std::cin >> n;
    std::cin.ignore();  

    
    processor.inputStrings(n);
    processor.sortStrings();
    processor.displaySortedStrings();
    processor.countWordsInEachString();

    return 0;
}
