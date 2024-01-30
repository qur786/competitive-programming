#include <bits/stdc++.h>

using namespace std;

/**
 * Time complexity: O(n)
 * Space complexity: O(n)
 */

class ProductOfNumbers
{
private:
    vector<int> products;

public:
    ProductOfNumbers() {}

    void add(int num)
    {
        for (int &product : products)
        {
            product *= num;
        }

        products.emplace_back(num);
    }

    int getProduct(int k) { return products[products.size() - k]; }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */