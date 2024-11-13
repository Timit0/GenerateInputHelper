#pragma once
#include <iostream>
#include <vector>
#include <fstream> 
#include <string>

class Tscn
{
protected:
	std::string godotProjectPath;
	std::string outputPath;
	std::string fileAndClassName;
public:
	Tscn(std::string& godotProjectPath, std::string& outputPath, std::string& fileAndClassName);
	~Tscn();

	std::vector<std::string> get_all_input_name();
	void generate_InputFile();
};

