const int blinkSensorPin = 2;  // Pin connected to the eye-blink sensor
const int buzzerPin = 3;       // Pin connected to the buzzer
int blinkStatus = 0;
unsigned long closeStartTime = 0;
unsigned long blinkThreshold = 2000; // Time in milliseconds to consider drowsiness

void setup() {
  pinMode(blinkSensorPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  blinkStatus = digitalRead(blinkSensorPin);
  
  if (blinkStatus == LOW) { // Eyes closed
    if (closeStartTime == 0) {
      closeStartTime = millis();  // Record the time when eyes closed
    }
    
    // Check if eyes have been closed longer than threshold
    if (millis() - closeStartTime > blinkThreshold) {
      digitalWrite(buzzerPin, HIGH); // Sound the alarm
    }
  } 
  else { // Eyes open
    closeStartTime = 0;  // Reset the timer when eyes open
    digitalWrite(buzzerPin, LOW);  // Turn off alarm
  }
}
