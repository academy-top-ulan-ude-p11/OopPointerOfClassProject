#include <iostream>

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
    void Info()
    {
        cout << "transport " << title << "\n";
    }
};

class Car : public Transport
{
    int speed;
public:
    Car() : Car("", 0) {}
    Car(string title, int speed) : Transport(title), speed{ speed } {};
    void Info()
    {
        cout << "car " << title << " speed = " << speed << "\n";
    }
};

class Airplane : public Transport
{
    int heigth;
public:
    Airplane() : Airplane("", 0) {}
    Airplane(string title, int heigth) : Transport(title), heigth{ heigth } {};
    void Info()
    {
        cout << "Airplane " << title << " heigth = " << heigth << "\n";
    }
};

class Ship : public Transport
{
    bool pass;
public:
    Ship() : Ship("", false) {}
    Ship(string title, bool pass) : Transport(title), pass{ pass } {};
    void Info()
    {
        cout << "Ship " << title << " pass = " << pass << "\n";
    }
};

int main()
{
    /*Parent* parent = new Parent();
    Child* child = new Child();
    Parent* parentChild = new Child();*/

    Transport transports[4];
    Transport trans("Transport");
    Car car("Bmv", 200);
    Airplane airplane("SuperJet", 10000);
    Ship ship("Titanic", true);

    transports[0] = car;
    transports[1] = airplane;
    transports[2] = ship;
    transports[3] = trans;

    /*for (int i = 0; i < 4; i++)
    {
        transports[i].Info();
    }*/

    Transport* t = new Transport("Transport Wow");
    t->Info();
    t = new Car("Mercedes", 250);
    t->Info();

}
