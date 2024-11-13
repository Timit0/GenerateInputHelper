#include <iostream>
#include <string>
#include <fstream> 
#include "Tscn.h";

void user_param_enter(std::string& v, std::string prompt);

int main()
{
    std::string godotProjectPath;
    user_param_enter(godotProjectPath, "Enter project.godot path");

    std::string outputPath;
    user_param_enter(outputPath, "Enter the output path");

    std::string fileAndClassName;
    user_param_enter(fileAndClassName, "set the file and class name");

    Tscn* tscnFile = new Tscn(godotProjectPath, outputPath, fileAndClassName);
    tscnFile->generate_InputFile();
    delete tscnFile;
}

void user_param_enter(std::string& v, std::string prompt)
{
    while (true)
    {
        std::cout << prompt + " : ";
        std::getline(std::cin, v);

        if (!v.empty()) {
            return;
        }
    }
}