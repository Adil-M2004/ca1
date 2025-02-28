#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <map>
#include <algorithm>
#include <iomanip>

using namespace std;

// Struct representing a car STAGE 2
struct Car {
    int id;
    string make;
    string model;
    int year;
    float engine_size;
};

// Function to read CSV into a vector of Car structs STAGE 2
void loadCars(vector<Car>& cars, const string& filename) {
    ifstream file(filename);
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        Car car;
        ss >> car.id; ss.ignore();
        getline(ss, car.make, ',');
        getline(ss, car.model, ',');
        ss >> car.year; ss.ignore();
        ss >> car.engine_size;
        cars.push_back(car);
    }
    file.close();
}

// Function to display car data STAGE 3
void displayCars(const vector<Car>& cars) {
    cout << left << setw(6) << "ID"
         << setw(12) << "Make"
         << setw(12) << "Model"
         << setw(8) << "Year"
         << setw(12) << "Engine Size" << '\n';
    cout << "--------------------------------------------------\n";
    for (const auto& car : cars) {
        cout << setw(6) << car.id
             << setw(12) << car.make
             << setw(12) << car.model
             << setw(8) << car.year
             << setw(12) << fixed << setprecision(1) << car.engine_size << '\n';
    }
}



int main() {
    vector<Car> cars;
    loadCars(cars, "cars.csv");
    return 0;
}
