/*
 *  @Filename : Adapter.cc
 *  @Description :
 *  @Datatime : 2023/01/15 11:05:51
 *  @Author : xushun
 */

#include <iostream>

// VGA接口
class VGA
{
public:
    virtual void play() = 0;
};
// 使用VGA接口输入的TV
class TV01 : public VGA
{
public:
    void play() { std::cout << "通过VGA接口连接播放" << std::endl; }
};

// HDMI接口
class HDMI
{
public:
    virtual void play() = 0;
};
// 使用HDMI接口输入的TV
class TV02 : public HDMI
{
public:
    void play() { std::cout << "通过HDMI接口播放" << std::endl; }
};

// VGA到HDMI接口的适配器
class VGA2HDMIAdapter : public VGA // 从外部看是一个VGA接口
{
public:
    VGA2HDMIAdapter(HDMI *p) : pHDMI(p) {}
    void play() { pHDMI->play(); } // 接口转换
private:
    HDMI *pHDMI; // 内部实际上是HDMI接口在工作
};

// 只支持VGA接口输出的电脑
class VGAComputer
{
public:
    void playVideo(VGA *pVGA) { pVGA->play(); }
};

int main(int argc, char **argv)
{
    // VGA接口的TV和VGA接口的电脑直接连接
    TV01 *tv1 = new TV01();
    VGAComputer *p1 = new VGAComputer();
    p1->playVideo(tv1);

    TV02 *tv2 = new TV02();
    // p1->playVideo(tv2); 接口不兼容
    // 使用适配器将VGA转为HDMI
    p1->playVideo(new VGA2HDMIAdapter(tv2));
    return 0;
}