
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
struct City {
    string name;
    int x;
    int y;
};

vector<City> cities;

void insertCity(const string& name, int x, int y) {
    City city;
    city.name = name;
    city.x = x;
    city.y = y;
    cities.push_back(city);
}

void deleteCity(const string& name) {
    for (int i = 0; i < cities.size(); i++) {
        if (cities[i].name == name) {
            cities.erase(cities.begin() + i);
            i--;
        }
    }
}

void deleteCity(int x, int y) {
    for (int i = 0; i < cities.size(); i++) {
        if (cities[i].x == x && cities[i].y == y) {
            cities.erase(cities.begin() + i);
            i--;
        }
    }
}

vector<City> searchCity(const string& name) {
    vector<City> results;
    for (int i = 0; i < cities.size(); i++) {
        if (cities[i].name == name) {
            results.push_back(cities[i]);
        }
    }
    return results;
}

vector<City> searchCity(int x, int y) {
    vector<City> results;
    for (int i = 0; i < cities.size(); i++) {
        if (cities[i].x == x && cities[i].y == y) {
            results.push_back(cities[i]);
        }
    }
    return results;
}

void printCitiesWithinDistance(int x, int y, int distance) {
    for (int i = 0; i < cities.size(); i++) {
        int dx = cities[i].x - x;
        int dy = cities[i].y - y;
        if (sqrt(dx * dx + dy * dy) <= distance) {
            cout << cities[i].name << " " << cities[i].x << " " << cities[i].y << endl;
        }
    }
}

int main() {
    int choice;
    string name;
    int x, y, distance;
    vector<City> results;
    while (true) {
        cout << "1. Insert a city" << endl;
        cout << "2. Delete a city" << endl;
        cout << "3. Search for a city" << endl;
        cout << "4. Print cities within a distance" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice == 1) {
            cout << "Enter the name of the city: ";
            cin >> name;
            cout << "Enter the x coordinate of the city: ";
            cin >> x;
            cout << "Enter the y coordinate of the city: ";
            cin >> y;
            insertCity(name, x, y);
        } else if (choice == 2) {
            cout << "Enter the name of the city: ";
            cin >> name;
            deleteCity(name);
        } else if (choice == 3) {
            cout << "Enter the name of the city: ";
            cin >> name;
            results = searchCity(name);
            for (int i = 0; i < results.size(); i++) {
                cout << results[i].name << " " << results[i].x << " " << results[i].y << endl;
            }
    } //print cities within a distance of a given city and if theres no city with that name print no city found
        else if (choice == 4) {
            cout << "Enter the name of the city: ";
            cin >> name;
            cout << "Enter the distance: ";
            cin >> distance;
            results = searchCity(name);
            if (results.size() == 0) {
                cout << "No city found" << endl;
            } else {
                for (int i = 0; i < results.size(); i++) {
                    printCitiesWithinDistance(results[i].x, results[i].y, distance);
                }
            }

        } else if (choice == 5) {
            break;
        }
        else{
            cout<<"Invalid choice"<<endl;
        }
    }
    return 0;
}
