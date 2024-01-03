/*
  Ultrasonic Sensor HC-SR04 



*/
#include <LiquidCrystal.h> // includes the LiquidCrystal Library
LiquidCrystal lcd(1, 2, 4, 5, 6, 7); // Creates an LCD object. Parameters: (rs, enable, d4, d5, d6, d7)
const int trigPin = 9;
const int echoPin = 10;

const int trigPin2 = 11;
const int echoPin2 = 12;

long duration;
long duration2;
int distanceCm, distanceInch, distanceCm2, distanceInch2;
void setup() {
  lcd.begin(16, 2); // Initializes the interface to the LCD screen, and specifies the dimensions (width and height) of the display

// ULTRASONIC 1
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  lcd.setCursor(0, 0); // Sets the location at which subsequent text written to the LCD will be displayed

// ULTRASONIC 2
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);

  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);


  // LIGHTS
  pinMode(51, OUTPUT); // Red Left
  pinMode(49, OUTPUT); // Green Left
  pinMode(45, OUTPUT); // Red Right
  pinMode(43, OUTPUT); // Green Right
}
void loop() {
/*
  digitalWrite(51, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(1000);                      // wait for a second
  digitalWrite(51, LOW);   // turn the LED off by making the voltage LOW

  digitalWrite(49, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(1000);                      // wait for a second
  digitalWrite(49, LOW);   // turn the LED off by making the voltage LOW

  digitalWrite(45, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(1000);                      // wait for a second
  digitalWrite(45, LOW);   // turn the LED off by making the voltage LOW

  digitalWrite(43, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(1000);                      // wait for a second
  digitalWrite(43, LOW);   // turn the LED off by making the voltage LOW
*/

  // ULTRASONIC DISTANCE 1
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distanceCm = duration * 0.034 / 2;
  distanceInch = duration * 0.0133 / 2;

  // ULTRASONIC DISTANCE 2
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);
  distanceCm2 = duration2 * 0.034 / 2;
  distanceInch2 = duration2 * 0.0133 / 2;
  lcd.setCursor(0, 1); // Sets the location at which subsequent text written to the LCD will be displayed

  //lcd.print(millis() / 1000);

  /*
  lcd.print("Distance: "); // Prints string "Distance" on the LCD
  lcd.print(distanceCm); // Prints the distance value from the sensor
  lcd.print(" cm");
  delay(10);
  lcd.setCursor(0, 1);
  lcd.print("Distance: ");
  lcd.print(distanceInch);
  lcd.print(" inch");
  delay(10);
*/


// IF statement for light control
lcd.print("WIN $100,000");
//lcd.print(distanceInch2);

if (distanceInch < 5) {
  //Recyclable Detected
  //Green Left light on
  //Red Right light on
  // Display text
  // wait 5 seconds
  // turn off all lights and return to normal
  lcd.clear();
  digitalWrite(49, HIGH); // Green Left ON
  digitalWrite(45, HIGH); // Red Right ON
  lcd.print("PLACE IN RECYCLE");
  delay(3000);

  int disVar;
  disVar = distanceCm2;
  String disVarString = String(disVar);
  lcd.clear();
if (disVar <=4){
    // RIGHT HOLE
  lcd.print("CORRECT");
  delay(3000);
  lcd.clear();
  lcd.print("[FACT] ####");
  


} else if (disVar >4) {
  // WRONG HOLE
  lcd.print("INCORRECT");
  delay(3000);
  lcd.clear();
  lcd.print("[FACT]");

}

  digitalWrite(49, LOW); // Green Left OFF
  digitalWrite(45, LOW); // Red Right OFF
  //lcd.print("[FACT] ####");
  delay(5000);
  lcd.clear();

} else if (distanceInch >= 5 && distanceInch < 10) {

  
  //Trash Detected
  //Green Right light on
  //Red Left light on
  // Display text
  // wait 5 seconds
  // turn off all lights and return to normal
  lcd.clear();
  digitalWrite(43, HIGH); // Green Right
  digitalWrite(51, HIGH); // Red Left
  lcd.print("PLACE IN TRASH");
  delay(3000);
  lcd.clear();
  // VARS for testing
  int disVar;
  disVar = distanceCm2;
  String disVarString = String(disVar);

if (disVar <=4){
  // WRONG HOLE
  lcd.print("INCORRECT");
  delay(3000);
  lcd.clear();
  lcd.print("[FACT]");
  


} else if (disVar >4) {
    // RIGHT HOLE
  lcd.print("CORRECT");
  delay(3000);
  lcd.clear();
  lcd.print("[FACT] ####");
 

}

  digitalWrite(43, LOW); // Green Left OFF
  digitalWrite(51, LOW); // Red Right OFF


  delay(5000);
  lcd.clear();

}

delay(1000);
  
  
}