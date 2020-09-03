const int trigP = 2;  //D4 Or GPIO-2 of nodemcu
const int echoP = 0;  //D3 Or GPIO-0 of nodemcu
const int relay = 12; // D6 or GPIO-12 of nodemcu
long duration;
int distance;

void setup() {
pinMode(trigP, OUTPUT);  // Sets the trigPin as an Output
pinMode(echoP, INPUT);   // Sets the echoPin as an Input
pinMode(relay, OUTPUT);
Serial.begin(9600);      // Open serial channel at 9600 baud rate
}

void loop() {

digitalWrite(trigP, LOW);   // Makes trigPin low
delayMicroseconds(2);       // 2 micro second delay 

digitalWrite(trigP, HIGH);  // tigPin high
delayMicroseconds(10);      // trigPin high for 10 micro seconds
digitalWrite(trigP, LOW);   // trigPin low

duration = pulseIn(echoP, HIGH);   //Read echo pin, time in microseconds
distance= duration*0.034/2;        //Calculating actual/real distance

Serial.print("Distance = ");        //Output distance on arduino serial monitor 
Serial.println(distance);
                          //Pause for 3 seconds and start measuring distance again


if (distance < 10){ 
    digitalWrite(relay, LOW);
    Serial.print("Distance = ");
    Serial.println(distance);  
  }   
else 
    digitalWrite(relay, HIGH);  
    Serial.print("Distance = ");
    Serial.println(distance);   
} 
