#include <iostream>
#include <string>

using namespace std;

class Parent
{
public:
    Parent()
    {
        std::cout << this << " - parent\n";
    }
};

class Child : public Parent
{
public:
    Child()
    {
        std::cout << this << " - child\n";
    }
};

class Transport
{
protected:
    string title;
public:
    Transport(string title = "") : title{title} {}
    virtual string Info()
    {
        return "transport " + title;
    }
};

class Car : public Transport
{
protected:
    int speed;
public:
    Car() : Car("", 0) {}
    Car(string title, int speed) : Transport(title), speed{ speed } {};
    string Info() override
    {
        return "car " + title + " speed = " + to_string(speed);
    }
};

class Bus : public Car
{
public:
    Bus(string title, int speed) : Car(title, speed) {};
    string Info() override
    {
        return "bus " + title + " speed = " + to_string(speed);
    }
};

class Airplane : public Transport
{
    int heigth;
public:
    Airplane() : Airplane("", 0) {}
    Airplane(string title, int heigth) : Transport(title), heigth{ heigth } {};
    string Info() override
    {
        return "Airplane " + title + " heigth = " + to_string(heigth);
    }
};

class Ship : public Transport
{
    bool pass;
public:
    Ship() : Ship("", false) {}
    Ship(string title, bool pass) : Transport(title), pass{ pass } {};
    string Info() override
    {
        return "Ship " + title + " pass = " + to_string(pass);
    }
};

int main()
{
    /*Parent* parent = new Parent();
    Child* child = new Child();
    Parent* parentChild = new Child();*/

    Transport** transports = new Transport*[5];

    Transport* trans = new Transport("Transport");
    Car* car = new Car("Bmv", 200);
    Airplane* airplane = new Airplane("SuperJet", 10000);
    Ship* ship = new Ship("Titanic", true);
    Bus* bus = new Bus("Gazel", 80);

    transports[0] = car;
    transports[1] = airplane;
    transports[2] = ship;
    transports[3] = trans;
    transports[4] = bus;


    for (int i = 0; i < 5; i++)
    {
        cout << transports[i]->Info() << "\n";
    }
    
}
