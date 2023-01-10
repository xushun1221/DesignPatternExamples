/*
 *  @Filename : FactoryMethod.cc
 *  @Description :
 *  @Datatime : 2023/01/10 21:46:20
 *  @Author : xushun
 */

#include <iostream>
#include <memory>

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

// Factory Method
class Factory
{
public:
    virtual Car *createCar(std::string name) = 0;
};

// BMW Factory
class BMWFactory : public Factory
{
public:
    Car *createCar(std::string name)
    {
        return new BMW(name);
    }
};

// Audi Factory
class AudiFactory : public Factory
{
public:
    Car *createCar(std::string name)
    {
        return new Audi(name);
    }
};

// ... other Factory

int main(int argc, char **argv)
{
    std::unique_ptr<Factory> BMWfactory(new BMWFactory());
    std::unique_ptr<Factory> Audifactory(new AudiFactory());
    std::unique_ptr<Car> p1(BMWfactory->createCar("X6"));
    std::unique_ptr<Car> p2(Audifactory->createCar("A8"));
    p1->show();
    p2->show();
    return 0;
}