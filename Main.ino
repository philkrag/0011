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
// 2019-11-25   || Phillip Kraguljac    || v1.0
// 2019-11-26   || Phillip Kraguljac    || v1.1
// 2019-12-30   || Phillip Kraguljac    || v1.2

// /////////////////////////////////////////////////////////////////////// VERSION CONTROL
*/


// /////////////////////////////////////////////////////////////////////// USER DEFINABLE VARIABLES

float Allowable_Target_Margin = 10;                                               // ...
float Direction_Zone = 100;                                                       // ...
float Set_Distance_Depth_1 = 200;                                                 // ...
float Set_Distance_Depth_2 = 800;                                                 // ...
float Set_Distance_Depth_3 = 1800;                                                // ...
float Sensor_Offset_1 = -23;                                                      // Controller Side
float Sensor_Offset_2 = -23;
int const Scan_Accuracy = 10;                                                       // Total samples taken for each measurement.


// /////////////////////////////////////////////////////////////////////// SYSTEM VARIABLES
int Sensor_Trigger_1 = 3;                                                         // Ultra sonic sensor trigger pin.
int Sensor_Echo_1 = 2;                                                            // Unltra sonic sensor echo pin.
int Sensor_Trigger_2 = 5;                                                         // Ultra sonic sensor trigger pin.
int Sensor_Echo_2 = 4;                                                            // Unltra sonic sensor echo pin.
int Right_LED_A = 7;                                                              // Controller Side
int Right_LED_S = 6;                                                              // Controller Side
int Left_LED_A = A3;                                                              // ...
int Left_LED_S = A4;                                                              // ...

float Sensor_Distance_1 = 0;                                                      // ...
float Sensor_Distance_2 = 0;                                                      // ...

float Zone_1_Distance = Set_Distance_Depth_1 - Direction_Zone;                    // ...
float Zone_2_Distance = Set_Distance_Depth_1 - (Allowable_Target_Margin/2);       // ...
float Zone_3_Distance = Set_Distance_Depth_1 + (Allowable_Target_Margin/2);       // ...
float Zone_4_Distance = Set_Distance_Depth_1 + Direction_Zone;                    // ...

float Zone_5_Distance = Set_Distance_Depth_2 - Direction_Zone;                    // ...
float Zone_6_Distance = Set_Distance_Depth_2 - (Allowable_Target_Margin/2);       // ...
float Zone_7_Distance = Set_Distance_Depth_2 + (Allowable_Target_Margin/2);       // ...
float Zone_8_Distance = Set_Distance_Depth_2 + Direction_Zone;                    // ...

float Zone_9_Distance = Set_Distance_Depth_3 - Direction_Zone;                    // ...
float Zone_10_Distance = Set_Distance_Depth_3 - ((Allowable_Target_Margin/2)*1.2);      // ...
float Zone_11_Distance = Set_Distance_Depth_3 + ((Allowable_Target_Margin/2)*1.2);      // ...
float Zone_12_Distance = Set_Distance_Depth_3 + Direction_Zone;                   // ...

bool Out_Side_Zones_Left = false;                                                 // ...
bool Out_Side_Zones_Right = false;                                                // ...
String Indicator_Output_Left = "";                                                // ...
String Indicator_Output_Right = "";                                               // ...


void setup() {                                                                    // ...
Serial.begin (9600);                                                              // Start serial @ BAUD.
pinMode(LED_BUILTIN, OUTPUT);                                                     // Declare IO's.
pinMode(Sensor_Trigger_1, OUTPUT);                                                // Initiate US trigger pin.
pinMode(Sensor_Echo_1, INPUT);                                                    // Initiate US echo pin.
pinMode(Sensor_Trigger_2, OUTPUT);                                                // Initiate US trigger pin.
pinMode(Sensor_Echo_2, INPUT);                                                    // Initiate US echo pin.
pinMode(Right_LED_A, OUTPUT);                                                     // ...
pinMode(Right_LED_S, OUTPUT);                                                     // ...
pinMode(Left_LED_A, OUTPUT);                                                      // ...
pinMode(Left_LED_S, OUTPUT);                                                      // ...
}


