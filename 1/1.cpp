#include "stdafx.h"
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <sstream>
#include <algorithm>    // std::min

typedef std::map<std::pair<int, int>, int> Dict;
enum Heading {North,East,West,South};
 class Santa {
 public:
	 Dict BlockMap;
	 Heading current = North;
	 int NrOFSteps = 0;
	 int X = 0;
	 int Y = 0;
	 void changeHeading(char c) {
		 if (c == 'R') {
			 if (current == North) 	 current = East;
			 else if (current == East) current = South;
			 else if (current == West) current = North;
			 else if (current == South) current = West;			 
		}
		 else if (c == 'L') {
			 if (current == North) 	 current = West;
			 else if (current == East) current = North;
			 else if (current == West) current = South;
			 else if (current == South) current = East;
		}
	 }
	 void moveAtHeading(int steps) {
		 for (int i = 0; i < steps; i++) {
			if (current == North) 	 Y+= 1;
			 else if (current == East) X += 1;
			 else if (current == West) X -= 1;
			 else if (current == South) Y -= 1;
			 visitPosition();
		 }		
	 }
	 void visitPosition() {
		 NrOFSteps++;
		 if (BlockMap.count(std::make_pair(X, Y)) > 0) {
			 BlockMap.at(std::make_pair(X, Y))++;
			 std::cout << "Twice: X:" << X << " Y:" << Y << '\n';
		 }
		 else {
			 BlockMap[std::make_pair(X, Y)] = 1;
		 }
	 }
};

 std::vector<std::string> Split(std::string input, char delim) {
	 std::stringstream ss;
	std::vector<std::string> seglist;
	std::string segment;
	ss.str(input);
	while (std::getline(ss, segment, delim))
	{
		seglist.push_back(segment);
	}
	return seglist;
 }


int main()
{
	Santa Santa;
	//::string input = "R8, R4, R4, R8";
	std::string input="R3, L5, R2, L2, R1, L3, R1, R3, L4, R3, L1, L1, R1, L3, R2, L3, L2, R1, R1, L1, R4, L1, L4, R3, L2, L2, R1, L1, R5, R4, R2, L5, L2, R5, R5, L2, R3, R1, R1, L3, R1, L4, L4, L190, L5, L2, R4, L5, R4, R5, L4, R1, R2, L5, R50, L2, R1, R73, R1, L2, R191, R2, L4, R1, L5, L5, R5, L3, L5, L4, R4, R5, L4, R4, R4, R5, L2, L5, R3, L4, L4, L5, R2, R2, R2, R4, L3, R4, R5, L3, R5, L2, R3, L1, R2, R2, L3, L1, R5, L3, L5, R2, R4, R1, L1, L5, R3, R2, L3, L4, L5, L1, R3, L5, L2, R2, L3, L4, L1, R1, R4, R2, R2, R4, R2, R2, L3, L3, L4, R4, L4, L4, R1, L4, L4, R1, L2, R5, R2, R3, R3, L2, L5, R3, L3, R5, L2, R3, R2, L4, L3, L1, R2, L2, L3, L5, R3, L1, L3, L4, L3";
	Santa.BlockMap[std::make_pair(0, 0)] = 1;
	for (std::string move : Split(input,',')) {	
		int i = 0;
		if (move.at(i) == ' ')  i++;
		Santa.changeHeading(move.at(i));
		i++;
		Santa.moveAtHeading(stoi(move.substr(i)));		
	}

	std::cout << "NrOFSteps: " << Santa.NrOFSteps << '\n';
	std::cout << "FinalCordinate: X:" << Santa.X << " Y:"<< Santa.Y << '\n';
	std::getline(std::cin, input);
	return 0;
}
