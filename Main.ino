/*
// /////////////////////////////////////////////////////////////////////// COPYRIGHT NOTICE
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// You should have received a copy of the GNU General Public License
// along with Pip-Project.  If not, see <http://www.gnu.org/licenses/>.
// /////////////////////////////////////////////////////////////////////// COPYRIGHT NOTICE
// /////////////////////////////////////////////////////////////////////// VERSION CONTROL
// PAGE CREATED BY: Phillip Kraguljac
// PAGE CREATED DATE: 2019-07-20
// DATE       || NAME           || MODIFICATION
// 2019-11-24   || Phillip Kraguljac    || Created.
// 2019-11-25   || Phillip Kraguljac    || v1.0.
// /////////////////////////////////////////////////////////////////////// VERSION CONTROL
*/


// /////////////////////////////////////////////////////////////////////// USER DEFINABLE VARIABLES
float Zone_1_Distance = 0; // IGNORE ZONE
float Zone_2_Distance = 200; // REQUIRES ADJUSTMENT
float Zone_3_Distance = 300; // CORRECT DISTANCE
float Zone_4_Distance = 310; // CORRECT DISTANCE
float Zone_5_Distance = 400; // REQURIES ADJUSTMENT
float Zone_6_Distance = 500; // IGNORE ZONE

// /////////////////////////////////////////////////////////////////////// SYSTEM VARIABLES
int Sensor_Trigger_1 = 3;                                                          // Ultra sonic sensor trigger pin.
int Sensor_Echo_1 = 2;                                                             // Unltra sonic sensor echo pin.
int Sensor_Trigger_2 = 5;                                                          // Ultra sonic sensor trigger pin.
int Sensor_Echo_2 = 4;                                                             // Unltra sonic sensor echo pin.

float Sensor_Distance_1 = 0;
float Sensor_Distance_2 = 0;




float Allowable_Range = 10; 

String Indicator_Output = "";


bool Flash_Fast_Flag = false;                                                       // ...
int Flash_Indexer = 0;                                                              // ...
int Flash_Fast_Cycles = 20;                                                         // ...
bool Flash_Sensor_1_Flag = false;
int Flash_Sensor_1_Index = false;
int Flash_Sensor_2_Index = false;
//int Flash_Sensor_1_Cycles = 10;                                                         // ...



//ZONE 1 - OFF
//ZONE 2 - WARNING
//ZONE 3 - TARGET
//ZONE 4 - TARGET
//ZONE 5 - WARNING
//ZONE 6 - OFF
//ZONE 7 - OFF
//ZONE 8 - WARNING
//ZONE 9 - TARGET
//ZONE 10 - WARNING
//ZONE 11 - OFF









void setup() {

Serial.begin (9600);                                                                // Start serial @ BAUD.
pinMode(LED_BUILTIN, OUTPUT);                                                       // Declare IO's.
pinMode(Sensor_Trigger_1, OUTPUT);                                                 // Initiate US trigger pin.
pinMode(Sensor_Echo_1, INPUT);                                                     // Initiate US echo pin.
pinMode(Sensor_Trigger_2, OUTPUT);                                                 // Initiate US trigger pin.
pinMode(Sensor_Echo_2, INPUT);                                                     // Initiate US echo pin.

pinMode(6, OUTPUT);
pinMode(7, OUTPUT);
pinMode(A3, OUTPUT);
pinMode(A4, OUTPUT);








}