void loop() {                                                                     // ...
//Override_Flag = digitalRead(Override_Switch);                                   // Removed for this application.

Out_Side_Zones_Right = false;                                                     // ...
Out_Side_Zones_Left = false;                                                      // ...

Sensor_Distance_1 = Scan_Sensor(Sensor_Trigger_1, Sensor_Echo_1) + Sensor_Offset_1;                 // ...
delay(50);                                                                        // ...
Sensor_Distance_2 = Scan_Sensor(Sensor_Trigger_2, Sensor_Echo_2) + Sensor_Offset_2;                 // ...
delay(50);                                                                        // ...

if(Sensor_Distance_1 > Zone_1_Distance && Sensor_Distance_1 < Zone_2_Distance){   // ...
Indicator_Output_Right = "RIGHT (+)";                                             // ...
Out_Side_Zones_Right = true;                                                      // ...
}                                                                                 // ...

if(Sensor_Distance_1 > Zone_2_Distance && Sensor_Distance_1 < Zone_3_Distance){   // ...
Indicator_Output_Right = "RIGHT (ALIGNED)";                                       // ...
Out_Side_Zones_Right = true;                                                      // ...
}                                                                                 // ...

if(Sensor_Distance_1 > Zone_3_Distance && Sensor_Distance_1 < Zone_4_Distance){   // ...
Indicator_Output_Right = "RIGHT (-)";                                             // ...
Out_Side_Zones_Right = true;                                                      // ...
}                                                                                 // ...

if(Sensor_Distance_1 > Zone_5_Distance && Sensor_Distance_1 < Zone_6_Distance){   // ...
Indicator_Output_Right = "RIGHT (+)";                                             // ...
Out_Side_Zones_Right = true;                                                      // ...
}                                                                                 // ...

if(Sensor_Distance_1 > Zone_6_Distance && Sensor_Distance_1 < Zone_7_Distance){   // ...
Indicator_Output_Right = "RIGHT (ALIGNED)";                                       // ...
Out_Side_Zones_Right = true;                                                      // ...
}                                                                                 // ...

if(Sensor_Distance_1 > Zone_7_Distance && Sensor_Distance_1 < Zone_8_Distance){   // ...
Indicator_Output_Right = "RIGHT (-)";                                             // ...
Out_Side_Zones_Right = true;                                                      // ...
}                                                                                 // ...

if(Sensor_Distance_1 > Zone_9_Distance && Sensor_Distance_1 < Zone_10_Distance){  // ...
Indicator_Output_Right = "RIGHT (+)";                                             // ...
Out_Side_Zones_Right = true;                                                      // ...
}                                                                                 // ...

if(Sensor_Distance_1 > Zone_10_Distance && Sensor_Distance_1 < Zone_11_Distance){ // ...
Indicator_Output_Right = "RIGHT (ALIGNED)";                                       // ...
Out_Side_Zones_Right = true;                                                      // ...
}                                                                                 // ...

if(Sensor_Distance_1 > Zone_11_Distance && Sensor_Distance_1 < Zone_12_Distance){ // ...
Indicator_Output_Right = "RIGHT (-)";                                             // ...
Out_Side_Zones_Right = true;                                                      // ...
}                                                                                 // ...


if(!Out_Side_Zones_Right){                                                        // ...
Indicator_Output_Right = "RIGHT (OUT)";                                           // ...
}                                                                                 // ...


if(Sensor_Distance_2 > Zone_1_Distance && Sensor_Distance_2 < Zone_2_Distance){   // ...
Indicator_Output_Left = "LEFT (+)";                                               // ...
Out_Side_Zones_Left = true;                                                       // ...
}                                                                                 // ...

if(Sensor_Distance_2 > Zone_2_Distance && Sensor_Distance_2 < Zone_3_Distance){   // ...
Indicator_Output_Left = "LEFT (ALIGNED)";                                         // ...
Out_Side_Zones_Left = true;                                                       // ...
}                                                                                 // ...

if(Sensor_Distance_2 > Zone_3_Distance && Sensor_Distance_2 < Zone_4_Distance){   // ...
Indicator_Output_Left = "LEFT (-)";                                               // ...
Out_Side_Zones_Left = true;                                                       // ...
}                                                                                 // ...

if(Sensor_Distance_2 > Zone_5_Distance && Sensor_Distance_2 < Zone_6_Distance){   // ...
Indicator_Output_Left = "LEFT (+)";                                               // ...
Out_Side_Zones_Left = true;                                                       // ...
}                                                                                 // ...

if(Sensor_Distance_2 > Zone_6_Distance && Sensor_Distance_2 < Zone_7_Distance){   // ...
Indicator_Output_Left = "LEFT (ALIGNED)";                                         // ...
Out_Side_Zones_Left = true;                                                       // ...
}                                                                                 // ...

if(Sensor_Distance_2 > Zone_7_Distance && Sensor_Distance_2 < Zone_8_Distance){   // ...
Indicator_Output_Left = "LEFT (-)";                                               // ...
Out_Side_Zones_Left = true;                                                       // ...
}                                                                                 // ...

if(Sensor_Distance_2 > Zone_9_Distance && Sensor_Distance_2 < Zone_10_Distance){   // ...
Indicator_Output_Left = "LEFT (+)";                                               // ...
Out_Side_Zones_Left = true;                                                       // ...
}                                                                                 // ...

if(Sensor_Distance_2 > Zone_10_Distance && Sensor_Distance_2 < Zone_11_Distance){   // ...
Indicator_Output_Left = "LEFT (ALIGNED)";                                         // ...
Out_Side_Zones_Left = true;                                                       // ...
}                                                                                 // ...

if(Sensor_Distance_2 > Zone_11_Distance && Sensor_Distance_2 < Zone_12_Distance){   // ...
Indicator_Output_Left = "LEFT (-)";                                               // ...
Out_Side_Zones_Left = true;                                                       // ...
}                                                                                 // ...

if(!Out_Side_Zones_Left){                                                         // ...
Indicator_Output_Left = "LEFT (OUT)";                                             // ...
}                                                                                 // ...

Serial.print("Distance: ");                                                       // ...
Serial.print(Sensor_Distance_1);                                                  // ...
Serial.print(" / ");                                                              // ...
Serial.println(Sensor_Distance_2);                                                // ...

if(Indicator_Output_Right == "RIGHT (OUT)"){                                      // ...
digitalWrite(Right_LED_A, LOW);                                                   // ...
digitalWrite(Right_LED_S, LOW);                                                   // ...
}                                                                                 // ...

if(Indicator_Output_Right == "RIGHT (+)"){                                        // ...
digitalWrite(Right_LED_A, HIGH);                                                  // ...
digitalWrite(Right_LED_S, LOW);                                                   // ...
}                                                                                 // ...

if(Indicator_Output_Right == "RIGHT (ALIGNED)"){                                  // ...
digitalWrite(Right_LED_A, HIGH);                                                  // ...
digitalWrite(Right_LED_S, HIGH);                                                  // ...
}                                                                                 // ...

if(Indicator_Output_Right == "RIGHT (-)"){                                        // ...
digitalWrite(Right_LED_A, LOW);                                                   // ...
digitalWrite(Right_LED_S, HIGH);                                                  // ...
}                                                                                 // ...

if(Indicator_Output_Left == "LEFT (OUT)"){                                        // ...
digitalWrite(Left_LED_A, LOW);                                                   // ...
digitalWrite(Left_LED_S, LOW);                                                    // ...
}                                                                                 // ...

if(Indicator_Output_Left == "LEFT (+)"){                                          // ...
digitalWrite(Left_LED_A, HIGH);                                                   // ...
digitalWrite(Left_LED_S, LOW);                                                    // ...
}                                                                                 // ...

if(Indicator_Output_Left == "LEFT (ALIGNED)"){                                    // ...
digitalWrite(Left_LED_A, HIGH);                                                   // ...
digitalWrite(Left_LED_S, HIGH);                                                   // ...
}                                                                                 // ...

if(Indicator_Output_Left == "LEFT (-)"){                                          // ...
digitalWrite(Left_LED_A, LOW);                                                    // ...
digitalWrite(Left_LED_S, HIGH);                                                   // ...
}                                                                                 // ...

delay(100);                                                                        // Base cycle throttle. [Do not remove!]
}                                                                                 // ...


