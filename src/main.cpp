

// #include "mbed.h"
 
// DigitalOut myled(LED1);
// DigitalOut led2(LED2);
 
// int main() {
//     while(1) {
//         led2 =!led2;
//         myled=!myled;
//         wait(2);
        
//     }
// }


/*
#include "mbed.h"
 
PwmOut led(LED1);
 
int main() {
    // specify period first, then everything else
    led.period(4);  // 4 second period
    led.pulsewidth(0.1f); // 2 second pulse (on)
    while(1);          // led flashing
}

*/


  //............................................................Hello world v lupe
// #include "mbed.h"
 
// Serial pc(USBTX, USBRX); // tx, rx
// DigitalOut myled(LED1);
// int i=0;
 
// int main() {
//     pc.printf("Hello World!\n");
//     while(1) {
//         pc.printf("%d\n",i);
//         i++;
//         wait(1);
//         myled=!myled;
//     }
// }



// #include "mbed.h"

// Serial device(p6, p8);  // tx, rx

// int main() {
//     device.baud(9600);
//     while(1)
//     {
//         device.printf("Hello World\n");
//         wait(1);
//     }
// }





 // ...........................................................prerusenie, blikanie led a vypis na konzolu

// #include "mbed.h"

// #define Enable 1
// #define Disable 0

// InterruptIn button1(p13);
// InterruptIn button2(p14);
// InterruptIn button3(p15);

// DigitalOut led(LED1);
// DigitalOut flash(LED2);

// Serial pc(USBTX, USBRX);

// static int i;
// int j;

// void flip() {
//     led = !led;
//     i++;
//     pc.printf("Teraz Button 1 ------- %d\n",i);
    
// }
// void test() {
//     wait(1);
//     pc.printf("eraz Button 2 ---%d\n",i);

// }
// void test2() {
//     wait(1);
//     led=!led;

// }

// int main() {
//     button1.rise(&flip);  // attach the address of the flip function to the rising edge
//     button2.rise(&test);
//     button3.rise(&test2);

//     while(1) {           // wait around, interrupts will interrupt this!
       
//         wait(1);
//         pc.printf("mainloop ------- %d\n",i);
//         i++;
//         }
//     }

//...................................................interupt skuska/........................................

// #include "mbed.h"
// InterruptIn event(p13);
// DigitalOut myled(LED1);
// Serial pc(USBTX, USBRX);
 
// int go_to_sleep = 0;
 
// void pressed()
// {   
//     //pc.printf("Button pressed\n");
//     go_to_sleep = go_to_sleep + 1;
//     if (go_to_sleep > 3) go_to_sleep = 0;
 
// }
 
// int main()
// {
//     int i = 0;
 
//     pc.printf("\nPress Button to enter/exit sleep & deepsleep\n");
 
//     event.fall(&pressed);
 
//     while (1) {
 
//         if ((go_to_sleep == 0) || (go_to_sleep == 2)) {
//             pc.printf("%d: Running\n", i);
//             myled = 1;
//             wait(1.0);
//         }
 
//         if (go_to_sleep == 1) {
//             myled = 0;
//             pc.printf("%d: Entering sleep (press user button to resume)\n", i);
//             wait(0.1); // To let the printf finish
//             sleep();
//         }
 
//         if (go_to_sleep == 3) {
//             myled = 0;
//             pc.printf("%d: Entering deepsleep (press user button to resume)\n", i);
//             wait(0.1); // To let the printf finish
//             deepsleep();
//         }
 
//         i++;
//     }
// }




/*  // ........................................................ADC na vstupe A0...........................................
#include "mbed.h"

Serial pc(USBTX, USBRX); // tx, rx
AnalogIn input(A0);
float result=0;
int main() {
    
    while(1)
    {
    result=(float)input.read_u16()/1000;
    pc.printf("%.6f V \n",result);
    wait(5);
    }
}

*/


/*  //.....................................................Time............................................
#include "mbed.h"

int main() {
    set_time(1256729737);  // Set RTC time to Wed, 28 Oct 2009 11:35:37

    while (true) {
        time_t seconds = time(NULL);
        
        printf("Time as seconds since January 1, 1970 = %d\n", seconds);
        
        printf("Time as a basic string = %s", ctime(&seconds));

        char buffer[32];
        strftime(buffer, 32, "%I:%M %p\n", localtime(&seconds));
        printf("Time as a custom formatted string = %s", buffer);
        
        wait(10);
    }
}

*/


  // .............................................Casovas s interuptom .......................................

// #include "mbed.h"
// int i=0;

// InterruptIn button1(p13);
// Serial pc(USBTX, USBRX); 
// Timer t;
// void click() {
//     t.stop();
//     pc.printf("The time taken was %f seconds\n", t.read());
//     t.reset();
//     t.start();
// }

// int main() {

// t.start();
// button1.rise(&click);


// while(1)
//     {
    
//     pc.printf("ks\n");
//     wait(1);
    
//     }
// }






 //.....................................................................meranie tepu...............................................

// #include "mbed.h"


// AnalogIn input(A0);
// InterruptIn button1(p13);
// DigitalOut led1(LED1);
// DigitalOut led2(LED2);
// DigitalOut led3(LED3);

// float result=0;
// int i=0;
// Timer t;
// int k;
// int m;


// void click() {
//     t.stop();
//     printf("The time taken was %f seconds\n", t.read());
//     t.start();
//     //return t.read();
// }

// void blic(int k)
// {
//     if (k==1)
//     led1 = !led1;
//     if (k==2)
//     led2=!led2;
//     if(k==3)
//     led3=!led3;
       
//     }

// void ADC()
// {
//     blic(k);
//     while(m<100)
//     {
//     m++;
//     result=(float)input.read_u16()/1000;
//     printf("k-%dIn time %f is voltage  %.4f\n",k,t.read(),result);
//     wait(0.0);
//     }
//     blic(k);
//     printf("test\n");
// }

// int main() {
// t.start();

// button1.rise(&ADC);
//     while(1)
//     {
//         ADC();
//         m=0;
//         k++;
//         if(k>3)
//             k=1;
//     }
// }








  //........................................................program na test interuptu pre ukoncenie inej funkcie

// #include "mbed.h"

// int i=0;
// Serial pc(USBTX, USBRX);
// InterruptIn button1(p13);
// InterruptIn button2(p14);

// Timer t;
// void click() {
//     t.stop();
//     pc.printf("The time taken was %f seconds\n", t.read());
//     t.reset();
//     t.start();
// }

// void p1x4()
// {
//     i=1;
//     pc.printf("break");
    
    
// }

// void looa(){
//     while(1){
//         if (i>0)
//         break;
//         pc.printf("....\n");
//         wait(0.5);
//             }
// }

// int main() {
// t.start();
// button1.rise(&click);
// button2.rise(&p1x4);
//     while(1)
//     {
//     pc.printf("start\n");
//     looa();
//     i=0;
//     pc.printf("stop");
//     wait(0.5);
//     }
// }



//...............................................................................BLE...............................................................................

// #include "mbed.h"
// #include "ble/BLE.h"
// #include "ble/services/HeartRateService.h"
// #include "ble/services/BatteryService.h"
// #include "ble/services/DeviceInformationService.h"
// #include "ble/services/BatteryService.h"
// #include "ble/services/EnvironmentalService.h"


// AnalogIn input(A0);
// InterruptIn button1(p13);
// InterruptIn button2(p14);
// InterruptIn button3(p15);
// InterruptIn button4(p16);
// DigitalOut led1(LED1);
// DigitalOut led4(LED4);

// int i=0;
// Timer t;

// int m;


 
// const static char     DEVICE_NAME[]        = "SKUSKA";
// static const uint16_t uuid16_list[]        = {GattService::UUID_HEART_RATE_SERVICE,
//                                               GattService::UUID_DEVICE_INFORMATION_SERVICE};
// static volatile bool  triggerSensorPolling = false;

// Serial pc(USBTX, USBRX);

// uint8_t hrmCounter = 100; // init HRM to 100bps
// uint16_t testik =0;
// uint16_t sended=150;

// uint16_t testik_array[1000];
// int ii=0;


// HeartRateService         *hrService;
// DeviceInformationService *deviceInfo;
// BatteryService           *bateryy;


 
// void disconnectionCallback(const Gap::DisconnectionCallbackParams_t *params)
// {
//     BLE::Instance(BLE::DEFAULT_INSTANCE).gap().startAdvertising(); // restart advertising
// }


// void periodicCallback(void)
// {
//     led4 = !led4; /* Do blinky on LED1 while we're waiting for BLE events */
 
//     /* Note that the periodicCallback() executes in interrupt context, so it is safer to do
//      * heavy-weight sensor polling from the main thread. */
//     triggerSensorPolling = true;
// }
 
// void bleInitComplete(BLE::InitializationCompleteCallbackContext *params)
// {
//     BLE &ble          = params->ble;
//     ble_error_t error = params->error;
 
//     if (error != BLE_ERROR_NONE) {
//         return;
//     }
 
//     ble.gap().onDisconnection(disconnectionCallback);
 
//     /* Setup primary service. */
//    // hrService = new HeartRateService(ble, hrmCounter, HeartRateService::LOCATION_FINGER);
 
//     /* Setup auxiliary service. */
//    // deviceInfo = new DeviceInformationService(ble, "123", "Model1", "SN1", "hw-rev1", "fw-rev1", "soft-rev1");

//     bateryy = new BatteryService(ble,0);


//     //enviroment = new EnvironmentalService( ble,10);
    
