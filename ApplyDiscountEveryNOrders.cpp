
#include<bits/stdc++.h>

using namespace std;

class Cashier 
{
private :
    int discountNum;
    int discountAmt;
    int currCustomerIndex;
    int prices[200];

public:
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) 
    {
        this->discountNum = n;
        this->discountAmt = discount;
        this->currCustomerIndex = 0;

        for(int a = 0; a < products.size(); ++a)
        {
            this->prices[products[a]-1] = prices[a];
        }
    }
    
    double getBill(vector<int> product, vector<int> amount) 
    {
        double bill = 0.0;
        for(int a = 0; a < product.size(); ++a)
        {
            bill += prices[product[a]-1] * amount[a];
        }

        if(++currCustomerIndex == discountNum)
        {
            bill = bill - (discountAmt * bill) / 100;
            currCustomerIndex = 0;
        }
        
        return bill;
    }
};