#include <Arduino.h>
// AirLift_testtoggletarget - drawing from the subscription and type conversion examples, 
// let's just light an LED in sync with the behaviour of my TestToggle feed on AIO using a
// DC Boarduino (discontinued) and an AirLift breakout.

// edit config_template.h with your AIO, WiFi, and board particulars, and rename it config.h to be used here.
#include "config.h"

void handleMessage(AdafruitIO_Data *data);

// set up the 'testoggle' feed
AdafruitIO_Feed *testtoggle = io.feed("testtoggle");

// give us an LED to light
#define LED 9

void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
  while(! Serial);

  Serial.print("Connecting to Adafruit IO");

  // start MQTT connection to io.adafruit.com
  io.connect();

  // set up a message handler for the count feed.
  // the handleMessage function (defined below)
  // will be called whenever a message is
  // received from adafruit io.
  testtoggle->onMessage(handleMessage);

  // wait for an MQTT connection
  // NOTE: when blending the HTTP and MQTT API, always use the mqttStatus
  // method to check on MQTT connection status specifically
  while(io.mqttStatus() < AIO_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  // Because Adafruit IO doesn't support the MQTT retain flag, we can use the
  // get() function to ask IO to resend the last value for this feed to just
  // this MQTT client after the io client is connected.
  testtoggle->get();

  // we are connected
  Serial.println();
  Serial.println(io.statusText());

}

void loop() {

  // io.run(); is required for all sketches.
  // it should always be present at the top of your loop
  // function. it keeps the client connected to
  // io.adafruit.com, and processes any incoming data.
  io.run();

  // Because this sketch isn't publishing, we don't need
  // a delay() in the main program loop.
  
  // but, aren't we HAMMERING the wifi to poll? Adding delay here (even if not needed) does affect its responsiveness, but it does still work.
  //delay(1000);

}

// this function is called whenever a 'testtoggle' message
// is received from Adafruit IO. it was attached to
// the testtoggle feed in the setup() function above.
void handleMessage(AdafruitIO_Data *data) {

  Serial.print("received <- ");
  Serial.println(data->value());
  // convert 'value' to int so we can do something "useful" (lighting the LED) in response. 'value' is only ever 1 or 0 for this feed.
  int value = data->toInt();
  Serial.print("Value = ");
  Serial.println(value);
  

  digitalWrite(LED, value);

}