//     /* Setup advertising. */
//     ble.gap().accumulateAdvertisingPayload(GapAdvertisingData::BREDR_NOT_SUPPORTED | GapAdvertisingData::LE_GENERAL_DISCOVERABLE);
//     ble.gap().accumulateAdvertisingPayload(GapAdvertisingData::COMPLETE_LIST_16BIT_SERVICE_IDS, (uint8_t *)uuid16_list, sizeof(uuid16_list));
//     ble.gap().accumulateAdvertisingPayload(GapAdvertisingData::GENERIC_HEART_RATE_SENSOR);
//     ble.gap().accumulateAdvertisingPayload(GapAdvertisingData::COMPLETE_LOCAL_NAME, (uint8_t *)DEVICE_NAME, sizeof(DEVICE_NAME));
//     ble.gap().setAdvertisingType(GapAdvertisingParams::ADV_CONNECTABLE_UNDIRECTED);
//     ble.gap().setAdvertisingInterval(100); /* 1000ms */
//     ble.gap().startAdvertising();
// }

// void blik()
// { 
//     led1 = !led1;
//     ii++;
//     bateryy->updateBatteryLevel(ii);

// }


// void connection()
// {
    
//             // Do blocking calls or whatever is necessary for sensor polling.
//             // In our case, we simply update the HRM measurement.
//                 for (i = 0; i < 10; i++)
//                 {
//                 sended=testik_array[i];
//                 hrService->updateHeartRate(sended);
//                 wait(1);
//                 }
// }

// int ADC()
// {
//     blik();
//     testik=input.read_u16();
//     pc.printf("In time %f is voltage  %d\n",t.read(),testik);
//     wait(0.1);
//     blik();
//     wait(0.1);
//     return testik;
    
// }

// void measure()
// {
//     for (i = 0; i < 10; i++)
//     {
//         testik_array[i] = ADC();
//     }
// }

// void send()
// {

//     for (i = 0; i < 10; i++)
//     {
//         sended = testik_array[i];
//         connection();
//         wait(1);
//     }
// }

// void vypis()
// {
//      for(i=0;i<10;i++)
//      {
//       pc.printf("%d\n",testik_array[i]);
//      }
// }

// int main(void)
// {
//     led4 = 1;
//     Ticker ticker;
//     ticker.attach(periodicCallback,1); // blink LED every second
//     t.start();
//     button1.rise(&blik);
//     //button2.rise(&te);
//     button3.rise(&vypis);
//     button4.rise(&blik);
//     BLE& ble = BLE::Instance(BLE::DEFAULT_INSTANCE);
//     ble.init(bleInitComplete);
    
 
//     /* SpinWait for initialization to complete. This is necessary because the
//      * BLE object is used in the main loop below. */
//     while (ble.hasInitialized()  == false) { /* spin loop */ }
 
//     // infinite loop
//     while (1) {
//         // check for trigger from periodicCallback()
//         if (triggerSensorPolling && ble.getGapState().connected) {
//             triggerSensorPolling = false;

//             ble.gattClient().onDataRead();

//             // Do blocking calls or whatever is necessary for sensor polling.
//             // In our case, we simply update the HRM measurement.
            
//                 // if(i>10)
//                 // i=0;
//                 // sended=testik_array[i];
//                 // hrService->updateHeartRate(sended);
//                 // i++;
                
                            
//         }
//             else
//             {
//                 ble.waitForEvent(); // low power wait for event
//         }
// }
// }


// .......................................................................BatteryService..........................................................................

// #include "mbed.h"
// #include "BLE.h"
// #include "BatteryService.h"

// const static char     DEVICE_NAME[]        = "SKUSKA222";

// DigitalOut led1(LED1, 1);
// Ticker t;
// BatteryService *batteryService = NULL;
// uint8_t batteryLevel = 50;
 
// void disconnectionCallback(const Gap::DisconnectionCallbackParams_t *disconnectionParams)
// {
//     printf("Disconnected handle %u!\n\r", disconnectionParams->handle);
//     printf("Restarting the advertising process\n\r");
//     BLE::Instance(BLE::DEFAULT_INSTANCE).gap().startAdvertising(); // restart advertising
// }
 
// void blink(void)
// {
//     led1 = !led1;
// }
 
// void bleInitComplete(BLE::InitializationCompleteCallbackContext *params)
// {
//     BLE &ble          = params->ble;
//     ble_error_t error = params->error;
//     Gap& gap = ble.gap();
 
//     if (error != BLE_ERROR_NONE) {
//         return;
//     }
 
//     gap.onDisconnection(disconnectionCallback);
 
//     batteryService = new BatteryService(ble, batteryLevel);
 
//     /* setup advertising */
//     gap.accumulateAdvertisingPayload(GapAdvertisingData::BREDR_NOT_SUPPORTED | GapAdvertisingData::LE_GENERAL_DISCOVERABLE);
//     gap.setAdvertisingType(GapAdvertisingParams::ADV_CONNECTABLE_UNDIRECTED);
//     gap.setAdvertisingInterval(1000); /* 1000ms; in multiples of 0.625ms. */
//     gap.startAdvertising();
// }
 
// int main(void)
// {
//     t.attach(blink, 1.0f);
 
//     printf("Initialising the nRF51822\n\r");
 
//     BLE& ble = BLE::Instance(BLE::DEFAULT_INSTANCE);
//     ble.init(bleInitComplete);
 
//     /* SpinWait for initialization to complete. This is necessary because the
//      * BLE object is used in the main loop below. */
//     while (ble.hasInitialized()  == false) { /* spin loop */ }
 
//     while (true) {
//         ble.waitForEvent(); // this will return upon any system event (such as an interrupt or a ticker wakeup)
 
//         // the magic battery processing
//         batteryLevel++;
//         if (batteryLevel > 100) {
//             batteryLevel = 20;
//         }
 
//         batteryService->updateBatteryLevel(batteryLevel);
//     }
// }







// ....................................................................skuska CATS.............................................................

// #include "mbed.h"
// #include "ble/BLE.h"
// #include "ble/services/HeartRateService.h"
// #include "ble/services/HealthThermometerService.h"
 
// DigitalOut led1(LED1, 1);
// DigitalOut led4(LED4, 1);
// uint16_t customServiceUUID  = 0x181C;
// uint16_t readCharUUID       = 0x2A9A;
// uint16_t writeCharUUID      = 0xA001;
// AnalogIn input(A0);
// InterruptIn button1(p13);
// InterruptIn button2(p14);
// InterruptIn button3(p15);
// InterruptIn button4(p16);
// Serial pc(USBTX, USBRX);
// uint16_t testik = 0;
// uint16_t sended = 150;
// uint16_t testik_array[1000];
// int ii = 0;;
// int i = 0;
// int m;
// Timer t;
// uint16_t hrmCounter=0;

 
// static HealthThermometerService *thermometerServicePtr;
 


// static float          currentTemperature   = 39.6;

// HeartRateService         *hrService;

// static volatile bool  triggerSensorPolling = false;
 
// const static char     DEVICE_NAME[]        = "Cats"; // change this
// static const uint16_t uuid16_list[]        = {0xFFFF}; //Custom UUID, FFFF is reserved for development
// static const uint16_t uuid16_list1[]        = {GattService::UUID_HEALTH_THERMOMETER_SERVICE};

 
// /* Set Up custom Characteristics */
// static uint8_t readValue[100] = {0};
// NotifyArrayGattCharacteristic<uint8_t, sizeof(readValue)> readChar(readCharUUID, readValue);

// static uint8_t writeValue[100] = {0};
// WriteOnlyArrayGattCharacteristic<uint8_t, sizeof(writeValue)> writeChar(writeCharUUID, writeValue);
 
// /* Set up custom service */
// GattCharacteristic *characteristics[] = {&readChar, &writeChar};
// GattService        customService(customServiceUUID, characteristics, sizeof(characteristics) / sizeof(GattCharacteristic *));



// void periodicCallback(void)
// {
//     led4 = !led4; /* Do blinky on LED1 while we're waiting for BLE events */
//     triggerSensorPolling = true;
// }

// void disconnectionCallback(const Gap::DisconnectionCallbackParams_t *)
// {
//     BLE::Instance(BLE::DEFAULT_INSTANCE).gap().startAdvertising();
// }

// //........................................................................................................
// void blik()
// { 
//     led1 = !led1;
    
// }

// int ADC()
// {
//     blik();
//     testik=(input.read_u16());
//     //printf("In time %f is voltage  %d\n",t.read(),testik);
//     wait(0.03);
//     blik();
//     wait(0.03);
//     return testik;
// }

// void measure()
// {
//     for (i = 0; i < 1000; i++)
//     {
//         testik_array[i] = ADC();
//     }
//     i=0;
// }

// // void connection()
// // {

// //     // Do blocking calls or whatever is necessary for sensor polling.
// //     // In our case, we simply update the HRM measurement.
// //     // for (i = 0; i < 100; i++)
// //     // {
// //        // sended = testik_array[i];
// //         hrService->updateHeartRate(sended);
// //        // wait(0.1);
// //     //}
// // }
// void send()
// {
//     for (i = 0; i < 100; i++)
//     {
//        // sended = testik_array[i];
//         hrService->updateHeartRate(i);
//         wait(0.1);
//         blik();
//     }
// }


// void vypis()
// {
//     for (i = 0; i < 1000; i++)
//     {
//         pc.printf("%d ----- %d\n", i, testik_array[i]);
//     }
// }
// //.......................................................................................................
// void writeCharCallback(const GattWriteCallbackParams *params)
// {
//     /* Check to see what characteristic was written, by handle */
//     //if(params->handle == writeChar.getValueHandle()) {
    
//         //     printf("Data received: length = %d, data = 0x",params->len);
//         //     for(int x=0; x < params->len; x++) {
//         //         printf("%x", params->data[x]);
//         //         blik();
//         //         wait(0.5);
//         //     }
//         //     printf("\n\r");
             
//         // printf("%f\n",t.read());
//         if(params->data[0]<=0)
//         blik();
//         if((params->data[0])==1)
//         measure();
//         if((params->data[0])==2)
//         send();

//     //}
//         /* Update the readChar with the value of writeChar */
//         BLE::Instance(BLE::DEFAULT_INSTANCE).gattServer().write(readChar.getValueHandle(), params->data, params->len);
//     }

