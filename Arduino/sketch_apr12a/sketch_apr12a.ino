#include <SPI.h>
#include <Ethernet.h>
byte mac[]= { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};
byte ip[] = { 10,0,0,177};
void setup() {
  // put your setup code here, to run once:
Ethernet.begin(mac,ip);
}

void loop() {
  // put your main code here, to run repeatedly:

}
