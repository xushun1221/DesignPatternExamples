/*
 *  @Filename : LazySingleton_thread_safe.cc
 *  @Description :
 *  @Datatime : 2023/01/10 20:13:18
 *  @Author : xushun
 */

#include <mutex>

class LazySingleton
{
public:
    // 线程安全的实现
    static LazySingleton *getInstance()
    {
        if (instance == nullptr)
        {
            // 互斥锁+双重判断 保护临界区
            std::lock_guard<std::mutex> guard(mtx_instance);
            if (instance == nullptr)
            {
                instance = new LazySingleton();
            }
        }
        return instance;
    }

private:
    LazySingleton()
    {
    }
    // 使用volatile保证不同线程看到的instance相同
    static LazySingleton *volatile instance;
    // 互斥锁
    static std::mutex mtx_instance;
    LazySingleton(const LazySingleton &) = delete;
    LazySingleton &operator=(const LazySingleton &) = delete;
};

LazySingleton *volatile LazySingleton::instance = nullptr;
std::mutex LazySingleton::mtx_instance;

int main(int argc, char **argv)
{
    LazySingleton *p1 = LazySingleton::getInstance();
    LazySingleton *p2 = LazySingleton::getInstance();
    LazySingleton *p3 = LazySingleton::getInstance();

    return 0;
}