// /*
//  * Initialization callback
//  */
// void bleInitComplete(BLE::InitializationCompleteCallbackContext *params)
// {
//     BLE &ble          = params->ble;
//     ble_error_t error = params->error;
    
//     if (error != BLE_ERROR_NONE) {
//         return;
//     }
//     hrService = new HeartRateService(ble, hrmCounter, HeartRateService::LOCATION_FINGER);
 
//     ble.gap().onDisconnection(disconnectionCallback);
//     ble.gattServer().onDataWritten(writeCharCallback);
//      thermometerServicePtr = new HealthThermometerService(ble, currentTemperature, HealthThermometerService::LOCATION_EAR);
 
    
//     /* Setup advertising */
//     ble.gap().accumulateAdvertisingPayload(GapAdvertisingData::BREDR_NOT_SUPPORTED | GapAdvertisingData::LE_GENERAL_DISCOVERABLE); // BLE only, no classic BT
//     ble.gap().setAdvertisingType(GapAdvertisingParams::ADV_CONNECTABLE_UNDIRECTED); // advertising type
//     ble.gap().accumulateAdvertisingPayload(GapAdvertisingData::COMPLETE_LOCAL_NAME, (uint8_t *)DEVICE_NAME, sizeof(DEVICE_NAME)); // add name
//     ble.gap().accumulateAdvertisingPayload(GapAdvertisingData::COMPLETE_LIST_16BIT_SERVICE_IDS, (uint8_t *)uuid16_list, sizeof(uuid16_list)); // UUID's broadcast in advertising packet
//     ble.gap().setAdvertisingInterval(100); // 100ms.
 
//     /* Add our custom service */
//     ble.addService(customService);
 
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
//     ticker.attach(periodicCallback,1); // blink LED every second
//     t.start();
//     button1.rise(&blik);
//     button2.rise(&measure);
//     button3.rise(&vypis);
//     BLE& ble = BLE::Instance(BLE::DEFAULT_INSTANCE);
//     ble.init(bleInitComplete);
    
//     /* SpinWait for initialization to complete. This is necessary because the
//      * BLE object is used in the main loop below. */
//     while (ble.hasInitialized()  == false) { /* spin loop */ }
 
//     /* Infinite loop waiting for BLE interrupt events */
//     while (true) {
//         if (triggerSensorPolling && ble.gap().getState().connected) {
//             i+=1;
//             triggerSensorPolling = false;
//             currentTemperature += 0.1;
//             thermometerServicePtr->updateTemperature(testik_array[i]);  
//         } else {
//         ble.waitForEvent(); /* Save power */
//     }
// }
// }    








// ...............................................................Meranie v loope.........................................................     

// #include "mbed.h"

// AnalogIn input(A0);
// InterruptIn button1(p13);
// DigitalOut led1(LED1);


// float result=0;
// int i=0;
// Timer t;
// int k;
// int m;
// int l=0;



// typedef struct {
//     int resulted;
//     float timed;
// }TYP;


// int main() {
    
//     t.start();
//     TYP sa[1000];

//     while(1)
//      {
//      led1 = 1;
//      result=input.read_u16();
//      sa[l].resulted=result;
//      sa[l].timed=t.read();
//      //printf("k-%dIn time %f is voltage  %.4f\n",k,t.read(),sa[l].resulted);
//      wait(0.01);
//      l++;
//      if (l>999)
//          {
//          printf("test\n");
//         for(i=0;i<999;i++)
//         {
//         printf("time= %.4f test is voltage %d  in time\n",sa[i].timed, sa[i].resulted);
//         }
//         l=0;
//         }
//      }
// }



//............................................................I2c.....................................................................


// #include "mbed.h"
 
// I2C i2c(p26, p27);        // sda, scl
// Serial pc(USBTX, USBRX); // tx, rx
 
// const int addr = 0x00; // define the correct I2C Address    
 
// int main() 
// {
//     char regaddr[1];
//     char readdata[8]; // room for length and 7 databytes
//     char writedata[9]; // room for reg address, length and 7 databytes
//     while (1) 
//     {
//         // read the data
//         regaddr[0] = 0xE0;
//         i2c.write(addr, regaddr, 1, true);  // select the register, no I2C Stop
//         i2c.read(addr, readdata, 8);        // read the length byte and the 7 databytes
        
//         wait (1);
 
//         // print the data to the screen
//         pc.printf("Register 0x%x = 0x%x 0x%x 0x%x 0x%x 0x%x 0x%x 0x%x\r\n",
//                   regaddr[0],
//                   readdata[1], readdata[2], readdata[3], readdata[4],
//                   readdata[5], readdata[6], readdata[7] );
//         wait(1);
 
//         // copy the data, starting with register address
//         writedata[0] = regaddr[0];  // register address
//         writedata[1] = readdata[0]; // length, should be 7
//         writedata[2] = readdata[1]; // byte 1
//         writedata[3] = readdata[2];
//         writedata[4] = readdata[3];
//         writedata[5] = readdata[4];
//         writedata[6] = readdata[5];
//         writedata[7] = readdata[6];
//         writedata[8] = readdata[7]; // byte 7
 
//         // write the data
//         i2c.write(addr, writedata, 9); // select the register, 
//                                        // write the length, write 7 databytes      
//         wait(1);
 
//     }
// }


//...................................................................Scanner I2C.................................................


// #include "mbed.h"
// #include <stdbool.h>

// #include "nrf_delay.h"
// #include "app_error.h"
// #include "app_util_platform.h"


// I2C i2c(p26,p27); 

// const int addr = 0x00;


// int main() {
//     char regaddr[1];
//     char readdata[8];
//     printf("\nI2C Scanner");
    
    
//     while(1) {

   
//         int error, address;
//         int nDevices;
      
//         printf("Scanning...\n");
        
//          nDevices = 0;
//          i2c.write(3);
//          address=103;
//             i2c.start();
//             error = i2c.write(address << 1); //We shift it left because mbed takes in 8 bit addreses
//             printf("%d .... 0x%X\n",i2c.read(address), address);
//              i2c.read(addr, readdata, 8);        // read the length byte and the 7 databytes
        
//         wait (1);
        
        
//         printf("Register 0x%x = 0x%x 0x%x 0x%x 0x%x 0x%x 0x%x 0x%x\r\n",
//                   regaddr[0],
//                   readdata[1], readdata[2], readdata[3], readdata[4],
//                   readdata[5], readdata[6], readdata[7] );
//         wait(1);
 
            
//             i2c.stop();
           

          
//           if (nDevices == 0)
//             printf("No I2C devices found\n");
//           else
//             printf("\ndone\n");
        
//            wait(0.5);           // wait 5 seconds for next scan
          
//              }
//        }





//..............................................................................BLE iBeacon........................................................................



// #include "mbed.h"
// #include "ble/BLE.h"
// #include "ble/services/iBeacon.h"
 
// //BLE ble;
    
// void bleInitComplete(BLE::InitializationCompleteCallbackContext *params)
// {
//     BLE &ble          = params->ble;
//     ble_error_t error = params->error;
 
//     if (error != BLE_ERROR_NONE) {
//         return;
//     }
    
//     /**
//      * The Beacon payload has the following composition:
//      * 128-Bit / 16byte UUID = E2 0A 39 F4 73 F5 4B C4 A1 2F 17 D1 AD 07 A9 61
//      * Major/Minor  = 0x1122 / 0x3344
//      * Tx Power     = 0xC8 = 200, 2's compliment is 256-200 = (-56dB)
//      *
//      * Note: please remember to calibrate your beacons TX Power for more accurate results.
//      */
//     const uint8_t uuid[] = {0xE2, 0x0A, 0x39, 0xF4, 0x73, 0xF5, 0x4B, 0xC4,
//                             0xA1, 0x2F, 0x17, 0xD1, 0xAD, 0x07, 0xA9, 0x61};
//     uint16_t majorNumber = 1122;
//     uint16_t minorNumber = 3344;
//     uint16_t txPower     = 0xC8;
//     iBeacon *ibeacon = new iBeacon(ble, uuid, majorNumber, minorNumber, txPower);
 
//     ble.gap().setAdvertisingInterval(100); /* 1000ms. */
//     ble.gap().startAdvertising();
// }
 
// int main(void)
// {
//     BLE& ble = BLE::Instance(BLE::DEFAULT_INSTANCE);
//     ble.init(bleInitComplete);
    
    
//     /* SpinWait for initialization to complete. This is necessary because the
//      * BLE object is used in the main loop below. */
//     while (!ble.hasInitialized()) { /* spin loop */ }
 
//     while (true) {
//         ble.waitForEvent(); // allows or low power operation
//     }
// }


//.....................................................................BLE thermo.......................................


// /* mbed Microcontroller Library
//  * Copyright (c) 2006-2013 ARM Limited
//  *
//  * Licensed under the Apache License, Version 2.0 (the "License");
//  * you may not use this file except in compliance with the License.
//  * You may obtain a copy of the License at
//  *
//  *     http://www.apache.org/licenses/LICENSE-2.0
//  *
//  * Unless required by applicable law or agreed to in writing, software
//  * distributed under the License is distributed on an "AS IS" BASIS,
//  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  * See the License for the specific language governing permissions and
//  * limitations under the License.
//  */
 
// #include "mbed.h"
// #include "ble/BLE.h"
// #include "ble/services/HealthThermometerService.h"
 
// DigitalOut led1(LED1);
 
// static HealthThermometerService *thermometerServicePtr;
 
// static const char     DEVICE_NAME[]        = "Therm";
// static const uint16_t uuid16_list[]        = {GattService::UUID_HEALTH_THERMOMETER_SERVICE};
// static volatile bool  triggerSensorPolling = false;
// static float          currentTemperature   = 39.6;
 
// /* Restart Advertising on disconnection*/
// void disconnectionCallback(const Gap::DisconnectionCallbackParams_t *params)
// {
//     BLE::Instance().gap().startAdvertising();
// }
 
