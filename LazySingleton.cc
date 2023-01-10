/*
 *  @Filename : LazySingleton.cc
 *  @Description :
 *  @Datatime : 2023/01/10 17:33:36
 *  @Author : xushun
 */

class LazySingleton
{
public:
    // 是否线程安全?
    static LazySingleton *getInstance()
    {
        // #2 第一次获取时 创建该对象实例
        if (instance == nullptr)
        {
            instance = new LazySingleton();
        }
        return instance;
    }

private:
    LazySingleton()
    {
    }
    // #1 使用指针来管理唯一的实例对象
    static LazySingleton *instance;
    LazySingleton(const LazySingleton &) = delete;
    LazySingleton &operator=(const LazySingleton &) = delete;
};

// 实例对象的指针初始时为空
LazySingleton *LazySingleton::instance = nullptr;

int main(int argc, char **argv)
{
    // 在p1获取对象实例时 该对象才被实例化
    LazySingleton *p1 = LazySingleton::getInstance();
    LazySingleton *p2 = LazySingleton::getInstance();
    LazySingleton *p3 = LazySingleton::getInstance();

    return 0;
}