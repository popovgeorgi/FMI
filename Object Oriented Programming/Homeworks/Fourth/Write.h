#pragma once
void writeIntoFile(const char* name, std::vector<Shape*>& shapes)
{
    std::ofstream outFile(name, ios::trunc);
    if (!outFile.is_open())
    {
        std::cout << "File does not exist" << std::endl;
        return;
    }

    outFile << "<?xml version=\"1.0\" standalone=\"no\"?>" << '\n';
    outFile << "<!DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 1.1//EN\"" << '\n';
    outFile << "\"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">" << '\n';
    outFile << "<svg>" << std::endl;
    for (size_t i = 0; i < shapes.size(); i++)
    {
        outFile << shapes[i]->getXMLRepresentation();
    }
    outFile << "</svg>" << std::endl;
}