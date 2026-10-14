#include "stm32f10x.h"      // STM32F10x 标准外设库头文件
#include "Delay.h"          // 延时函数头文件
#include "OLED.h"           // OLED 相关函数声明

uint8_t i = 0; // PWM 占空比变量

int main(void)
{
    OLED_Init();  //OLED初始化
    PWM_Init();   //PWM初始化


    while(1)                
    {
        for(i = 0; i <= 100; i++) // 占空比从 0% 到 100%
        {
            PWM_SetCompare(i); // 设置占空比
            Delay_ms(50); // 延时 50 毫秒
        }
        for(i = 100; i > 0; i--) // 占空比从 100% 到 0%
        {
            PWM_SetCompare(i); // 设置占空比
            Delay_ms(50); // 延时 50 毫秒
        }
    }
}
