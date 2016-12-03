#include "stdafx.h"
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <sstream>
#include <algorithm> 

int APart(int temp,  std::string input) {
	int number = temp;
	for (char c : input) {
		if (c == 'U' && (number - 3) > 0)number -= 3;
		else if (c == 'D' && (number + 3) < 10)number += 3;
		else if (c == 'R' && number != 3 && number != 6 && number != 9) number++;
		else if (c == 'L' && number != 1 && number != 4 && number != 7) number--;
	}
	return number;
}

int BPart(int temp,  std::string input) {
	int number = temp;
	for (char c : input) {
		if (c == 'U' && number != 5 && number != 2 && number != 1 && number != 4 && number != 9) {
			if(number==3 || number == 13)number -= 2;
			else number -= 4;
		}
		else if (c == 'D' && number != 5 && number != 10 && number != 13 && number != 12 && number != 9) {
			if (number == 11 || number == 1) number += 2;
			else number += 4;
		}
		else if (c == 'R' && number != 1 && number != 4 && number != 9 && number != 12 && number != 13) number++;
		else if (c == 'L' && number != 1 && number != 2 && number != 5 && number != 10 && number != 13) number--;
	}
	return number;
}

int main()
{
	std::vector<int> Code;
	int number = 5;
	std::string input = "ULL";

	while (true) {
		std::cout << "Please, enter your input: ";
		std::getline(std::cin, input);
		if (input.size() == 0) {
			break;
		}
		else {
			number = BPart(number, input);
			Code.push_back(number);
		}
	}

	std::cout << "Code:";
	for (int num : Code) {
		if (num > 9) std::cout << (char)(num+55);
		else std::cout << num;
	}
	std::cout <<'\n';
	std::getline(std::cin, input);
	return 0;
}
