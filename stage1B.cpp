#include "mbed.h"
 
#define BLINKING_RATE     500ms
#define Threshold 0.5f

int main()
{
    int time = 0;
    int count = 0;
    int inside = 0;
    AnalogIn photo1(A0);
    AnalogIn photo2(A1);
    AnalogIn photo3(A2);
    AnalogIn photo4(A3);
    AnalogIn photo5(A4);
    PwmOut motorv1gndleft(D12);
    PwmOut motorv2gndright(PA_11_ALT0);
    PwmOut motorv1left(D11);
    PwmOut motorv2right(PA_8);
    //PwmOut motorv1left(D12);
    //PwmOut motorv2right(PA_8);
    motorv1left.period(0.001f);
    motorv2right.period(0.001f);

    motorv1gndleft.period(0.001f);
    motorv1gndleft = 0.0;

    float straight = 0.6f;
    float slow = 0.4f;
    float sharp = 0.5f;
    while (true) {
        time = time + 1;
        if(time > 1500){
            time = 0;
            count = 0;
        }
        if ((photo1.read() < Threshold)&(photo2.read() < Threshold)&(photo3.read() < Threshold)&(photo4.read() < Threshold)&(photo5.read() < Threshold)){
            
            if (count == 0){
                count = count +1;
            }
            else if(count ==1&inside ==0){
                break;
            }
 
            inside = 1;
        }
        else {inside = 0;}
                
        
        if ((photo5.read() < Threshold)&(photo3.read() > Threshold)){
            do{
            motorv1left = 0.0f;
            motorv2right = sharp;
            //sharp_left();
            }
            while ((photo3.read() > Threshold)&(photo2.read() > Threshold)|(photo1.read() > Threshold)&(photo2.read() > Threshold)&(photo3.read() > Threshold)&(photo4.read() > Threshold)&(photo5.read() > Threshold));
            continue;
        }
        else if ((photo1.read() < Threshold)&(photo3.read() > Threshold)){
            do{
            motorv1left = sharp;
            motorv2right = 0.0f;
            //sharp_right();
            }
            while ((photo3.read() > Threshold)&(photo4.read() > Threshold)|(photo1.read() > Threshold)&(photo2.read() > Threshold)&(photo3.read() > Threshold)&(photo4.read() > Threshold)&(photo5.read() > Threshold));
            continue;
        }
        else if ((photo4.read() < Threshold)&(photo3.read() > Threshold)){
            do{
            motorv1left = 0.0f;
            motorv2right = slow;
            //left();
            }
            while ((photo3.read() > Threshold)|(photo1.read() > Threshold)&(photo2.read() > Threshold)&(photo3.read() > Threshold)&(photo4.read() > Threshold)&(photo5.read() > Threshold)/*&(photo2.read() > Threshold)*/);
            continue;
        }
        else if ((photo2.read() < Threshold)&(photo3.read() > Threshold)){
            do{
            motorv1left = slow;
            motorv2right = 0.0f;
            //right();
            }
            while ((photo3.read() > Threshold)|(photo1.read() > Threshold)&(photo2.read() > Threshold)&(photo3.read() > Threshold)&(photo4.read() > Threshold)&(photo5.read() > Threshold)/*&(photo4.read() > Threshold)*/);
            continue;
            
        } 
        else {
        motorv1left = straight;
        motorv2right = straight;
        //forward();
        }
    }
}