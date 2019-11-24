[TEMP POC]

int test = 7;
const int trigPin1 = 3;
const int echoPin1 = 2;
const int trigPin2 = 5;
const int echoPin2 = 4;
long duration1;
int distance1;
long duration2;
int distance2;


void setup() {
pinMode(6, OUTPUT);
pinMode(7, OUTPUT);
pinMode(A3, OUTPUT);
pinMode(A4, OUTPUT);
pinMode(trigPin1, OUTPUT);
pinMode(echoPin1, INPUT);
pinMode(trigPin2, OUTPUT);
pinMode(echoPin2, INPUT);
Serial.begin(9600);  
}


void loop() {
digitalWrite(trigPin1, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin1, LOW);
duration1 = pulseIn(echoPin1, HIGH);
distance1= duration1*0.034/2;
digitalWrite(trigPin2, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin2, LOW);
duration2 = pulseIn(echoPin2, HIGH);
distance2= duration2*0.034/2;
Serial.print("Distance: ");
Serial.print(distance1);
Serial.print(" / ");
Serial.println(distance2);  
digitalWrite(6, HIGH);
digitalWrite(7, HIGH);
analogWrite(A3, 255);
analogWrite(A4, 255);
delay(1000);
digitalWrite(6, LOW);
digitalWrite(7, LOW);
analogWrite(A3, LOW);
analogWrite(A4, LOW);  
delay(1000);
}
