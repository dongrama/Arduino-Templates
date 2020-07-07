#include <SoftwareSerial.h>
#include <String.h>

#define ledRX 2
#define ledTX 3
#define lineRX 4
#define lineTX 5
#define SERIAL_BD 115200

SoftwareSerial SoftSerial(lineRX, lineTX); // RX, TX
String tx;
String rx;

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  Serial.println("Hello! Serial is initializing...");

  SoftSerial.begin(SERIAL_BD);
  pinMode(ledRX, OUTPUT);
  pinMode(ledTX, OUTPUT);
  SoftSerial.println("ABC123");
  Serial.println("Done!");
}

void loop(){                                                         //
    if(SoftSerial.available()){    Serial.write(SoftSerial.read());} // Передаём данные из программной шины UART в аппаратную  (от модуля     через Arduino к компьютеру)
    if(    Serial.available()){SoftSerial.write(    Serial.read());} // Передаём данные из аппаратной  шины UART в программную (от компьютера через Arduino к модулю    )
}
