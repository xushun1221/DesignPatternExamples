/*
 *  @Filename : SimpleFactory.cc
 *  @Description :
 *  @Datatime : 2023/01/10 21:25:49
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

enum CarType
{
    bmw,
    audi
};

class SimpleFactory
{
public:
    Car *createCar(CarType ct)
    {
        switch (ct)
        {
        case bmw:
            return new BMW("X1");
        case audi:
            return new Audi("A6");
        default:
            std::cerr << "wrong cartype: " << ct << std::endl;
            break;
        }
        return nullptr;
    }
};

int main(int argc, char **argv)
{
    std::unique_ptr<SimpleFactory> factory(new SimpleFactory());
    std::unique_ptr<Car> p1(factory->createCar(bmw));
    std::unique_ptr<Car> p2(factory->createCar(audi));
    p1->show();
    p2->show();
    return 0;
}