// void periodicCallback(void)
// {
//     led1 = !led1; /* Do blinky on LED1 while we're waiting for BLE events */
 
//     /* Note that the periodicCallback() executes in interrupt context, so it is safer to do
//      * heavy-weight sensor polling from the main thread. */
//     triggerSensorPolling = true;
// }
 
// /**
//  * This function is called when the ble initialization process has failed
//  */
// void onBleInitError(BLE &ble, ble_error_t error)
// {
//     /* Avoid compiler warnings */
//     (void) ble;
//     (void) error;
//     /* Initialization error handling should go here */
// }
 
// /**
//  * Callback triggered when the ble initialization process has finished
//  */
// void bleInitComplete(BLE::InitializationCompleteCallbackContext *params)
// {
//     BLE&        ble   = params->ble;
//     ble_error_t error = params->error;
 
//     if (error != BLE_ERROR_NONE) {
//         /* In case of error, forward the error handling to onBleInitError */
//         onBleInitError(ble, error);
//         return;
//     }
 
//     /* Ensure that it is the default instance of BLE */
//     if(ble.getInstanceID() != BLE::DEFAULT_INSTANCE) {
//         return;
//     }
 
//     ble.gap().onDisconnection(disconnectionCallback);
 
//     /* Setup primary service. */
//     thermometerServicePtr = new HealthThermometerService(ble, currentTemperature, HealthThermometerService::LOCATION_EAR);
 
//     /* setup advertising */
//     ble.gap().accumulateAdvertisingPayload(GapAdvertisingData::BREDR_NOT_SUPPORTED | GapAdvertisingData::LE_GENERAL_DISCOVERABLE);
//     ble.gap().accumulateAdvertisingPayload(GapAdvertisingData::COMPLETE_LIST_16BIT_SERVICE_IDS, (uint8_t *)uuid16_list, sizeof(uuid16_list));
//     ble.gap().accumulateAdvertisingPayload(GapAdvertisingData::THERMOMETER_EAR);
//     ble.gap().accumulateAdvertisingPayload(GapAdvertisingData::COMPLETE_LOCAL_NAME, (uint8_t *)DEVICE_NAME, sizeof(DEVICE_NAME));
//     ble.gap().setAdvertisingType(GapAdvertisingParams::ADV_CONNECTABLE_UNDIRECTED);
//     ble.gap().setAdvertisingInterval(10); /* 1000ms */
//     ble.gap().startAdvertising();    
// }

//     void tes()
//     {
//         currentTemperature += 0.1;
//         thermometerServicePtr->updateTemperature(currentTemperature);  
//     }
 
// int main(void)
// {
//     led1 = 1;
//     Ticker ticker;
//     ticker.attach(periodicCallback, 0.05);
 
//     BLE &ble = BLE::Instance();
//     ble.init(bleInitComplete);
    
//     /* SpinWait for initialization to complete. This is necessary because the
//      * BLE object is used in the main loop below. */
//     while (ble.hasInitialized()  == false) { /* spin loop */ }
 
//     while (true) {
//         if (triggerSensorPolling && ble.gap().getState().connected) {
//             triggerSensorPolling = false;
 
//             /* In our case, we simply update the dummy temperature measurement. */
//             tes();
//         } else {
//             ble.waitForEvent();
//         }
//     }
// }



//...................................................................DRUHA SKUSKA CATS/..................................................................

// #include "mbed.h"
// #include "ble/BLE.h"
// #include "ble/services/HealthThermometerService.h"

// //inicialization of LEDs
// DigitalOut led1(LED1, 0);
// DigitalOut led4(LED4, 1);
// DigitalOut led2(LED2, 0);
// uint16_t customServiceUUID = 0x181C;
// uint16_t writeCharUUID = 0x181C;
// AnalogIn input(A0);
// //inicialization of buttons
// InterruptIn button1(p13);
// InterruptIn button2(p14);
// InterruptIn button3(p15);
// InterruptIn button4(p16);
// //inicialization of timers
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


// //function for setting
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
//     wait_ms(100);
//     return value_ADC;
// }
// //functions for check whether are first 10 value of array equal 0.
// //helped function for overflow of measure function.
// int checkloop()
// {
//     int help_value = 0;
//     int checkValue = 0;
//     int returnValue = 0;
//     blik2();
//     wait(0.5);
//     blik2();
//     for (help_value = 0; help_value <= 10; help_value++)
//     {
//         if (measured_array[help_value] == 0)
//         {
//             checkValue = 0;
//         }
//         else
//         {
//             checkValue = 1;
//         }
//         returnValue += checkValue;
//     }
//     if (returnValue > 0)
//     {
//         return 0;
//     }
//     else
//     {
//         return 1;
//     }
// }

// void measure()
// {
//     if (measure_loop < ((int)(sizeof(measured_array) / sizeof(measured_array[0]))))
//     {
//         timedData_array[timedLoop] = t.read_ms();
//         pc.printf("ADC - time je %f  \t a som na %d\n", timedData_array[timedLoop],measure_loop);
//         timedLoop++;
//         blik();
//         for (measure_loop = k; measure_loop < (100 + k); measure_loop++)
//         {
//             measured_array[measure_loop] = ADC();
//          //  measured_array[measure_loop] = measure_loop;
//         }
//         blik();
//         k += 100;
//     }
//     else
//     {
//         if (checkloop())
//         {
//             pc.printf("idem odznova\n");
//             measure_loop = 0;
//             k = 0;
//             measure();
//         }
//         else
//         {
//             pc.printf("nevynulovane");
//         }
//     }
// }


// // only prepare for future value and functions.
// void measureRealSensor()
// {
//     realSensor_array[realSensorLoop]=t.read_ms();
//     realSensorLoop++;
//     timedData_array[timedLoop]=t.read_ms();
//     pc.printf("real - %f\n***********************\n", timedData_array[timedLoop]);
//     timedLoop++;
// }

// void cleararray()
// {
//     int clear_loop=0;
//     blik2();
//     wait(0.5);
//     blik2();
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
//    // for (loop_sended = 0; measured_array[loop_sended] > 0; loop_sended++)
//    for (loop_sended = 0; 1000; loop_sended++)
   
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
//     ticker.attach(periodicCallback, 0.04);
//     t.start();
//     button1.rise(&blik);
//     button2.rise(&measure);
//     button3.rise(&vypis);
//     BLE &ble = BLE::Instance(BLE::DEFAULT_INSTANCE);
//     ble.init(bleInitComplete);
    
    
//     //flipper.attach(&measure, 10);
//     //flipper2.attach(&measureRealSensor, 10);
//     //flipper2.attach(&triger_send2, 10);

//     /* SpinWait for initialization to complete. This is necessary because the
//      * BLE object is used in the main loop below. */
//     while (ble.hasInitialized() == false)
//     { /* spin loop */
//     }

//     /* Infinite loop waiting for BLE interrupt events */
//     while (true)
//     {       
//          if (triggerSensorPolling && ble.gap().getState().connected)
//          {
//              triggerSensorPolling = false; 
//         //     if (sended_switch == 1)
//         //     {
//         //        thermometerServicePtr->updateTemperature(measured_array[sended_loop]);
//         //         measured_array[sended_loop]=0;
//         //         sended_loop += 1;
//         //          if (sended_loop >= measure_loop)
//         //          {
//         //             sended_switch = 0;
//         //             sended_loop = 0;
//         //             cleararray();
//         //          }
//         //     }
//         //     if (sended_switch == 2)
//         //     {
//         //        thermometerServicePtr->updateTemperature(realSensor_array[sended_loop_real_measure]);
               
//         //         sended_loop_real_measure += 1;
//         //          if (sended_loop_real_measure >= realSensorLoop)
//         //          {
//         //             sended_switch = 0;
//         //             sended_loop_real_measure = 0;
                    
//         //          }
//         //     }
//         }
//         else
//         {
//             pc.printf("som vo waite");
//             ble.waitForEvent(); /* Save power */
//         }
//     }
// }
















//...................................................................TRETIA SKUSKA CATS/..................................................................

// #include "mbed.h"
// #include "ble/BLE.h"
// #include "ble/services/HealthThermometerService.h"

// //inicialization of LEDs
// DigitalOut led1(LED1, 0);
// DigitalOut led4(LED4, 1);
// DigitalOut led2(LED2, 0);
// DigitalOut set_for_battery(P0_5,0);
// DigitalOut set_for_battery2(P0_7,0);
// uint16_t customServiceUUID = 0x181C;
// uint16_t writeCharUUID = 0x181C;
// AnalogIn input(A0);
// //inicialization of buttons
// InterruptIn button1(p13);
// InterruptIn button2(p14);
// InterruptIn button3(p15);
// InterruptIn button4(p16);
// //inicialization of timers
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
// float time_of_periodical_timer=10;
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


// //function for setting
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
//     wait_ms(100);
//     return value_ADC;
// }
// //functions for check whether are first 10 value of array equal 0.
// //helped function for overflow of measure function.
// int checkloop()
// {
//     int help_value = 0;
//     int checkValue = 0;
//     int returnValue = 0;
//     blik2();
//     wait(0.5);
//     blik2();
//     for (help_value = 0; help_value <= 10; help_value++)
//     {
//         if (measured_array[help_value] == 0)
//         {
//             checkValue = 0;
//         }
//         else
//         {
//             checkValue = 1;
//         }
//         returnValue += checkValue;
//     }
//     if (returnValue > 0)
//     {
//         return 0;
//     }
//     else
//     {
//         return 1;
//     }
// }

// void measure()
// {
//     if (measure_loop < ((int)(sizeof(measured_array) / sizeof(measured_array[0]))))
//     {
//         timedData_array[timedLoop] = t.read_ms();
//        // pc.printf("ADC - time je %f  \t a som na %d\n", timedData_array[timedLoop],measure_loop);
//         timedLoop++;
//         blik();
//         for (measure_loop = k; measure_loop < (100 + k); measure_loop++)
//         {
//             measured_array[measure_loop] = ADC();
//          //  measured_array[measure_loop] = measure_loop;
//         }
//         blik();
//         k += 100;
//     }
//     else
//     {
//         if (checkloop())
//         {
           
