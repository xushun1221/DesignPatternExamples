/*
 *  @Filename : Car.cc
 *  @Description :
 *  @Datatime : 2023/01/10 21:14:15
 *  @Author : xushun
 */

#include <iostream>

class Car
{
public:
    Car(std::string name) : name_(name) {}
    virtual void show() = 0;

protected:
    std::string name_;
};

class BMW : public Car
{
public:
    BMW(std::string name) : Car(name) {}
    void show()
    {
        std::cout << "This is a BMW" << std::endl;
    }
};

class Audi : public Car
{
public:
    Audi(std::string name) : Car(name) {}
    void show()
    {
        std::cout << "This is an Audi" << std::endl;
    }
};

int main(int argc, char **argv)
{
    Car *p1 = new BMW("X1");
    Car *p2 = new Audi("A6");
    p1->show();
    p2->show();
    delete p1;
    delete p2;
    return 0;
}