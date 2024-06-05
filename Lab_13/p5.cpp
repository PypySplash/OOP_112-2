#include <iostream>
using namespace std;



class PaymentStrategy 
{
public:
    virtual void execute() const = 0;
    virtual ~PaymentStrategy() {}
};

class CreditCardPayment : public PaymentStrategy
{
public:
    void execute() const override
    {
        cout << "Credit Card" << endl;
    }
};

class PayPalPayment : public PaymentStrategy
{
public:
    void execute() const override
    {
        cout << "PayPal" << endl;
    }
};

class BankTransferPayment : public PaymentStrategy
{
    void execute() const override
    {
        cout << "Bank Transfer" << endl;
    }
};



class PaymentContext 
{
private:
    PaymentStrategy* paymentStrategy;
public:
    PaymentContext(PaymentStrategy* paymentStrat = nullptr) : paymentStrategy(paymentStrat) {}
    void setStrategy(PaymentStrategy* paymentStrat)
    {
        paymentStrategy = paymentStrat;
    }
    void pay(int amount) const 
    {
        if (paymentStrategy)
        {
            cout << "Paying " << amount << " using ";
            paymentStrategy->execute();
        }
        else 
        {
            cout << "Strategy not set" << endl;
        }
    }
};



int main() {
    CreditCardPayment creditCardPayment;
    PayPalPayment payPalPayment;
    BankTransferPayment bankTransferPayment;
    PaymentContext paymentContext;
    paymentContext.setStrategy(&creditCardPayment);
    paymentContext.pay(100);
    paymentContext.setStrategy(&payPalPayment);
    paymentContext.pay(200);
    paymentContext.setStrategy(&bankTransferPayment);
    paymentContext.pay(300);
    return 0;
}