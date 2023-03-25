#include "ble_server.h"
#include "logger.h"

constexpr uint8_t EventQueueLength = 16;
events::EventQueue bleEventQueue(/* event count */ EventQueueLength * EVENTS_EVENT_SIZE);

/* Schedule processing of events from the BLE middleware in the event queue. */
void schedule_ble_events(BLE::OnEventsToProcessCallbackContext *context)
{
    bleEventQueue.call(Callback<void()>(&context->ble, &BLE::processEvents));
}

BleServer::BleServer(BLE& ble, events::EventQueue& eventQueue) :
    _ble(ble),
    _eventQueue(eventQueue)
{
    _ble.init(this, &BleServer::onInitComplete);
}

//Callback triggered when the ble initialization process has finished 
void BleServer::onInitComplete(BLE::InitializationCompleteCallbackContext* /*params*/)
{
    LOG_INFO("ble init callback");
}