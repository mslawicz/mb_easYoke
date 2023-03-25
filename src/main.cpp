#include "ble_server.h"
#include "mbed.h"
#include <events/mbed_events.h>
#include <chrono>

int main()
{
    constexpr std::chrono::microseconds HeartbeatPeriod(500000);
    DigitalOut heartbeatLed(LED2);
    Timer heartbeatTimer;
    constexpr uint8_t EventQueueLength = 16;
    events::EventQueue eventQueue(/* event count */ EventQueueLength * EVENTS_EVENT_SIZE);
    BleServer bleServer(BLE::Instance(), eventQueue);

    heartbeatTimer.start();

    while (true)
    {
        if(heartbeatTimer.elapsed_time().count() > HeartbeatPeriod.count())
        {
            heartbeatLed.write(heartbeatLed.read() != 0 ? 0 : 1);
            heartbeatTimer.reset();
        }
    }
}

