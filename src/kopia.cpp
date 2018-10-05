
// #include "mbed.h"
// #include "ble/BLE.h"
// #include "ble/services/HealthThermometerService.h"

// DigitalOut led1(LED1, 0);
// DigitalOut led4(LED4, 1);
// DigitalOut led2(LED2, 0);
// uint16_t customServiceUUID = 0x181C;
// uint16_t writeCharUUID = 0x181C;
// AnalogIn input(A0);
// InterruptIn button1(p13);
// InterruptIn button2(p14);
// InterruptIn button3(p15);
// InterruptIn button4(p16);
// LowPowerTicker flipper;
// LowPowerTicker flipper2;
// Serial pc(USBTX, USBRX);

// uint16_t value_ADC = 0;
// uint16_t sended = 0;
// uint16_t measured_array[5000];
// uint8_t sended_switch = 0;
// uint16_t sended_loop = 0;
// uint16_t sended_loop_real_measure=0;
// int measure_loop = 0;
// uint16_t realSensor_array[50];
// float timedData_array[50];
// int timedLoop =0;
// int realSensorLoop=0;
// int k=0;
// Timer t;


// static HealthThermometerService *thermometerServicePtr;

// static volatile bool triggerSensorPolling = false;

// const static char DEVICE_NAME[] = "Cats"; // change this
// static const uint16_t uuid16_list[] = {GattService::UUID_HEALTH_THERMOMETER_SERVICE};

// static uint8_t writeValue[10] = {0};
// WriteOnlyArrayGattCharacteristic<uint8_t, sizeof(writeValue)> writeChar(writeCharUUID, writeValue);

// // /* Set up custom service */
// // GattCharacteristic *characteristics[] = {&writeChar};
// // GattService customService(0x111E, characteristics, sizeof(characteristics) / sizeof(GattCharacteristic *));

// void periodicCallback(void)
// {
//        triggerSensorPolling = true;
// }

// void disconnectionCallback(const Gap::DisconnectionCallbackParams_t *)
// {
//     BLE::Instance(BLE::DEFAULT_INSTANCE).gap().startAdvertising();
// }

// void blik()
// {
//     led1 = !led1;
// }

// void blik2()
// {
//     led2 = !led2;
// }

// int ADC()
// {
    
//     value_ADC = input.read_u16();
//     wait_ms(10);
//     return value_ADC;
// }

// void measure()
// {
//     if (measure_loop < ((int)(sizeof(measured_array) / sizeof(measured_array[0]))))
//     {
//         timedData_array[timedLoop]=t.read_ms();
//         pc.printf("ADC - %f\n", timedData_array[timedLoop]);
//         timedLoop++;
//         blik();
//         for (measure_loop = k; measure_loop < (300 + k); measure_loop++)
//         {
//             measured_array[measure_loop] = ADC();
//         }
//         blik();
//         k += 300;
//     }
//     else
//     {
//     pc.printf("Nedostatok miesta");
//     }
// }

// void measureRealSensor()
// {
//     realSensor_array[realSensorLoop]=t.read_ms();
//     realSensorLoop++;
//     timedData_array[timedLoop]=t.read_ms();
//     pc.printf("real - %f\n***********************\n", timedData_array[timedLoop]);
//     timedLoop++;
// }

// void clearfun()
// {
//     int clear_loop=0;
//     for (clear_loop=0;clear_loop<=measure_loop;clear_loop++)
//         {
//             measured_array[clear_loop]=0;
//         }
//         k = 0;
//         measure_loop = 0;
// }


// void vypis()
// {   
//     int loop_sended = 0;
//     for (loop_sended = 0; measured_array[loop_sended] > 0; loop_sended++)
//     {
//         pc.printf("%d ----- %d\n", loop_sended, measured_array[loop_sended]);
//     }
// }

// void triger_send(int triger_in)
// {
//     sended_switch = triger_in;
// }

// void triger_send2()
// {
//     sended_switch = 1;
// }

