//  // ------------------- Pin Definitions -------------------
// #define LDR_PIN A0           // LDR analog pin
// #define TRIG_LEFT 4          // Left ultrasonic sensor TRIG
// #define ECHO_LEFT 5          // Left ultrasonic sensor ECHO
// #define TRIG_RIGHT 2         // Right ultrasonic sensor TRIG
// #define ECHO_RIGHT 3         // Right ultrasonic sensor ECHO

// int leds[] = {6, 7, 8, 9, 10, 11, 12, 13, A1};  // 9 LEDs
// int ledCount = 9;

// // ------------------- Thresholds -------------------
// const int LIGHT_THRESHOLD = 500;   // LDR threshold (adjust as needed)
// const int DISTANCE_THRESHOLD = 10; // Distance in cm to trigger LEDs

// // ------------------- Helper Functions -------------------
// long getDistance(int trigPin, int echoPin) {
//   digitalWrite(trigPin, LOW);
//   delayMicroseconds(2);
//   digitalWrite(trigPin, HIGH);
//   delayMicroseconds(10);
//   digitalWrite(trigPin, LOW);
//   long duration = pulseIn(echoPin, HIGH, 20000);
//   long distance = duration * 0.034 / 2;
//   return distance;
// }

// void turnOffAll() {
//   for (int i = 0; i < ledCount; i++) {
//     digitalWrite(leds[i], LOW);
//   }
// }

// void sequenceLeftToRight() {
//   for (int i = 0; i < ledCount; i++) {
//     digitalWrite(leds[i], HIGH);
//     delay(1000);
//   }
//   delay(2000);
//   for (int i = 0; i < ledCount; i++) {
//     digitalWrite(leds[i], LOW);
//     delay(1000);
//   }
// }

// void sequenceRightToLeft() {
//   for (int i = ledCount - 1; i >= 0; i--) {
//     digitalWrite(leds[i], HIGH);
//     delay(1000);
//   }
//   delay(2000);
//   for (int i = ledCount - 1; i >= 0; i--) {
//     digitalWrite(leds[i], LOW);
//     delay(1000);
//   }
// }

// void sequenceBothSides() {
//   // On both directions
//   for (int i = 0; i < ledCount; i++) {
//     digitalWrite(leds[i], HIGH);
//     delay(1000);
//   }
//   delay(2000);
//   // Off both directions
//   for (int i = 0; i < ledCount; i++) {
//     digitalWrite(leds[i], LOW);
//     delay(1000);
//   }
// }

// // ------------------- Setup -------------------
// void setup() {
//   Serial.begin(9600);
//   pinMode(LDR_PIN, INPUT);
//   pinMode(TRIG_LEFT, OUTPUT);
//   pinMode(ECHO_LEFT, INPUT);
//   pinMode(TRIG_RIGHT, OUTPUT);
//   pinMode(ECHO_RIGHT, INPUT);
  
//   for (int i = 0; i < ledCount; i++) {
//     pinMode(leds[i], OUTPUT);
//   }
  
//   turnOffAll();
// }

// // ------------------- Main Loop -------------------
// void loop() {
//   int ldrValue = analogRead(LDR_PIN);
//   ldrValue = 600;
//  // Serial.print("LDR: "); Serial.println(ldrValue);
//     long leftDistance = getDistance(TRIG_LEFT, ECHO_LEFT);
//     long rightDistance = getDistance(TRIG_RIGHT, ECHO_RIGHT);
    
//     Serial.print("Left: "); Serial.print(leftDistance);
//     Serial.print("  Right: "); Serial.println(rightDistance);

//   if (ldrValue < LIGHT_THRESHOLD) {
//     // Daytime
//     turnOffAll();
//   } else {
//     // Nighttime
//     // long leftDistance = getDistance(TRIG_LEFT, ECHO_LEFT);
//     // long rightDistance = getDistance(TRIG_RIGHT, ECHO_RIGHT);
    
//     // Serial.print("Left: "); Serial.print(leftDistance);
//     // Serial.print("  Right: "); Serial.println(rightDistance);

