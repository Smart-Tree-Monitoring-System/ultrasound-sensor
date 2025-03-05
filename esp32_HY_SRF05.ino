#define TRIG_PIN 8    // Connect pin Trig with pin 8
#define ECHO_PIN 7    // Connect pib Echo with pin 7
#define TIME_OUT 5000 // Time_out of pulseIn is 5000 microsecond

 // Fuction to calculate distance
float getDistance()
{
  long duration, distanceCm;
  //Generate a 10uS pulse from the Trig pin 
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  //The time it takes for the signal to respond to the Echo pin
  duration = pulseIn(ECHO_PIN, HIGH, TIME_OUT);
 
  //Calculate distance
  distanceCm = duration / 29.1 / 2;
  // Return result
  return distanceCm;
}
 
void setup() {  
  Serial.begin(9600);
 
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}
 
void loop() {
  // Call getDistance
  long distance = getDistance();
 
  if (distance <= 0)
  {
    Serial.println("Echo time out !!"); // if the response time exceeds the Time_out of the pulseIn function
  }
  else
  {
    //Display measured distance on Serial Monitor   
    Serial.print("Distance to nearest obstacle (cm): ");
    Serial.println(distance);
  }
  //Wait for 1 second to repeat 
  delay(1000);
}
