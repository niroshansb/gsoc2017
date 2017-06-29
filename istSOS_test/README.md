# Installation and functions of istSOS

istSOS has been installed in the server by following the [tutorial.](http://istsos.org/en/latest/doc/installation.html) After the installation you can try to load the istSOS by using your browser. In my case I couldn't open the istSOS. Then I have followed the step 7 which is mentioned in the [tutorial](http://istsos.org/en/latest/doc/installation.html). 

For the testing I have used [Arduino UNO Rev. 3](http://www.arduino.org/products/boards/arduino-uno) with [DHT11 sensor](https://www.adafruit.com/product/386). 

### Arduino UNO Rev. 3

Arduino is an open-source electronics platform based on easy-to-use hardware and software. Arduino boards are able to read inputs - light on a sensor, a finger on a button, or a Twitter message - and turn it into an output - activating a motor, turning on an LED, publishing something online. Arduino can be programmed with the [Arduino Software (IDE)](https://www.arduino.cc/en/Main/Software).

<img src="https://github.com/niroshansb/gsoc2017/blob/master/istSOS_test/img/arduino.jpg" width="200">

### DHT11 sensor

The DHT11 is a basic, ultra low-cost digital temperature and humidity sensor. It uses a capacitive humidity sensor and a thermistor to measure the surrounding air, and spits out a digital signal on the data pin (no analog input pins needed). Its fairly simple to use, but requires careful timing to grab data.

<img src="https://github.com/niroshansb/gsoc2017/blob/master/istSOS_test/img/dht11.jpg" width="200">

### Hardware and software setup

The DHT 11 module is connected to the Arduino Uno as shown in the below [image](https://github.com/niroshansb/gsoc2017/blob/master/istSOS_test/img/setup_hw_dht.png). The [dht11 module](https://github.com/niroshansb/gsoc2017/blob/master/istSOS_test/img/dht11.jpg) which I am using has 3 pins, those are VCC, Data and GND. VCC should connect with 5v pin, GND should connect with ground pin and the Data pin can connect with any any pin which you have defined in the [arduino code](https://github.com/niroshansb/gsoc2017/blob/master/istSOS_test/Arduino_dht11/Arduino_dht11.ino#L5) in my case it is A0.  

<img src="https://github.com/niroshansb/gsoc2017/blob/master/istSOS_test/img/setup_hw_dht.png" width="350"> 

<img src="https://github.com/niroshansb/gsoc2017/blob/master/istSOS_test/img/setup_hw.png" width="300"> 

After setup the hardware you can connect the Arduino to PC and upload the [codes](https://github.com/niroshansb/gsoc2017/blob/master/istSOS_test/Arduino_dht11/Arduino_dht11.ino) to Arduino. If it is succussfully done you will be able to see the data through Arduino IDE serial monitor. 

<img src="https://github.com/niroshansb/gsoc2017/blob/master/istSOS_test/img/readings.png" width="300"> 

## Data acquisition

First let’s create a new arduino sensor in istSOS

* Add procedure arduino with multiple observed properties

        Name :  arduino_test
        Description : Arduino with istSOS test
        Keywords : arduino,air,temperature,humidity
        
        System type : insitu-fixed-point 
        Sensor type : DHT11
        
        FOI name : OCU
        EPSG : 4326
        Coordinates : x: 135.5041993 y: 34.592802 z: 24
        
        Outputs :
          Observed property : urn:ogc:def:parameter:x-istsos:1.0:meteo:air:humidity:relative 
          Unit of measure : %
          Observed property : urn:ogc:def:parameter:x-istsos:1.0:meteo:air:temperature 
          Unit of measure : °C

Register the new sensor (procedure) pressing the "submit " button

Once you done this successfully, now you can read the data coming from arduino and upload them to istSOS.
In order to do that, 
First you need to create a json file in the file config format. 
              
               Example 
                 {
                    "url": "http://istsos.org/istsos",
                     "service": "demo",
                      "port": "/dev/ttyACM0",
                      "baud": "9600",
                      "procedure": "arduino",
                      "datetime": {
                          "date": {
                             "column": 4,
                             "format": "%m/%d/%Y"
                           },
                            "time": {
                              "column": 5,
                              "format": "%H:%M:%S"
                           },
                           "tz": "+01:00"
                        },
                           "observations": [{
                           "name": "urn:ogc:def:parameter:x-istsos:1.0:meteo:air:humidity:relative",
                             "column": 13,
                             "nodata": -1
                       },{
                           "name": "urn:ogc:def:parameter:x­istsos:1.0:meteo:air:temperature",
                             "column": 14
                               }]
                   }

In my test the json I named as [arduino.json](https://github.com/niroshansb/gsoc2017/blob/master/istSOS_test/arduino.json).

Then you can find the <b> serial2istsos.py </b> file in the script folder of istSOS.
By using them you can read data from the a serial output and send data in real time to istSOS using the WA-REST API.

First you have to Close the Arduino IDE “Serial Monitor” if still opened.
Then you can execute script as follows: 

            In the istSOS directory;
            cd /usr/share/istsos
                run the following command in the terminal;
            python scripts/serial2istsos.py -v -c /home/niroshan/Desktop/test/arduino.json
            
Then you will see as follows in your terminal 

<img src="https://github.com/niroshansb/gsoc2017/blob/master/istSOS_test/img/data_adding.png" width="500"> 

Now you can check your data in the “Data Viewer”

Humidity 

<img src="https://github.com/niroshansb/gsoc2017/blob/master/istSOS_test/img/humidity.png" width="500">

Temperature 

<img src="https://github.com/niroshansb/gsoc2017/blob/master/istSOS_test/img/temperature.png" width="500">
