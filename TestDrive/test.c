#include "asuro.h"


#define    XGN        RED
#define    XRD        GREEN

int test05(void)
{
    int n, s, light;
    
    char key;
    
    Init();

    StatusLED(XGN);
    
    FrontLED(ON);
    BackLED(ON, ON);

        
    //SerWrite("Begin...", 8);
    //SerWrite("Waiting for command... ", 23);

    SerRead(key, 1, 0);
    
    if (key == 'g')
    {
        SerWrite("Good Morning... Starting...", 27);
    }
    else
    {
        SerWrite("So... just start... ", 20);
    }
    
    while(1)
    {
        for (s=80; s<300; s+=10)
        {    
            SerWrite("Looping... ", 11);
            
            MotorDir(FWD, RWD);
            MotorSpeed(150,s);
        
            SerWrite("Sleep Now! ", 11);
            for (n=1; n< 100; n++)  Sleep(255);
        
            if (s > 200)
            {
                SerWrite("S>200 ", 6);
            
                s=80;
            }
                
        }
    }
    return 0;
}



int test04(void)
{
    int n;
    
    Init();

        StatusLED(XRD);

        FrontLED(ON);

        BackLED(ON, ON);

        MotorDir(FREE, FREE);
        MotorSpeed(150, 150);
        
        for (n=1; n<200; n++) Sleep(255);
        
        StatusLED(XGN);
        FrontLED(OFF);
        BackLED(OFF, OFF);
        for (n=1; n<50; n++) Sleep(255);

        while(1)
        {
         StatusLED(XGN);
         BackLED(OFF, OFF);
         FrontLED(ON);
         MotorDir(FWD, FWD);
         for (n=1; n<500; n++) Sleep(255);
         
         StatusLED(XRD);
         BackLED(OFF, OFF);
         FrontLED(OFF);
         MotorDir(BREAK, BREAK);
         for (n=1; n<100; n++) Sleep(255);
         
         StatusLED(XGN);
         BackLED(ON, ON);
         FrontLED(OFF);
         MotorDir(RWD, RWD);
         for (n=1; n<500; n++) Sleep(255);
         
         StatusLED(XRD);
         BackLED(OFF, OFF);
         FrontLED(OFF);
         MotorDir(BREAK, BREAK);
         for (n=1; n<100; n++) Sleep(255);
        }
        
    return 0;
}



int test03(void)
{
    int n;
    
    Init();

        StatusLED(XGN);

        FrontLED(ON);

        BackLED(ON, ON);

        MotorDir(BREAK, FREE);

        MotorSpeed(150,80);

        while(1)
        {
         BackLED(OFF, OFF);
         
         StatusLED(XGN);
         for (n=1; n<100; n++) Sleep(255);
         
         StatusLED(XRD);
         for (n=1; n<100; n++) Sleep(255);
        }
    return 0;
}


int test02(void)
{
    Init();

    StatusLED(XGN);

    FrontLED(ON);
    BackLED(ON, ON);

    MotorDir(FWD, RWD);
    MotorSpeed(150,80);

    while(1);
    return 0;
}


int test01(void)
{
    Init();

    StatusLED(XGN);
    
    FrontLED(ON);
    BackLED(ON, ON);

    MotorDir(BREAK, FREE);
    MotorSpeed(150,80);

    while(1);
    return 0;
}





int main(void)
{
    test05();
    
    return 0;
}
