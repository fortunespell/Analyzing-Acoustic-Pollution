const int analogPin = 26;  // Analog pin 26 to read Mic data from dodo v1.0
const int numDatasets = 5; // Number of datasets
const int numSamples = 25;  // Number of samples per dataset
const int sampleDelay = 1000; // Delay between samples in milliseconds
const int datasetDelay = 5000; // Delay between datasets in milliseconds

int datasets[numDatasets][numSamples];

void setup() {
  Serial.begin(9600);  
}

void loop() {
  
  for (int datasetIndex = 0; datasetIndex < numDatasets; ++datasetIndex) {
    // Collect dataset
    collectDataset(datasets[datasetIndex], numSamples);

    // Output collected dataset
    outputDataset("Dataset " + String(datasetIndex + 1) + ":", datasets[datasetIndex], numSamples);

    // Delay between datasets
    delay(datasetDelay);
  }

  // Stop further execution
  while (true) {
    // Do nothing
  }
}

void collectDataset(int dataset[], int numSamples) {
  Serial.println("Collecting dataset...");
  for (int i = 0; i < numSamples; ++i) {
    // Read analog data
    int sensorValue = analogRead(analogPin);

    // Store data in the dataset
    dataset[i] = sensorValue;

    // Wait for the next sample interval
    delay(sampleDelay);
  }
}

void outputDataset(const String& label, int dataset[], int numSamples) {
  Serial.println(label);
  for (int i = 0; i < numSamples; ++i) {
    Serial.print(dataset[i]);
    Serial.print("\t");
  }
  Serial.println();
  Serial.println();
}
