const int analogInputPin = 26;  // Mic input for audio signal
const int threshold = 512;     // Adjust this threshold based on your audio signal

volatile int crossings = 0;
volatile unsigned long startTime = 0;

void setup() {
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(analogInputPin), zeroCrossing, RISING);
}

void loop() {
  if (millis() - startTime >= 1000) {  // Print frequency every second
    detachInterrupt(digitalPinToInterrupt(analogInputPin));
    
    // Calculate frequency based on zero crossings
    float frequency = crossings;
    Serial.print("Frequency: ");
    Serial.print(frequency);
    Serial.println(" Hz");

    // Reset variables
    crossings = 0;
    startTime = millis();
    
    attachInterrupt(digitalPinToInterrupt(analogInputPin), zeroCrossing, RISING);
  }
}

void zeroCrossing() {
  crossings++;
}
