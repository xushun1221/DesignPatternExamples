/*
 *  @Filename : EagerSingleton.cc
 *  @Description :
 *  @Datatime : 2023/01/10 17:04:55
 *  @Author : xushun
 */

class EagerSingleton
{
public:
    // #3 获取类的唯一对象实例的接口方法
    static EagerSingleton *getInstance()
    {
        return &instance;
    }

private:
    // #1 构造函数自由化
    EagerSingleton()
    {
    }
    // #2 定义唯一的对象实例
    static EagerSingleton instance;
    // #4 去掉拷贝构造和赋值重载
    EagerSingleton(const EagerSingleton &) = delete;
    EagerSingleton &operator=(const EagerSingleton &) = delete;
};

// 静态成员变量要在类外进行初始化
EagerSingleton EagerSingleton::instance;

int main(int argc, char **argv)
{
    // 在获取对象实例之前 唯一的对象就已经产生了
    EagerSingleton *p1 = EagerSingleton::getInstance();
    EagerSingleton *p2 = EagerSingleton::getInstance();
    EagerSingleton *p3 = EagerSingleton::getInstance();

    return 0;
}