//             measure_loop = 0;
//             k = 0;
//             measure();
//         }
//         else
//         {
            
//         }
//     }
// }


// // only prepare for future value and functions.
// void measureRealSensor()
// {
//     realSensor_array[realSensorLoop]=t.read_ms();
//     realSensorLoop++;
//     timedData_array[timedLoop]=t.read_ms();
    
//     timedLoop++;
// }

// void cleararray()
// {
//     int clear_loop=0;
//     blik2();
//     wait(0.5);
//     blik2();
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
//    // for (loop_sended = 0; measured_array[loop_sended] > 0; loop_sended++)
//    for (loop_sended = 0; 1000; loop_sended++)
   
//     {
//        // pc.printf("%d ----- %d\n", loop_sended, measured_array[loop_sended]);
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
    
//     Ticker ticker;
//     ticker.attach(periodicCallback, 0.5);
//     //ticker.detach();
//     t.start();
//     button1.rise(&blik);
//     button2.rise(&measure);
//     button3.rise(&vypis);
//     BLE &ble = BLE::Instance(BLE::DEFAULT_INSTANCE);
//     ble.init(bleInitComplete);
    
    
//     //flipper.attach(&measure, 10);
//     //flipper2.attach(&measureRealSensor, 10);
//     //flipper2.attach(&triger_send2, 10);

//     /* SpinWait for initialization to complete. This is necessary because the
//      * BLE object is used in the main loop below. */
//     while (ble.hasInitialized() == false)
//     { /* spin loop */
//     }

//     /* Infinite loop waiting for BLE interrupt events */
//     while (true)
//     ticker.attach(periodicCallback, time_of_periodical_timer);
//     {       
//          if (triggerSensorPolling && ble.gap().getState().connected)
//          {
//              triggerSensorPolling = false; 
//             if (sended_switch == 1)
//             {
//                thermometerServicePtr->updateTemperature(measured_array[sended_loop]);
//                 measured_array[sended_loop]=0;
//                 sended_loop += 1;
//                  if (sended_loop >= measure_loop)
//                  {
//                     sended_switch = 0;
//                     sended_loop = 0;
//                     cleararray();
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




//....................................................MERANIE prudu



// #include "mbed.h"
// #include "ble/BLE.h"
// //#include "ble/BLEdevice.h"
// #include "ble/services/HealthThermometerService.h"
// #include "ble/services/CatService.h"
// #include "ble/ArrayView.h"
// #include "ble/services/UARTService.h"

// //inicialization of LEDs
// DigitalOut led1(LED1, 1);
// DigitalOut led2(LED2, 1);
// DigitalOut led3(LED3, 1);
// DigitalOut led4(LED4, 1);
// DigitalOut nastavenie(P0_5,0);
// DigitalOut nastavenie2(P0_7,0);
// //BLEDevice ble;

// uint16_t customServiceUUID = 0x181C;
// uint16_t writeCharUUID = 0x181C;

// //inicialization of buttons
// InterruptIn button1(p13);
// InterruptIn button2(p14);
// InterruptIn button3(p15);
// InterruptIn button4(p16);

// //inicialization of timers
// LowPowerTicker flipper;
// LowPowerTicker flipper2;
// Serial pc(USBTX, USBRX);
// int send=1;

// static double arrayMy[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
// static double temperatures[]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};

// int i=0;

// static int32_t temp[5000];


// static HealthThermometerService *thermometerServicePtr;

// static volatile bool triggerSensorPolling = false;

// const static char DEVICE_NAME[] = "Cats"; // change this
// static const uint16_t uuid16_list[] = {GattService::UUID_HEALTH_THERMOMETER_SERVICE};


// // uint8_t writeValue[10] = {4,2,3,5};
// // ReadWriteArrayGattCharacteristic<uint8_t, sizeof(writeValue)> writeChar(81299129, writeValue);

// // /* Set up custom service */
// // GattCharacteristic *characteristics[] = {&writeChar};
// // GattService customService(0x1810, characteristics, sizeof(characteristics) / sizeof(GattCharacteristic *));


// uint8_t writeValue[26] = {4,2,3,5,23,3,11,2};
// ReadWriteArrayGattCharacteristic<uint8_t, 10> writeChar(writeValue, writeValue);

// /* Set up custom service */
// GattCharacteristic *characteristics[] = {&writeChar};
// GattService customService(0x1810,  characteristics, sizeof(characteristics) / sizeof(GattCharacteristic *));

// void loopa()
// {   
//     int j=0;
//     for(j=0;j<5000;j++)
//     {
//         temp[j]=j;
//     }
// }


// void blik_led()
// {
//     led1=!led1;
// }

// void blik()
// {
      
// }

// //function for setting
// void periodicCallback(void)
// {
//        triggerSensorPolling = true;
//        i+=1;
// }

// void disconnectionCallback(const Gap::DisconnectionCallbackParams_t *)
// {
//     BLE::Instance(BLE::DEFAULT_INSTANCE).gap().startAdvertising();
// }


// void writeCharCallback(const GattWriteCallbackParams *params)
// {

//     if (params->data[0] <= 10)
//     {
//         pc.printf("%d",params->data[0]);
//     }
// }

// void click()
// {
//     i+=1;
    
    
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
    
    
//     /* Setup advertising */
//     ble.gap().accumulateAdvertisingPayload(GapAdvertisingData::BREDR_NOT_SUPPORTED | GapAdvertisingData::LE_GENERAL_DISCOVERABLE);            // BLE only, no classic BT
//     ble.gap().setAdvertisingType(GapAdvertisingParams::ADV_CONNECTABLE_UNDIRECTED);                                                           // advertising type
//     ble.gap().accumulateAdvertisingPayload(GapAdvertisingData::COMPLETE_LOCAL_NAME, (uint8_t *)DEVICE_NAME, sizeof(DEVICE_NAME));             // add name
//     ble.gap().accumulateAdvertisingPayload(GapAdvertisingData::COMPLETE_LIST_32BIT_SERVICE_IDS, (uint8_t *)uuid16_list, sizeof(uuid16_list)); // UUID's broadcast in advertising packet
//     ble.gap().accumulateAdvertisingPayload(GapAdvertisingData::COMPLETE_LIST_16BIT_SERVICE_IDS,writeValue, sizeof(writeValue));
//     ble.gap().setAdvertisingInterval(100);                                                                                                    // 100ms.

//     /* Add our custom service */
//    ble.addService(customService);

//     /* Start advertising */
//     ble.gap().startAdvertising();
// }

// /*
//  *  Main loop
// */
// int main(void)
// {
//     /* initialize stuff */
//     ;
//     Ticker Timmer;
//     Timmer.attach(periodicCallback,1);
//     button1.rise(&blik_led);
//     BLE &ble = BLE::Instance(BLE::DEFAULT_INSTANCE);
//     ble.init(bleInitComplete);
//     button1.rise(&click);
//     //loopa();
    
//      //flipper.attach(&measure, 10);
//     //flipper2.attach(&measureRealSensor, 10);
//     //flipper2.attach(&triger_send2, 10);

//     /* SpinWait for initialization to complete. This is necessary because the
//      * BLE object is used in the main loop below. */
//     while (ble.hasInitialized() == false)
//     { /* spin loop */
//     }

//     /* Infinite loop waiting for BLE interrupt events */
//     while (true)
    
//     {       
//          if (triggerSensorPolling && ble.gap().getState().connected)
//          {
        
//         //thermometerServicePtr->updateTemperature(temp[i]);
//         thermometerServicePtr->updateTemperature(temperatures[0]);
        
       
       
//         }
//         else
//         {
           
//             ble.waitForEvent(); /* Save power */
            
//         }
//     }
// }






//.....................................................Threads......................................................

// #include "mbed.h"

// LowPowerTimer t;
 
// int main() {
//     t.start();
//     printf("Hello World!\n");
//     t.stop();
//     printf("The time taken was %f seconds\n", t.read());
// }

// #include "mbed.h"
 
// LowPowerTicker flipper;
// DigitalOut led1(LED1);
 
// void flip() {
//     led1 = !led1;
// }
 
// int main() {
//     led1 = 1;
//     flipper.attach(&flip, 2.0); // the address of the function to be attached (flip) and the interval (2 seconds)
 
//     while(1) {
//         wait(12);
//     }
// }

//......................................................UART ble....................................................

 
// #include <string.h>
// #include "mbed.h"
// #include "BLE.h"
 
// #include "UARTService.h"
 
// #define NEED_CONSOLE_OUTPUT 1 /* Set this if you need debug messages on the console;
//                                * it will have an impact on code-size and power consumption. */
 
// #if NEED_CONSOLE_OUTPUT
// #define DEBUG(STR) { if (uart) uart->write(STR, strlen(STR)); }
// #else
// #define DEBUG(...) /* nothing */
// #endif /* #if NEED_CONSOLE_OUTPUT */
// Serial pc(USBTX, USBRX);
// static volatile bool triggerSensorPolling = false;

//  const static char DEVICE_NAME[] = "Cats"; // change this
//  static const uint16_t uuid16_list[] = {GattService::UUID_HEALTH_THERMOMETER_SERVICE};

 

// DigitalOut led1(LED1);
// UARTService *uart;

// void disconnectionCallback(const Gap::DisconnectionCallbackParams_t *)
// {
//     pc.printf("Disconnected!\n\r");
//     pc.printf("Restarting the advertising process\n\r");
//     BLE::Instance(BLE::DEFAULT_INSTANCE).gap().startAdvertising();
// }
 

 
// void periodicCallback(void)
// {
//     led1 = !led1;
   
// }

// void bleInitComplete(BLE::InitializationCompleteCallbackContext *params)
// {
//     BLE &ble = params->ble;
//     ble_error_t error = params->error;

