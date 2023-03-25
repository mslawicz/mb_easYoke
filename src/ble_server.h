#include "ble/BLE.h"
#include <events/mbed_events.h>

extern events::EventQueue bleEventQueue;

extern void schedule_ble_events(BLE::OnEventsToProcessCallbackContext *context);

class BleServer : ble::Gap::EventHandler
{
public:
    BleServer(BLE& ble, events::EventQueue& eventQueue);
private:
    void onInitComplete(BLE::InitializationCompleteCallbackContext *params);
    BLE& _ble;
    events::EventQueue& _eventQueue;
};