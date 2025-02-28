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

// Function to find car by make STAGE 3
int findCarByMake(const vector<Car>& cars, const string& make) {
    for (size_t i = 0; i < cars.size(); i++) {
        if (cars[i].make == make) return i;
    }
    return -1;
}

// Function to count cars by make STAGE 3
map<string, int> countByMake(const vector<Car>& cars) {
    map<string, int> counts;
    for (const auto& car : cars) {
        counts[car.make]++;
    }
    return counts;
}

// Function to filter cars by year STAGE 3
vector<Car> filterByYear(const vector<Car>& cars, int year) {
    vector<Car> result;
    for (const auto& car : cars) {
        if (car.year == year) result.push_back(car);
    }
    return result;
}

// Function to search by substring in model STAGE 3
vector<Car> searchByModel(const vector<Car>& cars, const string& query) {
    vector<Car> result;
    for (const auto& car : cars) {
        if (car.model.find(query) != string::npos) result.push_back(car);
    }
    return result;
}

// Function to sort by engine size in descending order STAGE 3
void sortByEngineSize(vector<Car>& cars) {
    sort(cars.begin(), cars.end(), [](const Car& a, const Car& b) {
        return a.engine_size > b.engine_size;
    });
}

// Function to find highest, lowest, and average year STAGE 3
int findYearStats(const vector<Car>& cars, Car& minCar, Car& maxCar) {
    if (cars.empty()) return 0;

    minCar = maxCar = cars[0];
    int totalYears = 0;

    for (const auto& car : cars) {
        if (car.year < minCar.year) minCar = car;
        if (car.year > maxCar.year) maxCar = car;
        totalYears += car.year;
    }

    return totalYears / cars.size();
}

// Main Menu
void menu(vector<Car>& cars) {
    int choice;
    do {
        cout << "\n1. Display Cars\n2. Find Car by Make\n3. Count Cars by Make\n4. Filter by Year\n";
        cout << "5. Search by Model\n6. Sort by Engine Size\n7. Find Year Stats\n 8. Exit\nEnter choice: ";
        cin >> choice;
        if (choice == 1) displayCars(cars);
        else if (choice == 2) {
            string make;
            cout << "Enter make: "; cin >> make;
            int index = findCarByMake(cars, make);
            if (index != -1) cout << "Found: " << cars[index].make << " " << cars[index].model << '\n';
            else cout << "Car not found!\n";
        }
        else if (choice == 3) {
            auto counts = countByMake(cars);
            for (const auto& [make, count] : counts) {
                cout << make << ": " << count << '\n';
            }
        }
        else if (choice == 4) {
            int year;
            cout << "Enter year: "; cin >> year;
            auto filtered = filterByYear(cars, year);
            displayCars(filtered);
        }
        else if (choice == 5) {
            string query;
            cout << "Enter model keyword: "; cin >> query;
            auto results = searchByModel(cars, query);
            displayCars(results);
        }
        else if (choice == 6) {
            sortByEngineSize(cars);
            displayCars(cars);
        }
        else if (choice == 7) {
            Car minCar, maxCar;
            int avgYear = findYearStats(cars, minCar, maxCar);
            cout << "Oldest Car: " << minCar.year << " (" << minCar.make << " " << minCar.model << ")\n";
            cout << "Newest Car: " << maxCar.year << " (" << maxCar.make << " " << maxCar.model << ")\n";
            cout << "Average Year: " << avgYear << "\n";
        }
    } while (choice != 8);
}

int main() {
    vector<Car> cars;
    loadCars(cars, "cars.csv");
    menu(cars);
    return 0;
}
