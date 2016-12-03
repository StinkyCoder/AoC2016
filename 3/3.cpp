// 3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <regex>
#include <algorithm>  
#include <map>

class Triangle {
public:
	int x, y, z;
};

typedef std::vector<std::string> StrList;
typedef std::vector<Triangle> Triangles;
Triangles TrianglesToBe;

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

Triangle ParseTriangle(std::string input) {
	Triangle Triangle;
	StrList match = Split(input, ' ');
	StrList numberList;
	for (std::string s : match) {
		if (s.length() > 0)		numberList.push_back(s);
	}
	Triangle.x = stoi(numberList[0]);
	Triangle.y = stoi(numberList[1]);
	Triangle.z = stoi(numberList[2]);

	return Triangle;
}

int main()
{
	int trianglesssss = 0;;
	std::string input;
	std::cout << "Please, enter your input: ";
	std::getline(std::cin, input);
	while (input.size() != 0) {
		Triangle Triangle = ParseTriangle(input);
		TrianglesToBe.push_back(Triangle);
		std::cout << "Please, enter your input: ";
		std::getline(std::cin, input);
	}

	for (Triangle Triangle : TrianglesToBe) {
		int sum = Triangle.x + Triangle.y + Triangle.z;
		int min = std::max(Triangle.x, std::max(Triangle.y, Triangle.z));
		sum -= min;
		if (sum > min)  trianglesssss++;
	}

	std::cout << "NrofA: " << trianglesssss << '\n';
	trianglesssss = 0;
	for (int i = 0; i < TrianglesToBe.size() - 1; i += 3) {
		Triangle Triangle1 = TrianglesToBe[i];
		Triangle Triangle2 = TrianglesToBe[i + 1];
		Triangle Triangle3 = TrianglesToBe[i + 2];
		int sum = Triangle1.x + Triangle2.x + Triangle3.x;
		int min = std::max(Triangle1.x, std::max(Triangle2.x, Triangle3.x));
		sum -= min;
		if (sum > min)  trianglesssss++;

		sum = Triangle1.y + Triangle2.y + Triangle3.y;
		min = std::max(Triangle1.y, std::max(Triangle2.y, Triangle3.y));
		sum -= min;
		if (sum > min)  trianglesssss++;

		sum = Triangle1.z + Triangle2.z + Triangle3.z;
		min = std::max(Triangle1.z, std::max(Triangle2.z, Triangle3.z));
		sum -= min;
		if (sum > min)  trianglesssss++;
	}

	std::cout << "NrofB: " << trianglesssss << '\n';
	std::getline(std::cin, input);
	return 0;
}