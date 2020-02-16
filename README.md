# AirLift_TestToggleTarget

(2020-02-15@1051)

An experiment using the [Adafruit AirLift breakout](https://learn.adafruit.com/adafruit-airlift-breakout/arduino) on a [DC Boarduino](https://www.adafruit.com/product/72) to subscribe to an [Adafruit.IO](https://io.adafruit.com/) feed (a private feed of mine called testtoggle). As seen over in [AirLift_buttonthing](https://github.com/kenkl/AirLift_buttonthing), there *might* be issues with long-running WiFi Things on the old ATMEGA328, but only one way I know of to find out is to build something, let it run and see what happens.

Included is a copy of the [Adafruit_IO_Arduino](https://github.com/adafruit/Adafruit_IO_Arduino) libraries, as well as the Adafruit fork of [WiFiNINA](https://github.com/adafruit/WiFiNINA) libraries.

Building with Visual Studio Code with PlatformIO, I was prompted to install the Adafruit_MQTT and ArduinoHttpClient libraries within PIO. That installs the libraries in ~/.platformio/lib - making them available for all projects on my dev machine. (Maybe I should put the AIO and forked WiFiNINA libs there?)

(2020-02-16@1044)

Pleased, and a little suprised - AirLift_TestToggleTarget is, after 24 hours of continuous operation, still functioning as designed/programmed. Although it uses the same hardware seen in [AirLift_buttonthing](https://github.com/kenkl/AirLift_buttonthing), the behaviour seems stable.

This may be a way to press older 328-based devices into service as AIO/IoT targets. Fun stuff! Because this is simply a recycle/retooling of AirLift_buttonthing, our gratuitious snapshot is the same as before:

![AirLift_buttonthing](https://i.imgur.com/mYJM0Xn.jpg "AirLift buttonthing")
