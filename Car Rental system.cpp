#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct Car {
    string id, model, brand;
    double price;
    bool available;
};

class CarRental {
    vector<Car> cars;
public:
    CarRental() { loadCars(); }
   void loadCars() {
    ifstream file("cars.txt");
    if (!file) { 
        cout << "No existing car data found. Starting fresh.\n"; 
        return; 
    }
    Car car;
    while (file >> car.id) {
        file.ignore();
        getline(file, car.model, '|');
        getline(file, car.brand, '|');
        file >> car.price >> car.available;
        cars.push_back(car);
    }
}
    }
    void saveCars() {
        ofstream file("cars.txt");
        for (auto &car : cars)
            file << car.id << " " << car.model << " " << car.brand << " " << car.price << " " << car.available << "\n";
    }
    void addCar() {
        cout << "Enter Car ID: ";
        getline(cin >> ws, car.id);
        cout << "Enter Model: ";
        getline(cin >> ws, car.model);
        cout << "Enter Brand: ";
        getline(cin >> ws, car.brand);
        cout << "Enter Price: ";
        while (!(cin >> car.price)) {
            cout << "Invalid price. Try again: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }
        
    void displayCars() {
        for (auto &car : cars)
            if (car.available)
                cout << car.id << " " << car.model << " " << car.brand << " $" << car.price << "\n";
    }
    void updateCar(string id, bool avail) {
        for (auto &car : cars)
            if (car.id == id) { car.available = avail; saveCars(); return; }
        cout << "Invalid Car ID!\n";
    }
};

int main() {
    CarRental cr;
    int choice;
    string id;
    while (true) {
        cout << "1. Add Car 2. Show Cars 3. Rent 4. Return 5. Exit\nChoice: ";
        cin >> choice;
        if (choice == 1) cr.addCar();
        else if (choice == 2) cr.displayCars();
        else if (choice == 3 || choice == 4) {
            cout << "Enter Car ID: "; cin >> id;
            cr.updateCar(id, choice == 4);
        } else break;
    }
    return 0;
}
