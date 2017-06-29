# Installation and functions of istSOS

istSOS has been installed in the server by following the [tutorial.](http://istsos.org/en/latest/doc/installation.html) After the installation you can try to load the istSOS by using your browser. In my case I couldn't open the istSOS. Then I have followed the step 7 which is mentioned in the [tutorial](http://istsos.org/en/latest/doc/installation.html). 

For the testing I have used [Arduino UNO Rev. 3](http://www.arduino.org/products/boards/arduino-uno) with [DHT11 sensor](https://www.adafruit.com/product/386). 

### Arduino UNO Rev. 3

Arduino is an open-source electronics platform based on easy-to-use hardware and software. Arduino boards are able to read inputs - light on a sensor, a finger on a button, or a Twitter message - and turn it into an output - activating a motor, turning on an LED, publishing something online. Arduino can be programmed with the [Arduino Software (IDE)](https://www.arduino.cc/en/Main/Software).

<img src="https://github.com/niroshansb/gsoc2017/blob/master/istSOS_test/img/arduino.jpg" width="300">

### DHT11 sensor

The DHT11 is a basic, ultra low-cost digital temperature and humidity sensor. It uses a capacitive humidity sensor and a thermistor to measure the surrounding air, and spits out a digital signal on the data pin (no analog input pins needed). Its fairly simple to use, but requires careful timing to grab data.

<img src="https://github.com/niroshansb/gsoc2017/blob/master/istSOS_test/img/dht11.jpg" width="300">

### Hardware and software setup

The DHT 11 module is connected to the Arduino Uno as shown in the below [image](https://github.com/niroshansb/gsoc2017/blob/master/istSOS_test/img/setup_hw_dht.png). The [dht11 module](https://github.com/niroshansb/gsoc2017/blob/master/istSOS_test/img/dht11.jpg) which I am using has 3 pins, those are VCC, Data and GND. VCC should connect with 5v pin, GND should connect with ground pin and the Data pin can connect with any any pin which you have defined in the [arduino code](https://github.com/niroshansb/gsoc2017/blob/master/istSOS_test/Arduino_dht11/Arduino_dht11.ino#L5) in my case it is A0.  

<img src="https://github.com/niroshansb/gsoc2017/blob/master/istSOS_test/img/setup_hw_dht.png" width="300"> 
