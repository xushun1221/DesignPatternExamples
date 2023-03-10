/*
 *  @Filename : Decorator.cc
 *  @Description :
 *  @Datatime : 2023/01/15 10:20:24
 *  @Author : xushun
 */

#include <iostream>

// 汽车抽象类
class Car
{
public:
    virtual void show() = 0;
};
// 实体汽车类
class BMW : public Car
{
public:
    void show() { std::cout << "这是一辆宝马汽车" << std::endl; }
};
class Audi : public Car
{
public:
    void show() { std::cout << "这是一辆奥迪汽车" << std::endl; }
};
class Benz : public Car
{
public:
    void show() { std::cout << "这是一辆奔驰汽车" << std::endl; }
};


// 装饰器01 定速巡航
class ConcreteCarDecorator01 : public Car
{
public:
    ConcreteCarDecorator01(Car *p) : pCar(p) {}
    void show() { 
        pCar->show(); // 原有功能
        std::cout << "(定速巡航)" << std::endl; // 增加了定速巡航的功能
    }
private:
    Car *pCar; // 装饰的对象指针
};
// 装饰器02 自动刹车
class ConcreteCarDecorator02 : public Car
{
public:
    ConcreteCarDecorator02(Car *p) : pCar(p) {}
    void show() { pCar->show(); std::cout << "(自动刹车)" << std::endl; }
private:
    Car *pCar;
};
// 装饰器03 车道偏离提醒
class ConcreteCarDecorator03 : public Car
{
public:
    ConcreteCarDecorator03(Car *p) : pCar(p) {}
    void show() { pCar->show(); std::cout << "(车道偏离提醒)" << std::endl; }
private:
    Car *pCar;
};


int main(int argc, char** argv)
{
    // 给一个BMW对象添加定速巡航功能
    Car* p1 = new ConcreteCarDecorator01(new BMW());
    p1->show();
    // 给一个Audi对象添加自动刹车、车道偏离提醒功能
    Car* p2 = new ConcreteCarDecorator01(new Audi());
    p2 = new ConcreteCarDecorator02(p2); // 装饰器也能装饰装饰器 因为装饰器也继承自Car抽象类
    p2->show();
    // 给一个Benz对象添加定速巡航、自动刹车、车道偏离提醒功能
    Car* p3 = new ConcreteCarDecorator01(new Benz());
    p3 = new ConcreteCarDecorator02(p3);
    p3 = new ConcreteCarDecorator03(p3);
    p3->show();
}