// 4.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>    
#include <map>
#include <fstream>

typedef std::map<char, int> Dict;
typedef std::map<std::string, std::string> TextDict;
typedef std::vector<std::string> StrList;
typedef std::vector<char> CharList;
typedef std::map<char, int>::iterator it_type;
typedef std::map<std::string, std::string>::iterator it_type2;
TextDict Rooms;

StrList Split(std::string input, char delim) {
	std::stringstream ss;
	StrList seglist;
	std::string segment;
	ss.str(input);
	while (std::getline(ss, segment, delim))
	{
		seglist.push_back(segment);
	}
	return seglist;
}

char JumpForward(char c, int jumps) {
	char out = c;
	for (int i = 0; i < jumps; i++) {
		if ((out + 1) > 122) out = 'a';
		else out = out +1;
	}	
	return out;
}

void ParseText(StrList List) {
	int InitLoop = stoi(List[List.size() - 1]);
	//int temp = (InitLoop / 25);
	//double temp2 = ((double)InitLoop / 25.0);
	//int Forward = 25 * ( temp2-temp);
	std::string orignal;
	std::string out;
	for (int i = 0; i < List.size() - 1; i++) {
		std::string s = List[i];
		for (char c : s) {
			out += JumpForward(c, InitLoop);
		}
		out += ' ';
		orignal += s;
		orignal += ' ';
	}
	

	Rooms[out] = std::to_string(InitLoop)+ '-' +  orignal;
}

int ParseRoomNumber(std::string input) {
	CharList EndList;
	StrList Part = Split(input, '[');
	Dict dict;
	if (Part.size() == 2) {
		StrList List = Split(Part.at(0), '-');
		for (int i = 0; i < List.size() - 1; i++) {
			std::string s = List[i];
			for (char c : s) {
				dict[c]++;
			}
		}

		char c = '{';
		int highval = 0;
		for (int i = 0; i < 5; i++) {
			for (it_type iterator = dict.begin(); iterator != dict.end(); iterator++) {
				if (iterator->second >= highval && std::find(EndList.begin(), EndList.end(), iterator->first) == EndList.end()) {
					if (iterator->second == highval) {
						if (iterator->first < c) {
							c = iterator->first;
							highval = iterator->second;
						}
					}
					else {
						c = iterator->first;
						highval = iterator->second;
					}					
				}
			}
			EndList.push_back(c);
			c = '{';
			highval = 0;
		}

		for (int i = 0; i < Part[1].size() - 1; i++) {
			if (std::find(EndList.begin(), EndList.end(), Part[1][i]) == EndList.end()) {
				return 0;
			}
		}
		ParseText(List);
		return stoi(List[List.size()-1]);
	}
	else std::cout << "Bad Input -> " << input << '\n';
	return 0;
}

int main()
{
	ParseText({ "qzmt","zixmtkozy","ivhz","343" });


	int GoodRooms = 0;
	std::string input;
	std::cout << "Please, enter your input: ";
	std::getline(std::cin, input);
	while (input.size() != 0) {
	 GoodRooms += ParseRoomNumber(input);
		std::cout << "Please, enter your input: ";
		std::getline(std::cin, input);
	}

	std::cout << "NrOfRooms: " << GoodRooms << '\n';
	std::ofstream myfile;
	myfile.open("example.txt");
	for (it_type2 iterator = Rooms.begin(); iterator != Rooms.end(); iterator++) {
		myfile << "Text: " << iterator->first << "  ID:"<< iterator->second << '\n';
	}
	myfile.close();
	std::getline(std::cin, input);
	return 0;
}



