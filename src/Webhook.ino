// This #include statement was automatically added by the Particle IDE.
#include <Adafruit_DHT.h>

#define DHTPIN D2

#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

void setup() {
    
    dht.begin();

}

void loop() {
    
    float t = dht.getTempCelcius();
    
    Particle.publish("Temperature", String(t), PRIVATE);

    delay(30000);
}