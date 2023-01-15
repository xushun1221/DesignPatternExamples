/*
 *  @Filename : Observer.cc
 *  @Description :
 *  @Datatime : 2023/01/15 14:18:52
 *  @Author : xushun
 */

#include <iostream>
#include <unordered_map>
#include <list>

// 观察者抽象类
class Observer
{
public:
    // 处理消息的接口
    virtual void handle(int msgid) = 0;
};
// 观察者实体类
class Observer01 : public Observer
{
public:
    void handle(int msgid)
    { // 对 1 2 号消息感兴趣
        switch (msgid)
        {
        case 1:
            std::cout << "Observer01 recv msg: 1" << std::endl;
            break;
        case 2:
            std::cout << "Observer01 recv msg: 2" << std::endl;
            break;
        default:
            std::cout << "Observer01 recv msg: unknown" << std::endl;
            break;
        }
    }
};
class Observer02 : public Observer
{
public:
    void handle(int msgid)
    { // 对 2 号消息感兴趣
        switch (msgid)
        {
        case 2:
            std::cout << "Observer02 recv msg: 2" << std::endl;
            break;
        default:
            std::cout << "Observer02 recv msg: unknown" << std::endl;
            break;
        }
    }
};
class Observer03 : public Observer
{
public:
    void handle(int msgid)
    { // 对 1 3 号消息感兴趣
        switch (msgid)
        {
        case 1:
            std::cout << "Observer03 recv msg: 1" << std::endl;
            break;
        case 3:
            std::cout << "Observer03 recv msg: 3" << std::endl;
            break;
        default:
            std::cout << "Observer03 recv msg: unknown" << std::endl;
            break;
        }
    }
};

// 主题类
class Subject
{
public:
    // 添加观察者
    void addObserver(Observer *observer, int msgid)
    {
        subMap[msgid].push_back(observer);
    }
    // 主题发生变化 通知观察者
    void dispatch(int msgid)
    {
        auto it = subMap.find(msgid);
        if (it != subMap.end()) {
            for (auto pObserver : it->second)
            {
                pObserver->handle(msgid);
            }
        }
    }

private:
    // 记录每个类型消息的观察者们
    std::unordered_map<int, std::list<Observer *>> subMap;
};

int main(int argc, char **argv)
{
    Subject subject;
    Observer* p1 = new Observer01();
    subject.addObserver(p1, 1);
    subject.addObserver(p1, 2);
    Observer* p2 = new Observer02();
    subject.addObserver(p2, 2);
    Observer* p3 = new Observer03();
    subject.addObserver(p3, 1);
    subject.addObserver(p3, 3);

    int msgid = 0;
    for (;;)
    {
        std::cout << "enter msgid(-1 to exit): ";
        std::cin >> msgid;
        if (msgid == -1)
        {
            break;
        }
        subject.dispatch(msgid);
    }

    return 0;
}