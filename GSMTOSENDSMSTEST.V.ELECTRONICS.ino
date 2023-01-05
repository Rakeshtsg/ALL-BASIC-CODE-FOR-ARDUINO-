/*
  File: example.ino
  Author: Rakesh T S V.Electros Pvt Ltd
  Date: 9/6/2022
  Description: This code initializes the GSM connection and sends an SMS message to the specified phone number with the message "This is a test message from Arduino".
  You can customize the phone number and message to fit your needs.
*/
#include <GSM.h>

GSM gsm;
GSM_SMS sms;

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  // connection state
  boolean notConnected = true;

  // Start GSM shield
  // If your SIM has PIN, pass it as a parameter of begin() in quotes
  while (notConnected) {
    if (gsm.begin("YOUR_SIM_PIN") == GSM_READY) {
      notConnected = false;
    } else {
      Serial.println("Not connected");
      delay(1000);
    }
  }
  Serial.println("Connected to GSM network");
}

void loop() {
  // send the message
  sms.beginSMS("+1234567890");
  sms.print("This is a test message from Arduino");
  sms.endSMS();
  Serial.println("Message sent");
}
