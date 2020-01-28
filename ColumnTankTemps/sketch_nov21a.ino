const int startPin = 2;
const int endPin = 20;

#include <OneWire.h>

void setup()
{
  Serial.begin(115200);
  Serial.println("//\n// Start oneWireSearch.ino \n//");

  for (uint8_t pin = startPin; pin < endPin; pin++)
  {
    findDevices(pin);
  }
  Serial.println("\n//\n// End oneWireSearch.ino \n//");
}

void loop()
{
}

uint8_t findDevices(int pin)
{
  OneWire ow(pin);

  uint8_t address[8];
  uint8_t count = 0;


  if (ow.search(address))
  {
    Serial.print("\nuint8_t pin");
    Serial.print(pin, DEC);
    Serial.println("[][8] = {");
    do
    {
      count++;
      Serial.println("  {");
      for (uint8_t i = 0; i < 8; i++)
      {
        Serial.print("0x");
        if (address[i] < 0x10) Serial.print("0");
        Serial.print(address[i], HEX);
        if (i < 7) Serial.print(", ");
      }
      Serial.print("  },");
      // CHECK CRC
      if (ow.crc8(address, 7) == address[7])
      {
        Serial.println("\t\t// CRC OK");
      }
      else
      {
        Serial.println("\t\t// CRC FAILED");
      }
    } while (ow.search(address));

    Serial.println("};");
    Serial.print("// nr devices found: ");
    Serial.println(count);
  }

  return count;
}

