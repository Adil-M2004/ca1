#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;


// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main()
{
    ifstream iFile;
    string line = "";
    string first = "";
    int location = 0;

    iFile.open("cars.csv");
    getline(iFile, line);
    getline(iFile, line);

    location = line.find(',');
    first = line.substr(0, location);
    line = line.substr(location + 1, line.length());
    cout << line << endl;

    return 0;

}



// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.