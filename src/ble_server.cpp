#include "ble_server.h"

BleServer::BleServer(BLE& ble, events::EventQueue& eventQueue) :
    _ble(ble),
    _eventQueue(eventQueue)
{
    _ble.init(this, &BleServer::onInitComplete);
}

//Callback triggered when the ble initialization process has finished 
void BleServer::onInitComplete(BLE::InitializationCompleteCallbackContext *params)
{

}