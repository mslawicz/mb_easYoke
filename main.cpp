#include "mbed.h"

DigitalOut systemLed(LED2);
// main() runs in its own thread in the OS
int main()
{
    while (true)
    {
        systemLed.write(1);
        ThisThread::sleep_for(500);
        systemLed.write(0);
        ThisThread::sleep_for(500);
    }
}

