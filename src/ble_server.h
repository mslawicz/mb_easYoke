#include "ble/BLE.h"
#include <events/mbed_events.h>

class BleServer
{
public:
    BleServer(BLE& ble, events::EventQueue& eventQueue);
private:
    void onInitComplete(BLE::InitializationCompleteCallbackContext *params);
    BLE& _ble;
    events::EventQueue& _eventQueue;
};