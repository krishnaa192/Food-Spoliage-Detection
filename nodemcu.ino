/*************************************************************

  This is a simple demo of sending and receiving some data.
  Be sure to check out other examples!
 *************************************************************/
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <SoftwareSerial.h>

/* Fill-in information from Blynk Device Info here */
#define BLYNK_TEMPLATE_ID "TMPL3jTeLz_Kq"
#define BLYNK_TEMPLATE_NAME "Quickstart Template"
#define BLYNK_AUTH_TOKEN "YAs2rW4vZnT2ArZMohfn3w8wpwL6xUGi"

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial


//#include <ESP8266WiFi.h>
//#include <BlynkSimpleEsp8266.h>

// Your WiFi credentials.
// Set password to "" for open networks.

char auth[]= "YAs2rW4vZnT2ArZMohfn3w8wpwL6xUGi";
char ssid[] = "moto g32";
char pass[] = "Krishna121";

BlynkTimer timer;

String sdata; 


String  myString; // complete message from Arduino, which consists of sensors data
char rdata; // received characters

void myTimerEvent()
{
    Blynk.virtualWrite(V1, millis() / 1000);

}
void setup()
  {
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);

  timer.setInterval(1000L, sensorvalue1); 

}
void loop()
{
   if (Serial.available() == 0) 
   {
  Blynk.run();
  timer.run(); // Initiates BlynkTimer

   }
   
  if (Serial.available() > 0) 
  {
    rdata = Serial.read(); 
    myString = myString + rdata; 
  
  }

}

void sensorvalue1()
{
sdata = myString ;
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  Blynk.virtualWrite(V12, sdata);
   myString = "";


}

// This function is called every time the Virtual Pin 0 state changes
//BLYNK_WRITE(V0)
//{
  // Set incoming value from pin V0 to a variable
 // int value = param.asInt();

  // Update state
 // Blynk.virtualWrite(V1, value);
//}

// This function is called every time the device is connected to the Blynk.Cloud
//BLYNK_CONNECTED()
//{
  // Change Web Link Button message to "Congratulations!"
 // Blynk.setProperty(V3, "offImageUrl", "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations.png");
 // Blynk.setProperty(V3, "onImageUrl",  "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations_pressed.png");
 // Blynk.setProperty(V3, "url", "https://docs.blynk.io/en/getting-started/what-do-i-need-to-blynk/how-quickstart-device-was-made");
//}

// This function sends Arduino's uptime every second to Virtual Pin 2.
//void myTimerEvent()
//{
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
 // Blynk.virtualWrite(V2, millis() / 1000);
//}

//void setup()
//{
  // Debug console
 // Serial.begin(115200);

  //Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  // You can also specify server:
  //Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, "blynk.cloud", 80);
  //Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, IPAddress(192,168,1,100), 8080);

  // Setup a function to be called every second
 // timer.setInterval(1000L, myTimerEvent);
//}

//void loop()
//{
 // Blynk.run();
 // timer.run();
  // You can inject your own code or combine it with other sketches.
  // Check other examples on how to communicate with Blynk. Remember
  // to avoid delay() function!
//}
