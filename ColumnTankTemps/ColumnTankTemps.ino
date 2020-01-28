#include <DallasTemperature.h>
#include <OneWire.h>
#include <LiquidCrystal_I2C.h>
// 28 FF 07 34 B1 16 05 31
// 28 FF 47 56 B1 16 03 92

DeviceAddress TermCol = { 0x28, 0xFF, 0x07, 0x34, 0xB1, 0x16, 0x05, 0x31 };
DeviceAddress TermTan = { 0x28, 0xFF, 0x47, 0x56, 0xB1, 0x16, 0x03, 0x92 };
 
OneWire oneWire(8);
DallasTemperature sensors(&oneWire);

LiquidCrystal_I2C lcd (0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

void setup() {
  
sensors.begin();
lcd.begin(16,2);
lcd.clear();

}


void loop() {
 sensors.requestTemperatures();

lcd.clear();
 lcd.setCursor(1, 0);
lcd.print("TCol  = ");
lcd.print(sensors.getTempC(TermCol));
 lcd.setCursor(1, 1);
lcd.print("TTank = ");
lcd.print(sensors.getTempC(TermTan));


}
