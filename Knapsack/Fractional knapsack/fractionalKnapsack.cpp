#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Item {
public:
    int weight, value;

    Item(int w, int v) {
        weight = w;
        value = v;
    }
};

// custom comparator function to sort items based on value-to-weight ratio
bool cmp(Item a, Item b) {
    return (double)a.value / a.weight > (double)b.value / b.weight;
}

double fractionalKnapsack(vector<Item> &items, int capacity) {
    sort(items.begin(), items.end(), cmp);
    
    double totalValue = 0.0;
    
    for (Item item : items) {
        if (capacity >= item.weight) {
            totalValue += item.value;
            capacity -= item.weight;
        } else {
            totalValue += (double)item.value * capacity / item.weight;
            break;
        }
    }

    return totalValue;
}

int main() {
    vector<Item> items = {{10, 60}, {20, 100}, {30, 120}};
    int capacity = 50;

    cout << "Maximum value in Knapsack: " << fractionalKnapsack(items, capacity) << endl;
    return 0;
}
