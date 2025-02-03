.#define soilSensor A0  // Soil moisture sensor connected to A0
#define relayPin 7     // Relay module connected to pin 7
#define threshold 400  // Adjust threshold based on soil conditions

void setup() {
    Serial.begin(9600);
    pinMode(soilSensor, INPUT);
    pinMode(relayPin, OUTPUT);
    digitalWrite(relayPin, HIGH); // Keep pump off initially
}

void loop() {
    int moisture = analogRead(soilSensor);
    Serial.print("Soil Moisture: ");
    Serial.println(moisture);

    if (moisture > threshold) { // Dry soil
        digitalWrite(relayPin, LOW); // Turn pump ON
        Serial.println("Pump ON");
    } else { // Wet soil
        digitalWrite(relayPin, HIGH); // Turn pump OFF
        Serial.println("Pump OFF");
    }

    delay(2000); // Wait for 2 seconds before next reading
}
