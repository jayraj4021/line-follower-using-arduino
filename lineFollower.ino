//sensor pins
const int IR0 = 2;
const int IR1 = 3;
const int IR2 = 4;
const int IR3 = 5;
const int IR4 = 6;
const int IR5 = 7;

//Motor control pins- 
//left motor- MOT0 & MOT1
//right motor- MOT2 & MOT3
const int MOT0 = 9;
const int MOT1 = 8;
const int MOT2 = 10;
const int MOT3 = 11;

void setup() {
      pinMode(MOT0,OUTPUT);
      pinMode(MOT1,OUTPUT);
      pinMode(MOT2,OUTPUT);
      pinMode(MOT3,OUTPUT);
      // initialize the serial communications:
      //Serial.begin(115200);
}

void loop() {
      int S0 = digitalRead(IR0);
      int S1 = digitalRead(IR1);
      int S2 = digitalRead(IR2);
      int S3 = digitalRead(IR3);
      int S4 = digitalRead(IR4);
      int S5 = digitalRead(IR5);
      // print the sensor values:

      //Conditions to drive line folower appropriately
      if (S0==0 && S1==0 && S2==0 && S3==0 && S4==0 && S5==0) {
            //stop
            digitalWrite(MOT0,LOW);
            digitalWrite(MOT1,LOW);
            digitalWrite(MOT2,LOW);
            digitalWrite(MOT3,LOW);
      } else if (S0==1 && S1==1 && S2==1 && S3==1 && S4==1 && S5==1) {
            //stop
            digitalWrite(MOT0,LOW);
            digitalWrite(MOT1,LOW);
            digitalWrite(MOT2,LOW);
            digitalWrite(MOT3,LOW);
      } else if (S2==0 && S3==0) {
            //if two sensors at the center reads 0, go straight
            digitalWrite(MOT0,HIGH);
            digitalWrite(MOT1,LOW);
            digitalWrite(MOT2,LOW);
            digitalWrite(MOT3,HIGH);  
      } else if (S1==0 && S2==0) {
            //follower moving towads right, stop left motor
            //digitalWrite(MOT0,LOW);
            analogWrite(MOT0, 125);
            digitalWrite(MOT1,LOW);
            digitalWrite(MOT2,LOW);
            digitalWrite(MOT3,HIGH);
      } else if (S0==0 && S1==0) {
            //follower moving towads right, stop left motor
            digitalWrite(MOT0,LOW);
            digitalWrite(MOT1,LOW);
            digitalWrite(MOT2,LOW);
            digitalWrite(MOT3,HIGH);
      } else if (S3==0 && S4==0) {
            //follower moving towads left, stop right motor
            digitalWrite(MOT0,HIGH);
            digitalWrite(MOT1,LOW);
            digitalWrite(MOT2,LOW);
            //digitalWrite(MOT3,LOW);
            analogWrite(MOT3, 125);
      } else if (S4==0 && S5==0) {
            //follower moving towads left, stop right motor
            digitalWrite(MOT0,HIGH);
            digitalWrite(MOT1,LOW);
            digitalWrite(MOT2,LOW);
            digitalWrite(MOT3,LOW);
      } else if ( S4==1 && S5==0) {
            //follower moving towads left, stop right motor
            digitalWrite(MOT0,HIGH);
            digitalWrite(MOT1,LOW);
            digitalWrite(MOT2,LOW);
            digitalWrite(MOT3,LOW); 
      } else if (S0==0 && S1==1) {
            //follower moving towads right, stop left motor
            digitalWrite(MOT0,LOW);
            digitalWrite(MOT1,LOW);
            digitalWrite(MOT2,LOW);
            digitalWrite(MOT3,HIGH);
      } else {
            //stop follower
            digitalWrite(MOT0,LOW);
            digitalWrite(MOT1,LOW);
            digitalWrite(MOT2,LOW);
            digitalWrite(MOT3,LOW);
      }
}
