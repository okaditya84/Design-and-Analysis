#include <iostream>
#include <unordered_map>
using namespace std;

struct City {
    int x;
    int y;
};

class CityDatabase {
    public:
        unordered_map<string, City> cities;

        void insert_city(string name, int x, int y) {
            City city = {x, y};
            cities[name] = city;
        }

        void delete_city_by_name(string name) {
            cities.erase(name);
        }

        City* search_city_by_name(string name) {
            if (cities.find(name) != cities.end())
                return &cities[name];
            else
                return nullptr;
        }

        void print_database() {
            for (auto& city : cities) {
                cout << city.first << ": (" << city.second.x << ", " << city.second.y << ")" << endl;
            }
        }


        unordered_map<string, City> search_city_by_distance(int x, int y, int distance) {

            unordered_map<string, City> result;
            for (auto& city : cities) {
                int dist_x = abs(city.second.x - x);
                int dist_y = abs(city.second.y - y);
                if(dist_x * dist_x + dist_y * dist_y <= distance * distance) {
                    result[city.first] = city.second;
                }
            }
            return result;
        }
};

int main() {
    CityDatabase db;
    int choice;
    //display menu
    cout << "1. Insert city" << endl;
    cout << "2. Delete city" << endl;
    cout << "3. Search city by name" << endl;
    cout << "4. Search city by distance" << endl;
    cout << "5. Print database" << endl;
    cout << "6. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    
    while (choice != 6) {
        switch (choice) {
            case 1: {
                string name;
                int x, y;
                cout<<"Enter city name:"<<endl;
                cin>>name;
                cout<<"Enter x coordinate:"<<endl;
                cin>>x;
                cout<<"Enter y coordinate:"<<endl;
                cin>>y;
                
                db.insert_city(name, x, y);
                break;
            }
            case 2: {
                string name;
                cout << "Enter name: ";
                cin >> name;
                db.delete_city_by_name(name);
                break;
            }
            case 3: {
                string name;
                cout << "Enter name: ";
                cin >> name;
                City* city = db.search_city_by_name(name);
                if (city != nullptr) {
                    cout << "Found " << name << ": (" << city->x << ", " << city->y << ")" << endl;
                } else {
                    cout << "Not found" << endl;
                }
                break;
            }
            case 4: {
                int x, y, distance;
                cout << "Enter x, y, distance: ";
                cin >> x >> y >> distance;
                unordered_map<string, City> result = db.search_city_by_distance(x, y, distance);
                for (auto& city : result) {
                    cout << city.first << ": (" << city.second.x << ", " << city.second.y << ")" << endl;
                }
                break;
            }
            case 5: {
                db.print_database();
                break;
            }
            default: {
                cout << "Invalid choice" << endl;
            }
        }
        cout << "Enter your choice: ";
        cin >> choice;
    }

}