//     if (error != BLE_ERROR_NONE)
//     {
//         return;
//     }

//     ble.init();
//     ble.onDisconnection(disconnectionCallback);
    
//     uart = new UARTService(ble);
 
//     /* setup advertising */
//     ble.accumulateAdvertisingPayload(GapAdvertisingData::BREDR_NOT_SUPPORTED);
//     ble.setAdvertisingType(GapAdvertisingParams::ADV_CONNECTABLE_UNDIRECTED);
//     ble.accumulateAdvertisingPayload(GapAdvertisingData::SHORTENED_LOCAL_NAME,
//                                      (const uint8_t *)"BLE UART", sizeof("BLE UART") - 1);
//     ble.accumulateAdvertisingPayload(GapAdvertisingData::COMPLETE_LIST_128BIT_SERVICE_IDS,
//                                      (const uint8_t *)UARTServiceUUID_reversed, sizeof(UARTServiceUUID_reversed));
 
//     ble.setAdvertisingInterval(160); /* 100ms; in multiples of 0.625ms. */
//     ble.startAdvertising();
// }
 
// int main(void)
// {
//      led1 = 1;
//     Ticker ticker;
//     ticker.attach(periodicCallback, 1);
 
//     pc.printf("Initialising the nRF51822\n\r");
//     BLE &ble = BLE::Instance(BLE::DEFAULT_INSTANCE);
//     ble.init(bleInitComplete);

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
//         }
        
//         else
//         {
//             ble.waitForEvent(); /* Save power */
//     }
//     }
// }




// DigitalIn INT(I2C_SCL0);  //...............................................................nahodne pouzite I2C_SCL0






// #ifdef TARGET_KL25Z 
// PwmOut led(PTB18);  //initializes the pwm output that connects to the on board LED
// DigitalIn INT(PTD1);  //pin PTD1 connects to the interrupt output pin of the MAX30102
// #endif
// #ifdef TARGET_K64F
// DigitalIn INT(PTD1);  //pin PTD1 connects to the interrupt output pin of the MAX30102
// #endif
// #ifdef TARGET_MAX32600MBED
// PwmOut led(LED_RED);    //initializes the pwm output that connects to the on board LED
// DigitalIn INT(P2_0);  //pin P20 connects to the interrupt output pin of the MAX30102
// #endif
 
// // the setup routine runs once when you press reset:
// int main() { 
//     uint32_t un_min, un_max, un_prev_data;  //variables to calculate the on-board LED brightness that reflects the heartbeats
//     int i;
//     int32_t n_brightness;
//     float f_temp;
    
//     maxim_max30102_reset(); //resets the MAX30102
//     // initialize serial communication at 115200 bits per second:
//     pc.baud(9600);
//     pc.format(8,SerialBase::None,1);
//     wait(1);
    
//     //read and clear status register
//     maxim_max30102_read_reg(0,&uch_dummy);
    
//     //wait until the user presses a key
//     while(pc.readable()==0)
//     {
//         pc.printf("\x1B[2J");  //clear terminal program screen
//         pc.printf("Press any key to start conversion\n\r");
//         wait(5);
//     }
//     uch_dummy=getchar();
    
//     maxim_max30102_init();  //initializes the MAX30102
        
        
//     n_brightness=0;
//     un_min=0x3FFFF;
//     un_max=0;
  
//     n_ir_buffer_length=500; //buffer length of 100 stores 5 seconds of samples running at 100sps
    
//     //read the first 500 samples, and determine the signal range
//     for(i=0;i<n_ir_buffer_length;i++)
//     {
//         while(INT.read()==1);   //wait until the interrupt pin asserts
        
//         maxim_max30102_read_fifo((aun_red_buffer+i), (aun_ir_buffer+i));  //read from MAX30102 FIFO
            
//         if(un_min>aun_red_buffer[i])
//             un_min=aun_red_buffer[i];    //update signal min
//         if(un_max<aun_red_buffer[i])
//             un_max=aun_red_buffer[i];    //update signal max
//         pc.printf("red=");
//         pc.printf("%i", aun_red_buffer[i]);
//         pc.printf(", ir=");
//         pc.printf("%i\n\r", aun_ir_buffer[i]);
//     }
//     un_prev_data=aun_red_buffer[i];
    
    
//     //calculate heart rate and SpO2 after first 500 samples (first 5 seconds of samples)
//     maxim_heart_rate_and_oxygen_saturation(aun_ir_buffer, n_ir_buffer_length, aun_red_buffer, &n_sp02, &ch_spo2_valid, &n_heart_rate, &ch_hr_valid); 
    
//     //Continuously taking samples from MAX30102.  Heart rate and SpO2 are calculated every 1 second
//     while(1)
//     {
//         i=0;
//         un_min=0x3FFFF;
//         un_max=0;
        
//         //dumping the first 100 sets of samples in the memory and shift the last 400 sets of samples to the top
//         for(i=100;i<500;i++)
//         {
//             aun_red_buffer[i-100]=aun_red_buffer[i];
//             aun_ir_buffer[i-100]=aun_ir_buffer[i];
            
//             //update the signal min and max
//             if(un_min>aun_red_buffer[i])
//             un_min=aun_red_buffer[i];
//             if(un_max<aun_red_buffer[i])
//             un_max=aun_red_buffer[i];
//         }
        
//         //take 100 sets of samples before calculating the heart rate.
//         for(i=400;i<500;i++)
//         {
//             un_prev_data=aun_red_buffer[i-1];
//             while(INT.read()==1);
//             maxim_max30102_read_fifo((aun_red_buffer+i), (aun_ir_buffer+i));
        
//             if(aun_red_buffer[i]>un_prev_data)
//             {
//                 f_temp=aun_red_buffer[i]-un_prev_data;
//                 f_temp/=(un_max-un_min);
//                 f_temp*=MAX_BRIGHTNESS;
//                 n_brightness-=(int)f_temp;
//                 if(n_brightness<0)
//                     n_brightness=0;
//             }
//             else
//             {
//                 f_temp=un_prev_data-aun_red_buffer[i];
//                 f_temp/=(un_max-un_min);
//                 f_temp*=MAX_BRIGHTNESS;
//                 n_brightness+=(int)f_temp;
//                 if(n_brightness>MAX_BRIGHTNESS)
//                     n_brightness=MAX_BRIGHTNESS;
//             }
// #if defined(TARGET_KL25Z) || defined(TARGET_MAX32600MBED)
//             led.write(1-(float)n_brightness/256);
// #endif
//             //send samples and calculation result to terminal program through UART
//             pc.printf("red=");
//             pc.printf("%i", aun_red_buffer[i]);
//             pc.printf(", ir=");
//             pc.printf("%i", aun_ir_buffer[i]);
//             pc.printf(", HR=%i, ", n_heart_rate); 
//             pc.printf("HRvalid=%i, ", ch_hr_valid);
//             pc.printf("SpO2=%i, ", n_sp02);
//             pc.printf("SPO2Valid=%i\n\r", ch_spo2_valid);
//         }
//         maxim_heart_rate_and_oxygen_saturation(aun_ir_buffer, n_ir_buffer_length, aun_red_buffer, &n_sp02, &ch_spo2_valid, &n_heart_rate, &ch_hr_valid); 
//     }
// }

//..........................................................UART//////////....................................................

// /* mbed Microcontroller Library
//  * Copyright (c) 2006-2015 ARM Limited
//  *
//  * Licensed under the Apache License, Version 2.0 (the "License");
//  * you may not use this file except in compliance with the License.
//  * You may obtain a copy of the License at
//  *
//  *     http://www.apache.org/licenses/LICENSE-2.0
//  *
//  * Unless required by applicable law or agreed to in writing, software
//  * distributed under the License is distributed on an "AS IS" BASIS,
//  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  * See the License for the specific language governing permissions and
//  * limitations under the License.
//  */
// #include <string.h>
// #include "mbed.h"
// #include "ble/BLE.h"
// #include "UARTService.h"

 
// #define BUFFER_LEN 1024


// DigitalOut led1(LED1);
// UARTService* uart;
// Serial pc(USBTX, USBRX);
 
// const static char     DEVICE_NAME[] = "Cats";
 
// char buffer[BUFFER_LEN];
 
// /*Callback quando il dispositivo client si disconnette */
// void disconnectionCallback(const Gap::DisconnectionCallbackParams_t *params){
//     BLE::Instance().gap().startAdvertising();
    
//     pc.printf("Periferica disconnessa \r\n");
// }
 
// void connectionCallback(const Gap::ConnectionCallbackParams_t *params){
//     if(params->role == Gap::CENTRAL){
//         pc.printf("Connesso dispositivo %u \r\n");
//     }
// }
 
// void periodicCallback(void){
//     led1 = !led1;
    
//     /*Per spedire qualcosa al client*/
//     // char* str = "Ciao \r\n";
//     // if (uart) uart->writeString(str);
// }
 
// /**
//  * Chiamata in caso di errore, ottengo il codice sulla console
//  */
// void onBleInitError(BLE &ble, ble_error_t error){
//      pc.printf("Errore interno %u \r\n",error);
// }
 
 
// void onDataWritten(const GattWriteCallbackParams *params){
//     if ((uart != NULL) && (params->handle == uart->getTXCharacteristicHandle())) {
//         uint16_t bytesRead = params->len;
        
//         pc.printf("ricevuti %u bytes\n\r ", bytesRead);
        
//         if(bytesRead >= 255){
//             pc.printf("Overflow comando %u n\r ", bytesRead);
//             bytesRead = 255;
//         }
        
//         unsigned index = 0;
//         for (; index < bytesRead; index++) {
//             buffer[index] = params->data[index];
//         }
        
//         buffer[index++] = 0;
        
//         pc.printf("Data : %s ",buffer);
//         pc.printf("\r\n");
//     }
// }
 

// void bleInitComplete(BLE::InitializationCompleteCallbackContext *params){
    
//     BLE&        ble   = params->ble;
//     ble_error_t error = params->error;
 
