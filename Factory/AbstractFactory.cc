/*
 *  @Filename : AbstractFactory.cc
 *  @Description :
 *  @Datatime : 2023/01/11 12:13:36
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

// other products
class CarLight
{
public:
    virtual void show() = 0;
};
class BMWLight : public CarLight
{
public:
    void show()
    {
        std::cout << "BMW Light" << std::endl;
    }
};
class AudiLight : public CarLight
{
public:
    void show()
    {
        std::cout << "Audi Light" << std::endl;
    }
};

class AbstractFactory
{
public:
    virtual Car *createCar(std::string name) = 0;
    virtual CarLight *createCarLight() = 0;
};

class BMWFactory : public AbstractFactory
{
public:
    Car *createCar(std::string name)
    {
        return new BMW(name);
    }
    CarLight *createCarLight()
    {
        return new BMWLight();
    }
};

class AudiFactory : public AbstractFactory
{
public:
    Car *createCar(std::string name)
    {
        return new Audi(name);
    }
    CarLight *createCarLight()
    {
        return new AudiLight();
    }
};

int main(int argc, char **argv)
{
    std::unique_ptr<AbstractFactory> BMWfactory(new BMWFactory());
    std::unique_ptr<AbstractFactory> Audifactory(new AudiFactory());
    std::unique_ptr<Car> p1(BMWfactory->createCar("X6"));
    std::unique_ptr<Car> p2(Audifactory->createCar("A8"));
    std::unique_ptr<CarLight> l1(BMWfactory->createCarLight());
    std::unique_ptr<CarLight> l2(Audifactory->createCarLight());
    p1->show();
    p2->show();
    l1->show();
    l2->show();
    return 0;
}