// ///////////////////////////////////////////////////////////////// FUNCTION(S)

// [FUNCTION] => OBTAING DISTANCE FROM ULTRASONIC SENSORS (RAW PULSES)
float Scan_Sensor(int Sensor_Trigger, int Sensor_Echo){                           // ...
float Sensor_Duration = 0;                                                        // Value retrieved from sensor.
float Sensor_mm = 0;                                                              // Converted measurement.
digitalWrite(Sensor_Trigger, LOW);                                                // Set output LOW.
delayMicroseconds(5);                                                             // Wait clearance time.
digitalWrite(Sensor_Trigger, HIGH);                                               // Set output HIGH.
delayMicroseconds(10);                                                            // Sending input trigger.
digitalWrite(Sensor_Trigger, LOW);                                                // Set output LOW.
pinMode(Sensor_Echo, INPUT);                                                      // Sending input trigger.
Sensor_Duration =  pulseIn(Sensor_Echo, HIGH);                                    // Retrieve HCSR04 feedback.
Sensor_mm = (Sensor_Duration/2.9)/2;                                              // Convert to cm.
delayMicroseconds(10);                                                            // Apply reading buffer.
Sensor_mm = Sensor_mm + 70;                                                       // Apply sensor offeset to rail.
return Sensor_mm;                                                                 // Return value.
}