//     if (leftDistance < DISTANCE_THRESHOLD && rightDistance < DISTANCE_THRESHOLD) {
//       sequenceBothSides();
//     } else if (leftDistance < DISTANCE_THRESHOLD) {
//       sequenceLeftToRight();
//     } else if (rightDistance < DISTANCE_THRESHOLD) {
//       sequenceRightToLeft();
//     } else {
//       turnOffAll();
//     }
//   }

//   delay(200);
// }

// ------------------- Pin Definitions -------------------
#define LDR_PIN A0           // LDR analog pin
#define TRIG_LEFT 4          // Left ultrasonic sensor TRIG
#define ECHO_LEFT 5          // Left ultrasonic sensor ECHO
#define TRIG_RIGHT 2         // Right ultrasonic sensor TRIG
#define ECHO_RIGHT 3         // Right ultrasonic sensor ECHO

int leds[] = {6, 7, 8, 9, 10, 11, 12, 13, A1};  // 9 LEDs
int ledCount = 9;

// ------------------- Thresholds -------------------
const int LIGHT_THRESHOLD = 500;   // LDR threshold (adjust based on environment)
const int DISTANCE_THRESHOLD = 10; // Distance in cm to trigger LEDs

// ------------------- Helper Functions -------------------
long getDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH, 25000);  // 25 ms timeout
  if (duration == 0) return 999;                  // no echo
  return duration * 0.034 / 2;                    // convert to cm
}

void turnOffAll() {
  for (int i = 0; i < ledCount; i++) {
    digitalWrite(leds[i], LOW);
  }
}

void sequenceLeftToRight() {
  for (int i = 0; i < ledCount; i++) {
    digitalWrite(leds[i], HIGH);
    delay(300);
  }
   delay(2000);
  for (int i = 0; i < ledCount; i++) {
    digitalWrite(leds[i], LOW);
    delay(150);
  }
}

void sequenceRightToLeft() {
  for (int i = ledCount - 1; i >= 0; i--) {
    digitalWrite(leds[i], HIGH);
    delay(150);
  }
  delay(500);
  for (int i = ledCount - 1; i >= 0; i--) {
    digitalWrite(leds[i], LOW);
    delay(150);
  }
}

void sequenceBothSides() {
  for (int i = 0; i < ledCount; i++) {
    digitalWrite(leds[i], HIGH);
    delay(100);
  }
  delay(500);
  for (int i = 0; i < ledCount; i++) {
    digitalWrite(leds[i], LOW);
    delay(100);
  }
}

// ------------------- Setup -------------------
void setup() {
  Serial.begin(9600);
  pinMode(LDR_PIN, INPUT);

  pinMode(TRIG_LEFT, OUTPUT);
  pinMode(ECHO_LEFT, INPUT);
  pinMode(TRIG_RIGHT, OUTPUT);
  pinMode(ECHO_RIGHT, INPUT);

  for (int i = 0; i < ledCount; i++) {
    pinMode(leds[i], OUTPUT);
  }

  turnOffAll();
  Serial.println("System Ready");
}

// ------------------- Main Loop -------------------
void loop() {
  int ldrValue = analogRead(LDR_PIN);
  ldrValue = 600;
  // Read sensors one at a time (to avoid ultrasonic interference)
  long leftDistance = getDistance(TRIG_LEFT, ECHO_LEFT);
  delay(150);  // let echoes settle
  long rightDistance = getDistance(TRIG_RIGHT, ECHO_RIGHT);

 
  // Debugging output
  Serial.print("LDR: "); Serial.print(ldrValue);
  Serial.print(" | Left: "); Serial.print(leftDistance);
  Serial.print(" cm | Right: "); Serial.print(rightDistance);
  Serial.println(" cm");
   rightDistance = 400;

  // ------------------- Day/Night Logic -------------------
  if (ldrValue < LIGHT_THRESHOLD) {
    // Daytime → turn off all lights
    turnOffAll();
  } else {
    // Nighttime
    if (leftDistance < DISTANCE_THRESHOLD && rightDistance < DISTANCE_THRESHOLD) {
      sequenceBothSides();
    } 
    else if (leftDistance < DISTANCE_THRESHOLD) {
      sequenceLeftToRight();
    } 
    else if (rightDistance < DISTANCE_THRESHOLD) {
      sequenceRightToLeft();
    } 
    else {
      turnOffAll();
    }
  }

  delay(200);
}