void loop() {
//Override_Flag = digitalRead(Override_Switch);                                     // Removed for this application.

//float Zone_1_Distance = 0;
//float Zone_2_Distance = 150;
//float Zone_3_Distance = 200;
//float Zone_3_Distance = 250;
//float Zone_4_Distance = 300;
//float Zone_5_Distance = 0;

Flash_Operation();                                                                  // ...

//Flash_Operation_Direction();

Sensor_Distance_1 = Scan_Sensor(Sensor_Trigger_1, Sensor_Echo_1);
Sensor_Distance_2 = Scan_Sensor(Sensor_Trigger_2, Sensor_Echo_2);

if(Sensor_Distance_1 > Zone_1_Distance && Sensor_Distance_1 < Zone_2_Distance){Indicator_Output = "Right - Zone 1-2";}
if(Sensor_Distance_1 > Zone_2_Distance && Sensor_Distance_1 < Zone_3_Distance){Indicator_Output = "Right - Zone 2-3";}
if(Sensor_Distance_1 > Zone_3_Distance && Sensor_Distance_1 < Zone_4_Distance){Indicator_Output = "Right - Zone 3-4";}
if(Sensor_Distance_1 > Zone_4_Distance && Sensor_Distance_1 < Zone_5_Distance){Indicator_Output = "Right - Zone 4-5";}
if(Sensor_Distance_1 > Zone_5_Distance && Sensor_Distance_1 < Zone_6_Distance){Indicator_Output = "Right - Zone 5-6";}




//if(Sensor_Distance_1>Lower_Limit&&Sensor_Distance_1<Upper_Limit){
//  Indicator_Output = "Right - Target";
//  Serial.print("T");
//}
//if(Sensor_Distance_1>Upper_Limit){
//  Indicator_Output = "Right - Outside";
//}



Serial.print("Distance: ");
Serial.print(Sensor_Distance_1);
Serial.print(" / ");
Serial.print(Sensor_Distance_2);  
Serial.println(" / ");
//Serial.println(Upper_Limit);


//digitalWrite(6, HIGH);
//digitalWrite(7, HIGH);
//analogWrite(A3, 255);
//analogWrite(A4, 255);
//delay(1000);
//digitalWrite(6, LOW);
//digitalWrite(7, LOW);
//analogWrite(A3, LOW);
//analogWrite(A4, LOW);  
//delay(1000);



if(Indicator_Output == "Right - Zone 1-2"){
digitalWrite(6, LOW);
digitalWrite(7, LOW);
}

if(Indicator_Output == "Right - Zone 2-3"){
digitalWrite(6, HIGH);
digitalWrite(7, LOW);
}

if(Indicator_Output == "Right - Zone 3-4"){
digitalWrite(6, HIGH);
digitalWrite(7, HIGH);
}

if(Indicator_Output == "Right - Zone 4-5"){
digitalWrite(6, LOW);
digitalWrite(7, HIGH);
}

if(Indicator_Output == "Right - Zone 5-6"){
digitalWrite(6, LOW);
digitalWrite(7, LOW);
}


delay(50);                                                                        // Base cycle throttle. [Do not remove!]
}




// ///////////////////////////////////////////////////////////////// FUNCTION(S)

// [FUNCTION] => FLASH FUNCTIONS
void Flash_Operation(){
if(Flash_Indexer < Flash_Fast_Cycles){Flash_Indexer=Flash_Indexer+1;}               // ...
if(Flash_Indexer >= Flash_Fast_Cycles){                                             // ...
Flash_Indexer = 0;                                                                  // ...
if(Flash_Fast_Flag == true){Flash_Fast_Flag = false;}else{Flash_Fast_Flag = true;}  // ...
}                                                                                   // ...
}                                                                                   // ...


//void Flash_Operation_Direction(){
//float Ratio_1 = (Sensor_Distance_1 - Zone_2_Distance) / (Zone_3_Distance - Zone_2_Distance);
//int Flash_Sensor_1_Cycles = 20.0f * (1-Ratio_1);
//  Serial.print("-");  
//Serial.print(Flash_Sensor_1_Cycles);
//  Serial.print("-");
//if(Flash_Sensor_1_Index < Flash_Sensor_1_Cycles){Flash_Sensor_1_Index = Flash_Sensor_1_Index+1;}               // ...
//if(Flash_Sensor_1_Index >= Flash_Sensor_1_Cycles){                                             // ...
//Flash_Sensor_1_Index = 0;                                                                  // ...
//if(Flash_Sensor_1_Flag == true){Flash_Sensor_1_Flag = false;}else{Flash_Sensor_1_Flag = true;}  // ...
//}                                                                                   // ...
//
//}



// [FUNCTION] => OBTAING DISTANCE FROM ULTRASONIC SENSORS (RAW PULSES)
float Scan_Sensor(int Sensor_Trigger, int Sensor_Echo){
float Sensor_Duration = 0;                                                          // Value retrieved from sensor.
float Sensor_mm = 0;                                                                // Converted measurement.
digitalWrite(Sensor_Trigger, LOW);                                                  // Set output LOW.
delayMicroseconds(5);                                                               // Wait clearance time.
digitalWrite(Sensor_Trigger, HIGH);                                                 // Set output HIGH.
delayMicroseconds(10);                                                              // Sending input trigger.
digitalWrite(Sensor_Trigger, LOW);                                                  // Set output LOW.
pinMode(Sensor_Echo, INPUT);                                                        
Sensor_Duration =  pulseIn(Sensor_Echo, HIGH);                                      // Retrieve HCSR04 feedback.                                                        // Sending input trigger.
Sensor_mm = (Sensor_Duration/2.9)/2;                                                // Convert to cm.
delayMicroseconds(10);                                                              // Apply reading buffer.
Sensor_mm = Sensor_mm + 70;                                                         // Apply sensor offeset to rail.
return Sensor_mm;                                                                   // Return value.
}