// void writeCharCallback(const GattWriteCallbackParams *params)
// {

//     if (params->data[0] <= 0)
//         {
//         blik();
//         }
//     if ((params->data[0]) == 1)
//         measure();
//     if ((params->data[0]) == 2)
//         {
//         triger_send(1);
//         }
//     if ((params->data[0]) == 3)
//         {
//         triger_send(2);
//         }
// }

// void bleInitComplete(BLE::InitializationCompleteCallbackContext *params)
// {
//     BLE &ble = params->ble;
//     ble_error_t error = params->error;

//     if (error != BLE_ERROR_NONE)
//     {
//         return;
//     }

//     ble.gap().onDisconnection(disconnectionCallback);
//     ble.gattServer().onDataWritten(writeCharCallback);
//     thermometerServicePtr = new HealthThermometerService(ble, value_ADC, 5);
//     /* Setup advertising */
//     ble.gap().accumulateAdvertisingPayload(GapAdvertisingData::BREDR_NOT_SUPPORTED | GapAdvertisingData::LE_GENERAL_DISCOVERABLE);            // BLE only, no classic BT
//     ble.gap().setAdvertisingType(GapAdvertisingParams::ADV_CONNECTABLE_UNDIRECTED);                                                           // advertising type
//     ble.gap().accumulateAdvertisingPayload(GapAdvertisingData::COMPLETE_LOCAL_NAME, (uint8_t *)DEVICE_NAME, sizeof(DEVICE_NAME));             // add name
//     ble.gap().accumulateAdvertisingPayload(GapAdvertisingData::COMPLETE_LIST_16BIT_SERVICE_IDS, (uint8_t *)uuid16_list, sizeof(uuid16_list)); // UUID's broadcast in advertising packet
//     ble.gap().setAdvertisingInterval(100);                                                                                                    // 100ms.

//     /* Add our custom service */
//  //   ble.addService(customService);

//     /* Start advertising */
//     ble.gap().startAdvertising();
// }

// /*
//  *  Main loop
// */
// int main(void)
// {
//     /* initialize stuff */
//     printf("\n\r********* Starting Main Loop *********\n\r");
//     Ticker ticker;
//     ticker.attach(periodicCallback, 0.05);
//     t.start();
//     button1.rise(&blik);
//     button2.rise(&measure);
//     button3.rise(&vypis);
//     BLE &ble = BLE::Instance(BLE::DEFAULT_INSTANCE);
//     ble.init(bleInitComplete);
//     //flipper.attach(&measure, 10);
//     //flipper2.attach(&measureRealSensor, 10);
//    // flipper2.attach(&triger_send2, 10);

//     /* SpinWait for initialization to complete. This is necessary because the
//      * BLE object is used in the main loop below. */
//     while (ble.hasInitialized() == false)
//     { /* spin loop */
//     }

//     /* Infinite loop waiting for BLE interrupt events */
//     while (true)
//     {
//         if (triggerSensorPolling && ble.gap().getState().connected)
//         {
//             triggerSensorPolling = false;
//             if (sended_switch == 1)
//             {
//                thermometerServicePtr->updateTemperature(measured_array[sended_loop]);
               
//                 sended_loop += 1;
//                 pc.printf("%d\n", sended_loop);
//                  if (sended_loop >= measure_loop)
//                  {
//                     sended_switch = 0;
//                     sended_loop = 0;
//                     clearfun();
//                     pc.printf("%d.....................................\n", sended_loop);
//                  }
//             }
//             if (sended_switch == 2)
//             {
//                thermometerServicePtr->updateTemperature(realSensor_array[sended_loop_real_measure]);
               
//                 sended_loop_real_measure += 1;
//                  if (sended_loop_real_measure >= realSensorLoop)
//                  {
//                     sended_switch = 0;
//                     sended_loop_real_measure = 0;
                    
//                  }
//             }
//         }
//         else
//         {
//             ble.waitForEvent(); /* Save power */
//         }
//     }
// }