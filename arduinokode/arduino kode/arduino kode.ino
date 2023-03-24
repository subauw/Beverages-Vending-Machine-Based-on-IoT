#include <SoftwareSerial.h>
#include <Servo.h>

SoftwareSerial ArduinoUno (3, 2);

Servo servo_milep;
Servo servo_saus;
int sensor_milep;
int sensor_saus;

void setup() {
  Serial.begin(2400);
  ArduinoUno.begin(4800);
  pinMode(3, INPUT);
  pinMode(2, OUTPUT);
  servo_milep.attach(8);
  servo_saus.attach(9);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {

  sensor_milep = digitalRead(5);
  sensor_saus = digitalRead(6);

  if(sensor_milep == 0){  
    digitalWrite(LED_BUILTIN,HIGH);
    servo_milep.write(180);  
    delay(100);
    Serial.println("servo milf on");
    
    char y = "E";
    ArduinoUno.print(y);
    ArduinoUno.println("\n");
    Serial.println(y);
    delay(30); 
  }  
  else{  
    digitalWrite(LED_BUILTIN,LOW); 
    servo_milep.write(0);  
    delay(100); 
    Serial.println("SERVO MILF OFF");

    char x = "s";
    ArduinoUno.print(x);
    ArduinoUno.println("\n");
    Serial.println(x);
    delay(30); 
  }  

  if(sensor_saus == 0){
    digitalWrite(LED_BUILTIN,HIGH);
    servo_saus.write(180);  
    delay(100);
    Serial.println("Servo saus on");
  } else{
    digitalWrite(LED_BUILTIN,LOW);
    servo_saus.write(0);  
    delay(100); 
    Serial.println("SERVO SAUCE OFF");
  }
}