/*
 *  @Filename : LazySingleton_thread_safe_2.cc
 *  @Description : 
 *  @Datatime : 2023/01/10 20:39:14
 *  @Author : xushun
 */

class LazySingleton
{
public:
    // 线程安全的实现
    static LazySingleton *getInstance()
    {
        // 函数静态局部变量的初始化 只会进行一次
        // 多线程环境下 也不会出现竞态条件
        static LazySingleton instance;
        return &instance;
    }

private:
    LazySingleton()
    {
    }
    LazySingleton(const LazySingleton &) = delete;
    LazySingleton &operator=(const LazySingleton &) = delete;
};

int main(int argc, char **argv)
{
    LazySingleton *p1 = LazySingleton::getInstance();
    LazySingleton *p2 = LazySingleton::getInstance();
    LazySingleton *p3 = LazySingleton::getInstance();

    return 0;
}