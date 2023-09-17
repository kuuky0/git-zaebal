#include <iostream>
#include <string>
#include <map>



int main() {
	std::map<std::string, int> surnameCount;
#ifdef a
	surnameCount.insert({ "surname", 1 });
	std::map<std::string, int>::iterator i = surnameCount.begin();
	std::cout << i->first;
#endif
        while (true) {
            std::string word;
            std::cout << "Input surname or next: ";
            std::cin >> word;

            if (word != "next") {
                auto it = surnameCount.find(word);
                if (it != surnameCount.end()) {
                    it->second++;
                }
                else {
                    surnameCount.insert({ word, 1 });
                }
            }
            else {
                if (!surnameCount.empty()) {
                    std::cout << surnameCount.begin()->first << std::endl;
                    if (surnameCount.begin()->second > 1) {
                        surnameCount.begin()->second--;
                    }
                    else {
                        surnameCount.erase(surnameCount.begin());
                    }
                }
                else {
                    break;  
                }
            }
        }
}