#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>

using namespace std;

// A structure to store the license index and its cost at a particular month
struct License {
    int id;
    double cost;

    License(int _id, double _cost) : id(_id), cost(_cost) {}
};

// A structure to compare licenses based on their cost at the current month
struct LicenseComparator {
    bool operator()(const License& a, const License& b) const {
        return a.cost < b.cost;
    }
};

// A function to compute the order in which to buy the licenses to minimize the total cost
vector<int> compute_license_order(const vector<double>& growth_rates) {
    int num_licenses = growth_rates.size();

    // Initialize a vector of licenses with their current cost at month 0
    vector<License> licenses;
    for (int i = 0; i < num_licenses; i++) {
        licenses.emplace_back(i, 100 * growth_rates[i]);
    }

    // Sort the licenses based on their cost at month 0
    sort(licenses.begin(), licenses.end(), LicenseComparator());

    // Initialize the order of licenses to buy
    vector<int> order(num_licenses);
    for (int i = 0; i < num_licenses; i++) {
        order[i] = licenses[i].id;
    }

    return order;
}

int main() {
    int num_licenses;
    cout<<"Enter the number of licenses:"<<endl;
    cin >> num_licenses;

    // Input the growth rates of the licenses
    vector<double> growth_rates(num_licenses);
    cout << "Enter the growth rates of the licenses: ";
    for (int i = 0; i < num_licenses; i++) {
        cin >> growth_rates[i];
    }

    // Compute the order of licenses to buy
    vector<int> order = compute_license_order(growth_rates);

    // Output the order of licenses to buy
    cout << "The order of licenses to buy is: ";
    for (int i = 0; i < num_licenses; i++) {
        cout << order[i] << " ";
    }
    cout << endl;

    return 0;
}
