#include "Tscn.h";

Tscn::Tscn(std::string& godotProjectPath, std::string& outputPath, std::string& fileAndClassName)
{
	this->godotProjectPath = godotProjectPath;
    this->outputPath = outputPath;
    this->fileAndClassName = fileAndClassName;
	std::cout << godotProjectPath;
}

Tscn::~Tscn()
{
	
}

std::vector<std::string> Tscn::get_all_input_name()
{
    std::ifstream file(this->godotProjectPath);
    std::string line;
    std::string fileContent;

    bool inputHasStarted = false;
    std::vector<std::string> listInputName;
    while (std::getline(file, line))
    {
        if (line == "[input]")
        {
            inputHasStarted = true;
            continue;
        }

        if (line[0] == '[')
        {
            inputHasStarted = false;
        }

        
        if (inputHasStarted)
        {
            //if line contain =
            if (line.find("=") != std::string::npos)
            {
                std::string inputName = line.substr(0, line.find("="));
                listInputName.push_back(inputName);
            }
        }
        
    }
    return listInputName;

}

void Tscn::generate_InputFile()
{
    std::string content;
    content += "public static class " + this->fileAndClassName+"\n";
    content += "{\n";

    for(std::string x : this->get_all_input_name())
    {
        content += "\tpublic static string " + x + "\n";
        content += "\t{\n";
        content += "\t\tget\n";
        content += "\t\t{\n";
        content += "\t\t\treturn nameof("+x+");\n";
        content += "\t\t}\n";
        content += "\t}\n";
    }

    content += "}";

    std::string outputFilePath = this->outputPath + "/" + this->fileAndClassName + ".cs";

    // Create and write to the file
    std::ofstream file(outputFilePath);
    if (!file.is_open())
    {
        std::cerr << "Error: Could not create the file at " << outputFilePath << std::endl;
        return;
    }

    file << content;
    file.close();

}