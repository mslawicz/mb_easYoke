#include "ble_server.h"
#include "logger.h"
#include "mbed.h"
#include <chrono>
#include <events/mbed_events.h>

int main()
{
    LOG_ALWAYS("easYoke start");

    constexpr std::chrono::microseconds HeartbeatPeriod(500000);
    DigitalOut heartbeatLed(LED2);
    Timer heartbeatTimer;

    BLE& ble = BLE::Instance();

    ble.onEventsToProcess(schedule_ble_events);
    BleServer bleServer(ble, bleEventQueue);

    heartbeatTimer.start();

    while (true)
    {
        if(heartbeatTimer.elapsed_time().count() > HeartbeatPeriod.count())
        {
            heartbeatLed.write(heartbeatLed.read() != 0 ? 0 : 1);
            heartbeatTimer.reset();
        }

        bleEventQueue.dispatch_once();
        ThisThread::sleep_for(1);
    }
}

