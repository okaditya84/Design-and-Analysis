//implement city database using unordered lists array based and each database contains name of the city and its x y coordinates 

#include <bits/stdc++.h>
using namespace std;

//structure of city
struct city
{
    string name;
    int x;
    int y;
};

//structure of database
struct database
{
    city *cities;
    int size;
    int capacity;
};

//function to create database
database *createDatabase(int capacity)
{
    database *db = new database;
    db->cities = new city[capacity];
    db->size = 0;
    db->capacity = capacity;
    return db;
}

//function to insert city in database
void insertCity(database *db, string name, int x, int y)
{
    if (db->size == db->capacity)
    {
        cout << "Database is full" << endl;
        return;
    }
    db->cities[db->size].name = name;
    db->cities[db->size].x = x;
    db->cities[db->size].y = y;
    db->size++;
}

//function to search city in database

int searchCity(database *db, string name)
{
    for (int i = 0; i < db->size; i++)
    {
        if (db->cities[i].name == name)
        {
            return i;
        }
    }
    return -1;
}

//function to delete city from database

void deleteCity(database *db, string name)
{
    int index = searchCity(db, name);
    if (index == -1)
    {
        cout << "City not found" << endl;
        return;
    }
    for (int i = index; i < db->size - 1; i++)
    {
        db->cities[i] = db->cities[i + 1];
    }
    db->size--;
}

//function to print database

void printDatabase(database *db)
{
    for (int i = 0; i < db->size; i++)
    {
        cout << db->cities[i].name << " " << db->cities[i].x << " " << db->cities[i].y << endl;
    }
}

//main function with user input


int main(){
    string name;
    int x,y,choice;
    database *db=createDatabase(10);
    while(1){
    

        cout<<"Enter your choice"<<endl;
        cout<<"1. Insert city"<<endl;
        cout<<"2. Search city"<<endl;
        cout<<"3. Delete city"<<endl;
        cout<<"4. Print database"<<endl;
        cout<<"5. Exit"<<endl;
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"Enter the name of city"<<endl;
                cin>>name;
                cout<<"Enter the x coordinate of city"<<endl;
                cin>>x;
                cout<<"Enter the y coordinate of city"<<endl;
                cin>>y;
                insertCity(db,name,x,y);
                break;
            case 2:
                cout<<"Enter the name of city"<<endl;
                cin>>name;
                if(searchCity(db,name)==-1){
                    cout<<"City not found"<<endl;
                }
                else{
                    cout<<"City found"<<endl;
                }
                break;
            case 3:
                cout<<"Enter the name of city"<<endl;
                cin>>name;
                deleteCity(db,name);
                break;
            case 4:
cout<<"Database is"<<endl;
                printDatabase(db);
                break;
            case 5:
                exit(0);
            default:
                cout<<"Invalid choice"<<endl;
        }
    }
    return 0;

}