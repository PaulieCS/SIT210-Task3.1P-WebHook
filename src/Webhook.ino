// This #include statement was automatically added by the Particle IDE.
#include <Adafruit_DHT.h>

#define DHTPIN 2

#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

int led = D7;

void setup() {
    
    pinMode(led, OUTPUT);
    
    dht.begin();

}

void loop() {
    
    digitalWrite(led, HIGH);
    
    float h = dht.getHumidity();
    
    float t = dht.getTempCelcius();
    
    String temp = String(t);
    Particle.publish("Temperature", String(t), PRIVATE);
    Particle.publish("Humidity", String(h), PRIVATE);
	
    delay(30000);
    
    digitalWrite(led, LOW);
    delay(30000);
}