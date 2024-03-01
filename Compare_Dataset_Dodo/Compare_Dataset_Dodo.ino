//Compare_Datasets_dodo
const int analogPin = 26; // Analog pin to read data from
const int numSamples = 25; // Number of samples
const int sampleDelay = 100; // Delay between samples in milliseconds

// Variables to store collected dataset and predefined matrices
int collectedDataset[numSamples];
int d1[numSamples] = {512, 541, 590, 617, 478, 588, 502, 553, 710, 427, 436, 548, 498, 535, 634, 504, 574, 533, 541, 561, 418, 510, 504, 446, 477};
int d2[numSamples] = {614, 513, 519, 501, 536, 528, 510, 512, 519, 523, 480, 490, 525, 497, 502, 456, 475, 582, 509, 519, 517, 537, 477, 531, 514};

void setup() {
  Serial.begin(9600);
  Serial.println(" Starting... ");
}

void loop() {
  // Collect dataset from analog pin
  collectDataset(collectedDataset, numSamples);

  // Compare collected dataset with predefined matrices
  float distance1 = computeEuclideanDistance(collectedDataset, d1, numSamples);
  float distance2 = computeEuclideanDistance(collectedDataset, d2, numSamples);

  // Predict which matrix is more similar
  if (distance1 < distance2) {
    Serial.println(" High Noise ");
  } else if (distance1 > distance2) {
    Serial.println(" Normal Environment ");
  } else {
    Serial.println(" Regular Conversation ");
  }

  // Stop further execution
  while (true) {
    // Do nothing
  }
}

void collectDataset(int dataset[], int numSamples) {
  for (int i = 0; i < numSamples; ++i) {
    // Read analog data
    int sensorValue = analogRead(analogPin);

    // Store data in the dataset
    dataset[i] = sensorValue;

    // Wait for the next sample interval
    delay(sampleDelay);
  }
}

float computeEuclideanDistance(const int dataset1[], const int dataset2[], int numSamples) {
  // Compute Euclidean distance between two datasets
  float sumSquaredDiff = 0.0;
  for (int i = 0; i < numSamples; ++i) {
    float diff = dataset1[i] - dataset2[i];
    sumSquaredDiff += diff * diff;
  }
  return sqrt(sumSquaredDiff);
}
