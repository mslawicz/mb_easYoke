#include "ble_server.h"
#include "mbed.h"
#include <chrono>

// main() runs in its own thread in the OS
int main()
{
    constexpr std::chrono::microseconds HeartbeatPeriod(500000);
    DigitalOut heartbeatLed(LED2);
    Timer heartbeatTimer;

    heartbeatTimer.start();

    while (true)
    {
        if(heartbeatTimer.elapsed_time().count() > HeartbeatPeriod.count())
        {
            heartbeatLed.write(1 - heartbeatLed.read());
            heartbeatTimer.reset();
        }
    }
}

