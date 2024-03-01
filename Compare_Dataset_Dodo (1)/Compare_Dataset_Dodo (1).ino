//Compare_Datasets_dodo
const int analogPin = 26; // Analog pin to read data from
const int numSamples = 25; // Number of samples
const int sampleDelay = 100; // Delay between samples in milliseconds

// Variables to store collected dataset and predefined matrices
int collectedDataset[numSamples];
int d1[numSamples] = {542, 541, 518, 518, 525, 519, 515, 518, 559, 518, 520, 514, 530, 518, 519, 515, 524, 518, 516, 510, 520, 514, 518, 513, 522};
int d2[numSamples] = {548, 567, 504, 517, 515, 513, 518, 511, 508, 523, 520, 525, 516, 529, 187, 513, 515, 516, 527, 517, 525, 509, 513, 507, 516};

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
    Serial.println(" Saari Duniya Jalla Denge ");
  } else if (distance1 > distance2) {
    Serial.println(" Jamal Jamaloo ");
  } else {
    Serial.println(" both datasets are equally similar to the collected dataset ");
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