//     if (error != BLE_ERROR_NONE) {
//         onBleInitError(ble, error);
//         return;
//     }
 
//     if(ble.getInstanceID() != BLE::DEFAULT_INSTANCE) {
//         return;
//     }

//     ble.gap().onDisconnection(disconnectionCallback);
//     ble.gap().onConnection(connectionCallback);
//     ble.onDataWritten(onDataWritten);
//     uart = new UARTService(ble);
//     ble.gap().accumulateAdvertisingPayload(GapAdvertisingData::BREDR_NOT_SUPPORTED | GapAdvertisingData::LE_GENERAL_DISCOVERABLE);
//     ble.gap().accumulateAdvertisingPayload(GapAdvertisingData::COMPLETE_LOCAL_NAME, (uint8_t *)DEVICE_NAME, sizeof(DEVICE_NAME));
//     ble.accumulateAdvertisingPayload(GapAdvertisingData::COMPLETE_LIST_128BIT_SERVICE_IDS, (const uint8_t *)UARTServiceUUID_reversed, sizeof(UARTServiceUUID_reversed));
//     ble.gap().setAdvertisingType(GapAdvertisingParams::ADV_CONNECTABLE_UNDIRECTED);
//     ble.gap().setAdvertisingInterval(100); /* 1000ms. */
//     ble.gap().startAdvertising();
// }
 
 
// int main(void)
// {

//     BLE &ble = BLE::Instance();
//     ble.init(bleInitComplete);
    
//     /* Aspetto fino a che la periferica bluetooth non è inizializzata */
//     while (ble.hasInitialized()  == false) { /* spin loop */ }
    
//     Ticker ticker;
//     ticker.attach(periodicCallback, 0.5);
    
//     while (true) {
//         ble.waitForEvent();
//     }
// }


//..........................................Posielanie dat............................................................

#include "mbed.h"
#include "ble/BLE.h"
//#include "ble/services/HealthThermometerService.h"
#include "ble/services/GatService.h"




//#include "ble/services/HeartRateService-backup.h"
 
DigitalOut led1(LED1);
 
static HealthThermometerService *thermometerServicePtr;
//static DFUService *dfuPtr;
 
static const char     DEVICE_NAME[]        = "CATS";
static const uint16_t uuid16_list[]        = {GattService::UUID_HEALTH_THERMOMETER_SERVICE};
static volatile bool  triggerSensorPolling = false;
static float          currentTemperature   = 0;
static float          temp[5000];
static float          array_BPM[]={2,4,6,4,10,8,12,4,9,15};
static int            i                    =0;
static int            test_of_sleep        =0;
static volatile bool  trigger              =false;
InterruptIn button1(p13);
//uint16_t customServiceUUID = 0x1812;
uint16_t writeCharUUID = 0x2A59;
static uint8_t writeValue[10] = {0};
uint16_t writeCharUUID2 = 0x2A58;
static uint8_t writeValue2[10] = {0};


WriteOnlyArrayGattCharacteristic<uint8_t, sizeof(writeValue)> writeChar(writeCharUUID, writeValue);
WriteOnlyArrayGattCharacteristic<uint8_t, sizeof(writeValue2)> writeChar2(writeCharUUID2, writeValue2);
GattCharacteristic *characteristics[] = {&writeChar,&writeChar2};
GattService customService(0x1815, characteristics, sizeof(characteristics) / sizeof(GattCharacteristic *));



//static uint8_t AdvData[] = {0x07,0x02,0x03,0x04,0x05,0x03,0x04,0x05,0x03,0x04,0x05,0x03,0x04,0x255,0x24,0x04,0x05,0x03,0x04,0x05,0x03,0x04,0x04,0x05,0x65,0x34};
 
void blik()
{
    led1=!led1;
}
 
/* Restart Advertising on disconnection*/
void disconnectionCallback(const Gap::DisconnectionCallbackParams_t *params)
{
    BLE::Instance().gap().startAdvertising();
}



void click()
{
    for (int i = 0; i < 5000; i++)
    {
        temp[i] = i;
    }
    trigger = true;
}
void periodicCallback(void)
{
    triggerSensorPolling = true;
}
void writeCharCallback(const GattWriteCallbackParams *params)
{
  
    if (params->data[0] <= 50)
        {
        blik();
        click();
        }
}
 
/**
 * This function is called when the ble initialization process has failed
 */
void onBleInitError(BLE &ble, ble_error_t error)
{
    /* Avoid compiler warnings */
    (void) ble;
    (void) error;
    /* Initialization error handling should go here */
}
 
/**
 * Callback triggered when the ble initialization process has finished
 */
void bleInitComplete(BLE::InitializationCompleteCallbackContext *params)
{
    BLE&        ble   = params->ble;
    ble_error_t error = params->error;
 
    if (error != BLE_ERROR_NONE) {
        /* In case of error, forward the error handling to onBleInitError */
        onBleInitError(ble, error);
        return;
    }
 
    /* Ensure that it is the default instance of BLE */
    if(ble.getInstanceID() != BLE::DEFAULT_INSTANCE) {
        return;
    }
    
    ble.gap().onDisconnection(disconnectionCallback);
    
    ble.gattServer().onDataWritten(writeCharCallback);
    /* Setup primary service. */
    thermometerServicePtr = new HealthThermometerService(ble, currentTemperature,4);
    /* setup advertising */
    ble.gap().accumulateAdvertisingPayload(GapAdvertisingData::BREDR_NOT_SUPPORTED | GapAdvertisingData::LE_GENERAL_DISCOVERABLE);
    ble.gap().accumulateAdvertisingPayload(GapAdvertisingData::COMPLETE_LIST_32BIT_SERVICE_IDS, (uint8_t *)uuid16_list, sizeof(uuid16_list));
    ble.gap().accumulateAdvertisingPayload(10);
    ble.gap().accumulateAdvertisingPayload(GapAdvertisingData::COMPLETE_LOCAL_NAME, (uint8_t *)DEVICE_NAME, sizeof(DEVICE_NAME));
    ble.gap().setAdvertisingType(GapAdvertisingParams::ADV_CONNECTABLE_UNDIRECTED); 
    ble.gap().setAdvertisingInterval(100); /* 1000ms */
    ble.addService(customService); 
    ble.gap().startAdvertising();
    
}

int main(void)
{
    
    


    
    
    led1 = 1;
    
    Ticker ticker;
    ticker.attach(periodicCallback, 0.04);
    button1.rise(&click);
    BLE &ble = BLE::Instance();
    ble.init(bleInitComplete);
    
    /* SpinWait for initialization to complete. This is necessary because the
     * BLE object is used in the main loop below. */
    while (ble.hasInitialized()  == false) { /* spin loop */ }

    while (true)
    {
        if (triggerSensorPolling && ble.gap().getState().connected)
        {
            triggerSensorPolling = false;
            blik();
            if (trigger)
            {
  
                if (i<5000)
                {
                thermometerServicePtr->testloop(&temp[i]);
                thermometerServicePtr->testloop2(array_BPM);
                i+=10;
                }
                else  // initialising to default value
                {
                    trigger=false;
                    i=0;
                }
            }
        }
        else
        {
        ble.waitForEvent();
        }
    }
}

/* mbed Microcontroller Library
 * Copyright (c) 2006-2015 ARM Limited
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

// #include "mbed.h"
// #include "ble/BLE.h"
// #include "ble/Gap.h"
// #include "ble/services/HeartRateService.h"
// #include "ble/services/DFUService.h"

// DigitalOut led1(LED1, 1);

// const static char     DEVICE_NAME[] = "HRM";
// static const uint16_t uuid16_list[] = {GattService::UUID_HEART_RATE_SERVICE};

// static uint8_t hrmCounter = 100; // init HRM to 100bps
// static HeartRateService *hrServicePtr;
// static DFUService *dfuPtr;

// void disconnectionCallback(const Gap::DisconnectionCallbackParams_t *params)
// {
//     BLE::Instance().gap().startAdvertising(); // restart advertising
// }

// void updateSensorValue() {
//     // Do blocking calls or whatever is necessary for sensor polling.
//     // In our case, we simply update the HRM measurement.
//     hrmCounter++;

//     //  100 <= HRM bps <=175
//     if (hrmCounter == 175) {
//         hrmCounter = 100;
//     }

//     hrServicePtr->updateHeartRate(hrmCounter);
// }

// void periodicCallback(void)
// {
//     led1 = !led1; /* Do blinky on LED1 while we're waiting for BLE events */

    
// }

// void onBleInitError(BLE &ble, ble_error_t error)
// {
//    /* Initialization error handling should go here */
// }

// void bleInitComplete(BLE::InitializationCompleteCallbackContext *params)
// {
//     BLE&        ble   = params->ble;
//     ble_error_t error = params->error;

//     if (error != BLE_ERROR_NONE) {
//         onBleInitError(ble, error);
//         return;
//     }

//     if (ble.getInstanceID() != BLE::DEFAULT_INSTANCE) {
//         return;
//     }

//     ble.gap().onDisconnection(disconnectionCallback);

//     dfuPtr = new DFUService(ble);

//     /* Setup primary service. */
//     hrServicePtr = new HeartRateService(ble, hrmCounter, HeartRateService::LOCATION_FINGER);

//     /* Setup advertising. */
//     ble.gap().accumulateAdvertisingPayload(GapAdvertisingData::BREDR_NOT_SUPPORTED | GapAdvertisingData::LE_GENERAL_DISCOVERABLE);
//     ble.gap().accumulateAdvertisingPayload(GapAdvertisingData::COMPLETE_LIST_16BIT_SERVICE_IDS, (uint8_t *)uuid16_list, sizeof(uuid16_list));
//     ble.gap().accumulateAdvertisingPayload(GapAdvertisingData::GENERIC_HEART_RATE_SENSOR);
//     ble.gap().accumulateAdvertisingPayload(GapAdvertisingData::COMPLETE_LOCAL_NAME, (uint8_t *)DEVICE_NAME, sizeof(DEVICE_NAME));
//     ble.gap().setAdvertisingType(GapAdvertisingParams::ADV_CONNECTABLE_UNDIRECTED);
//     ble.gap().setAdvertisingInterval(1000); /* 1000ms */
//     ble.gap().startAdvertising();
// }

