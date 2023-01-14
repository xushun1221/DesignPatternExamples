/*
 *  @Filename : Proxy.cc
 *  @Description :
 *  @Datatime : 2023/01/14 17:30:11
 *  @Author : xushun
 */

#include <iostream>
#include <memory>

// 抽象类
class VideoSite
{
public:
    virtual void freeMovie() = 0;   // 观看免费电影
    virtual void vipMovie() = 0;    // 观看vip电影
    virtual void ticketMovie() = 0; // 观看需要观影券的电影
};

// 委托类 实现功能
class FixBugVideoSite
{
public:
    virtual void freeMovie() { std::cout << "观看免费电影" << std::endl; }
    virtual void vipMovie() { std::cout << "观看vip电影" << std::endl; }
    virtual void ticketMovie() { std::cout << "观看需要观影券的电影" << std::endl; }
};

// 代理类 游客通过该类访问freeMovie()功能
class FreeVideoSiteProxy : public VideoSite
{
public:
    virtual void freeMovie() { pVideo.freeMovie(); } // 只能看免费电影
    virtual void vipMovie() { std::cout << "您不是vip用户 无法观看vip电影" << std::endl; }
    virtual void ticketMovie() { std::cout << "您没有观影券 无法观看该电影" << std::endl; }

private:
    // 组合委托类 通过委托类访问观影的功能函数
    FixBugVideoSite pVideo;
};

// 代理类 vip通过该类访问freeMovie()和vipMovie()功能
class VipVideoSiteProxy : public VideoSite
{
public:
    virtual void freeMovie() { pVideo.freeMovie(); }
    virtual void vipMovie() { pVideo.vipMovie(); }
    virtual void ticketMovie() { std::cout << "您没有观影券 无法观看该电影" << std::endl; }

private:
    FixBugVideoSite pVideo;
};

int main(int argc, char **argv)
{
    // 游客和vip用户使用不同的代理类来访问观影功能
    std::unique_ptr<VideoSite> p1(new FreeVideoSiteProxy()); // 游客代理
    std::unique_ptr<VideoSite> p2(new VipVideoSiteProxy());  // vip代理

    p1->freeMovie();
    p1->vipMovie();
    p1->ticketMovie();
    
    p2->freeMovie();
    p2->vipMovie();
    p2->ticketMovie();
}