// void app_start(int, char **)
// {
   

//     BLE::Instance().init(bleInitComplete);
// }

// int main(void)
// {
    
    
//     led1 = 1;
    
//     Ticker ticker;
//     ticker.attach(periodicCallback, 0.4);
    
//     BLE &ble = BLE::Instance();
//     ble.init(bleInitComplete);
    
//     /* SpinWait for initialization to complete. This is necessary because the
//      * BLE object is used in the main loop below. */
//     while (ble.hasInitialized()  == false) { /* spin loop */ }

//     while (true)
//     {
        
//         ble.waitForEvent();
//     }
//     }



















//.................................NEFUJGUJE ----- kod na DFU proces. //////////////////////////////////


// /* mbed Microcontroller Library
//  * Copyright (c) 2006-2015 ARM Limited
//  *
//  * Licensed under the Apache License, Version 2.0 (the "License");
//  * you may not use this file except in compliance with the License.
//  * You may obtain a copy of the License at
//  *
//  *     http://www.apache.org/licenses/LICENSE-2.0
//  *
//  * Unless required by applicable law or agreed to in writing, software
//  * distributed under the License is distributed on an "AS IS" BASIS,
//  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  * See the License for the specific language governing permissions and
//  * limitations under the License.
//  */

// #include "mbed.h"
// #include "ble/BLE.h"
// #include "ble/Gap.h"
// #include "ble/services/HeartRateService-backup.h"
// #include "/home/danieldemcak/.platformio/packages/framework-mbed/features/FEATURE_BLE/ble/services/DFUtest.h"


// DigitalOut led1(LED1, 1);

// const static char     DEVICE_NAME[] = "HRM";
// static const uint16_t uuid16_list[] = {GattService::UUID_HEART_RATE_SERVICE};

// static uint8_t hrmCounter = 100; // init HRM to 100bps
// static HeartRateService *hrServicePtr;
// static DFUServicea *dfuPtr;

// void disconnectionCallback(const Gap::DisconnectionCallbackParams_t *params)
// {
//     BLE::Instance().gap().startAdvertising(); // restart advertising
// }

// void updateSensorValue() {
//     // Do blocking calls or whatever is necessary for sensor polling.
//     // In our case, we simply update the HRM measurement.
//     hrmCounter++;

//     //  100 <= HRM bps <=175
//     if (hrmCounter == 175) {
//         hrmCounter = 100;
//     }

//     hrServicePtr->updateHeartRate(hrmCounter);
// }

// void periodicCallback(void)
// {
//     led1 = !led1; /* Do blinky on LED1 while we're waiting for BLE events */

   
// }

// void onBleInitError(BLE &ble, ble_error_t error)
// {
//    /* Initialization error handling should go here */
// }

// void bleInitComplete(BLE::InitializationCompleteCallbackContext *params)
// {
//     BLE&        ble   = params->ble;
//     ble_error_t error = params->error;

//     if (error != BLE_ERROR_NONE) {
//         onBleInitError(ble, error);
//         return;
//     }

//     if (ble.getInstanceID() != BLE::DEFAULT_INSTANCE) {
//         return;
//     }

//     ble.gap().onDisconnection(disconnectionCallback);

//     dfuPtr = new DFUServicea(ble);

//     /* Setup primary service. */
//     hrServicePtr = new HeartRateService(ble, hrmCounter, HeartRateService::LOCATION_FINGER);

//     /* Setup advertising. */
//     ble.gap().accumulateAdvertisingPayload(GapAdvertisingData::BREDR_NOT_SUPPORTED | GapAdvertisingData::LE_GENERAL_DISCOVERABLE);
//     ble.gap().accumulateAdvertisingPayload(GapAdvertisingData::COMPLETE_LIST_16BIT_SERVICE_IDS, (uint8_t *)uuid16_list, sizeof(uuid16_list));
//     ble.gap().accumulateAdvertisingPayload(GapAdvertisingData::GENERIC_HEART_RATE_SENSOR);
//     ble.gap().accumulateAdvertisingPayload(GapAdvertisingData::COMPLETE_LOCAL_NAME, (uint8_t *)DEVICE_NAME, sizeof(DEVICE_NAME));
//     ble.gap().setAdvertisingType(GapAdvertisingParams::ADV_CONNECTABLE_UNDIRECTED);
//     ble.gap().setAdvertisingInterval(1000); /* 1000ms */
//     ble.gap().startAdvertising();
// }

// void app_start(int, char **)
// {
    

//     BLE::Instance().init(bleInitComplete);
// }

// int main(void)
// {
    
//     Ticker ticker;
//     ticker.attach(periodicCallback,1); // blink LED every second
    
//     BLE& ble = BLE::Instance(BLE::DEFAULT_INSTANCE);
//     ble.init(bleInitComplete);
    
 
//     /* SpinWait for initialization to complete. This is necessary because the
//      * BLE object is used in the main loop below. */
//     while (ble.hasInitialized()  == false) { /* spin loop */ }
 
//     // infinite loop
//     while (1) {
     
            
//                 ble.waitForEvent(); // low power wait for event
        
// }
// }



//...............................................PRE PETA na ukazku............................................
 
// #include "mbed.h"
// #include "Logger.h"
// #include "Configuration.h"
// #include "BLEDevice.h"
// #include "TransferService.h"
 
// BLEDevice ble;
 
// static Gap::ConnectionParams_t connectionParams;
 
// static const uint8_t *uuidlist = Transfer::getServiceUUIDp();
// static uint8_t uuidlistrev[16];
// static const char *DEVICE_NAME = "SD";
 
// void bluetoothInit();
 
// void disconnectionCallback(Gap::Handle_t handle, Gap::DisconnectionReason_t reason)
// {
//     DEBUG("Disconnected\n\r");
//     ble.startAdvertising();
//     DEBUG("Advertising...\r\n");
// }
 
// void onConnectionCallback(Gap::Handle_t handle, Gap::addr_type_t peerAddrType, const Gap::address_t peerAddr, const Gap::ConnectionParams_t *params)
// {
//     DEBUG("____[ Connected ]______________________________________\r\n");
//     DEBUG("Conn. params => min=%d, max=%d, slave=%d, supervision=%d\r\n",
//           params->minConnectionInterval, params->maxConnectionInterval, params->slaveLatency, params->connectionSupervisionTimeout);
 
//     connectionParams.minConnectionInterval        = Config::minConnectionInterval;
//     connectionParams.maxConnectionInterval        = Config::maxConnectionInterval;
//     connectionParams.slaveLatency                 = Config::slaveLatency;
//     connectionParams.connectionSupervisionTimeout = Config::supervisionTimeout;
//     if (ble.updateConnectionParams(handle, &connectionParams) != BLE_ERROR_NONE) {
//         DEBUG("failed to update connection paramter\r\n");
//     }
 
//     Transfer::reset();
// }
 
// void onUpdatesEnabled(Gap::Handle_t handle)
// {
//     DEBUG("Notifications enabled for %d\r\n", handle);
// }
 
// void onDataWritten(const GattCharacteristicWriteCBParams *params)
// {
//     // bubble up to services, they will emit callbacks if handle matches
//     Transfer::handleDataWritten(params);
// }
 
// void bluetoothInit()
// {
//     DEBUG("Bluetooth initialising...\r\n");
//     ble.init();
//     ble.setDeviceName(Config::deviceName);
//     ble.onDisconnection(disconnectionCallback);
//     ble.onConnection(onConnectionCallback);
//     ble.onDataWritten(onDataWritten);
//     ble.onUpdatesEnabled(onUpdatesEnabled);
 
//     // Make sure we use our preferred conn. parameters
//     connectionParams.minConnectionInterval        = Config::minConnectionInterval;
//     connectionParams.maxConnectionInterval        = Config::maxConnectionInterval;
//     connectionParams.slaveLatency                 = Config::slaveLatency;
//     connectionParams.connectionSupervisionTimeout = Config::supervisionTimeout;
//     ble.setPreferredConnectionParams(&connectionParams);
//     ble.getPreferredConnectionParams(&connectionParams);
//     DEBUG("Conn. params => min=%d, max=%d, slave=%d, supervision=%d\r\n",
//           connectionParams.minConnectionInterval,
//           connectionParams.maxConnectionInterval,
//           connectionParams.slaveLatency,
//           connectionParams.connectionSupervisionTimeout);
 
//     // Initialise transfer service
//     Transfer::init(ble);
 
//     /* setup advertising */
//     ble.accumulateAdvertisingPayload(GapAdvertisingData::BREDR_NOT_SUPPORTED | GapAdvertisingData::LE_GENERAL_DISCOVERABLE);
//     ble.accumulateAdvertisingPayload(GapAdvertisingData::COMPLETE_LIST_128BIT_SERVICE_IDS, uuidlistrev, 16);
//     ble.setAdvertisingType(GapAdvertisingParams::ADV_CONNECTABLE_UNDIRECTED);
//     ble.accumulateAdvertisingPayload(GapAdvertisingData::COMPLETE_LOCAL_NAME, (uint8_t *)DEVICE_NAME, sizeof(DEVICE_NAME));
//     ble.setAdvertisingInterval(Config::advertisingInterval);
//     ble.startAdvertising();
//     DEBUG("Ready. Advertising.\r\n");
// }
 
// int main(void)
// {
//     DEBUG("Initialising TRANSFER PRO | Built %s %s\n\r", __DATE__, __TIME__);
 
//     for (int i = 0; i < 16; i++) {
//         uuidlistrev[15 - i] = uuidlist[i];
//     }
 
//     bluetoothInit();
 
//     while (true) {
//         ble.waitForEvent();
//     }
// }
 

