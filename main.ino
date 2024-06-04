#include <Servo.h>
#include <Wire.h>
Servo servo1,servo2,servo3,servo4,servo5,servo6,servo7,servo8,servo9,servo10,servo11,servo12;
static int a1,a2,a3,a4,b1,b2,b3,b4,c1,c2,c3,c4,d1,d2,d3,d4,q1,q2,q3,q4,w1,w2,w3,w4,e1,e2,e3,e4,r1,r2,r3,r4;
int q,w,e,r,t,y,u,i;
int goc;
String doc="";
int a =0; int z2 = 0;
int trangthai = 0;
int speedd = 1;
int f01=0,f02=0,f03=0,f04=0;
int f11=0,f12=0,f13=0,f14=0;
int f21=0,f22=0,f23=0,f24=0;
int f31=0,f32=0,f33=0,f34=0,f35=0,f36=0;
boolean thai1 = LOW,thai2 = LOW,thai3 = LOW;

void setup() {
  Serial.begin(115200);
  Serial.println("8 channel Servo test!");
  
  servo1.attach(2);servo2.attach(3);servo3.attach(4);
  servo4.attach(5);servo5.attach(6);servo6.attach(7);
  servo7.attach(8);servo8.attach(9);servo9.attach(10);
  servo10.attach(11);servo11.attach(12);servo12.attach(13);

  servo3.write(90);
  servo6.write(90);
  servo9.write(90);
  servo12.write(90);
  delay(5);
  servo1.write(90);servo2.write(90);
  servo4.write(90);servo5.write(90);
  servo7.write(90);servo8.write(95);
  servo10.write(90);servo11.write(90);


}

void loop() {
  if(Serial.available()){
    while(Serial.available()){
      doc = Serial.readString();
    }
    Serial.print(doc); }
    if(doc.indexOf("z") >=0){
      trans();
    }
    else if (doc.indexOf("x") >=0){
      retrans();
    }
    if(doc.indexOf("g") >=0) {
      forward();
    }
    else if(doc.indexOf("b") >=0) {
      backward();
     // Serial.print("lui");
    }
    else if(doc.indexOf("r") >=0) {
      right();
    }
    else if(doc.indexOf("l") >=0) {
      left();
    }
    else if(doc.indexOf("e") >=0) {
      moveRight();
    }
    if(doc.indexOf("1") >=0) speedd = 1;
    else if (doc.indexOf("2") >=0) speedd = 2;
}
void trans() {
  trangthai = 1;
  if(a < 66 ) {
    servo1.write(90+a); 
    servo2.write(90+a);
    servo4.write(90-a); 
    servo5.write(90-a);
    servo7.write(90+a);
    servo8.write(95+a);
    servo10.write(90-a); 
    servo11.write(90-a);
    a++;
    delay(5);
  }
  if(a>= 66 && z2 < 30) {
    servo3.write(90+z2);
    servo6.write(90-z2);
    servo9.write(90+z2);
    servo12.write(90-z2);
    z2++;
    delay(5);
  }
  //f01=0;f02=0;f03=0;f04=0;
  f11=0;f12=0;f13=0;f14=0;
  f21=0;f22=0;f23=0;f24=0;
  q=0;a3=0;b3=0;c3=0;d3=0;
  w=0;a1=0;a2=0;b1=0;b2=0;c1=0;c2=0;d1=0;d2=0;
  thai1 = LOW;thai2 = LOW;
  e = 0;
}
void retrans() {
  trangthai = 0;
  if ( q < 4) {
    check(servo3,90,"a3");
    check(servo6,90,"b3");
    check(servo9,90,"c3");
    check(servo12,90,"d3");
    q = a3+b3+c3+d3;
    delay(5);
  }
  if( q >= 4 && w < 8 ) {
    check(servo1,90,"a1");
    check(servo2,90,"a2");
    check(servo4,90,"b1");
    check(servo5,90,"b2");
    check(servo7,90,"c1");
    check(servo8,95,"c2");
    check(servo10,90,"d1");
    check(servo11,90,"d2");
    w = a1+a2+b1+b2+c1+c2+d1+d2;
    z2 = 0;
    a=0;
    delay(5);
  }
  if( w >= 8 ) {
    a1=0;a2=0;b1=0;b2=0;c1=0;c2=0;d1=0;d2=0;a3=0;b3=0;c3=0;d3=0;
  }
}
void forward() {
  if (trangthai == 1) {
    legsetup();
    if (thai1 == HIGH){  
      leg13();
      if(thai2==HIGH){
        leg24();
      }
    }
  }
  delay(15);
}
void backward(){
  if ( trangthai==1){
    legsetup();
    if(thai1 == HIGH){
      leg13rev();
      if(thai2 == HIGH){
        leg24rev();
      }
    }
  }
  delay(15);
}
void right(){
  if ( trangthai==1){
    legsetup();
    if(thai1 == HIGH){
      leg13Right();
      if(thai2 == HIGH){
        leg24Right();
      }
    }
  }
  delay(15);
}
void left(){
  if ( trangthai==1){
    legsetup();
    if(thai1 == HIGH){
      leg13Left();
      if(thai2 == HIGH){
        leg24Left();
      }
    }
  }
  delay(15);
}
void moveRight() {
  if ( trangthai==1){
    setup2();
    if(thai3 == HIGH) {
      leg13moveRight();
    }
  }
  delay(15);
}
 void leg13(){
  if(f11<30) {
    servo1.write(156-f11);
    servo2.write(156-f11*0.6);
    servo7.write(156-f11);
    servo8.write(161-f11*0.6);
    f11+= speedd;
  }
  if(f11>=30 & f12 <30){
    servo9.write(120-f12);
    servo3.write(90+f12);
    f12+= speedd;
  }
  if(f12>=30 & f13<30){
    servo1.write(126+f13);
    servo2.write(138+f13*0.6);
    servo7.write(126+f13);
    servo8.write(143+f13*0.6);
    f13+= speedd;
    thai2 = HIGH;
  }
  if(f13>=30 & f14<30){
    servo3.write(120-f14);
    servo9.write(90+f14);
    f14+= speedd;
    //thai2 = HIGH;
  }
  if(f14>=30){
   // thai2 = HIGH;
    f11=0;f12=0;f13=0;f14=0;
    
  }
}
void legsetup() {
  if(e < 12 ){
      check(servo3,90,"a3");
      check(servo12,90,"d3");
      check(servo6,60,"b3");
      check(servo9,120,"c3");
      check(servo1,156,"a1");
      check(servo2,156,"a2");
      check(servo7,156,"c1");
      check(servo8,161,"c2");
      check(servo4,24,"b1");
      check(servo5,24,"b2");
      check(servo10,24,"d1");
      check(servo11,24,"d2");
      e = a1+a2+b1+b2+c1+c2+d1+d2+a3+b3+c3+d3;
    }
    if( e >= 12 ) {
      a1=0;a2=0;b1=0;b2=0;c1=0;c2=0;d1=0;d2=0;a3=0;b3=0;c3=0;d3=0;
      thai1 = HIGH;
    }
}
void leg24() {
  if( f21 <30) {
    servo4.write(24+ f21);
    servo5.write(24+f21*0.6);
    servo10.write(24+f21);
    servo11.write(24+f21*0.6);
    f21+= speedd;
  }
  if( f21 >=30 & f22 <= 30){
    servo6.write(60+f22);
    servo12.write(90-f22);
    f22+= speedd;
  }
  if( f22 >=30 & f23<=30 ){
    servo10.write(54-f23);
    servo11.write(42-f23*0.6);
    servo4.write(54-f23);
    servo5.write(42-f23*0.6);
    f23+= speedd;
  }
  if( f23 >=30 & f24<=30){
    servo6.write(90-f24);
    servo12.write(60+f24);
    f24+= speedd;
  }
  if(f24>=30){
    f21=0;f22=0;f23=0;f24=0;
  }
}
void leg13rev() {
  if(f11 < 30){
    servo1.write(156-f11);
    servo2.write(156-f11*0.6);
    servo7.write(156-f11);
    servo8.write(161-f11*0.6);
    f11+= speedd;
  }
  if(f11>=30 & f12 < 30){
    servo3.write(120-f12);
    servo9.write(90+f12);
    f12+= speedd;
  }
  if(f12>=30 & f13<30){
    servo1.write(126+f13);
    servo2.write(138+f13*0.6);
    servo7.write(126+f13);
    servo8.write(143+f13*0.6);
    f13+= speedd;
    thai2 = HIGH;
  }
  if(f13>=30 & f14<30){
    servo9.write(120-f14);
    servo3.write(90+f14);
    f14+= speedd;
  }
  if(f14 >= 30) {
    f11=0;f12=0;f13=0;f14=0;
  }
  
}
void leg24rev(){
  if(f21<30){
    servo4.write(24+ f21);
    servo5.write(24+f21*0.6);
    servo10.write(24+f21);
    servo11.write(24+f21*0.6);
    f21+= speedd;
  }
  if( f21 >=30 & f22 <= 30){
    servo6.write(90-f22);
    servo12.write(60+f22);
    f22+= speedd;
  }
  if( f22 >=30 & f23<=30 ){
    servo10.write(54-f23);
    servo11.write(42-f23*0.6);
    servo4.write(54-f23);
    servo5.write(42-f23*0.6);
    f23+= speedd;
  }
  if( f23 >=30 & f24<=30){
    servo6.write(60+f24);
    servo12.write(90-f24);
    f24+= speedd;
  }
  if(f24>=30){
    f21=0;f22=0;f23=0;f24=0;
  }
}
void leg13Right(){
  if(f11<30) {
    servo1.write(156-f11);
    servo2.write(156-f11*0.6);
    servo7.write(156-f11);
    servo8.write(161-f11*0.6);
    f11+= speedd;
  }
  if(f11>=30 & f12 <30){
    servo3.write(90+f12);
    servo9.write(90+f12);
    f12+= speedd;
  }
  if(f12>=30 & f13<30){
    servo1.write(126+f13);
    servo2.write(138+f13*0.6);
    servo7.write(126+f13);
    servo8.write(143+f13*0.6);
    f13+= speedd;
    thai2 = HIGH;
  }
  if(f13>=30 & f14<30){
    servo3.write(120-f14);
    servo9.write(120-f14);
    f14+= speedd;
    //thai2 = HIGH;
  }
  if(f14>=30){
   // thai2 = HIGH;
    f11=0;f12=0;f13=0;f14=0;
    
  }
}
void leg24Right() {
  if( f21 <30) {
    servo4.write(24+ f21);
    servo5.write(24+f21*0.6);
    servo10.write(24+f21);
    servo11.write(24+f21*0.6);
    f21+= speedd;
  }
  if( f21 >=30 & f22 <= 30){
    servo6.write(60+f22);
    servo12.write(60+f22);
    f22+= speedd;
  }
  if( f22 >=30 & f23<=30 ){
    servo10.write(54-f23);
    servo11.write(42-f23*0.6);
    servo4.write(54-f23);
    servo5.write(42-f23*0.6);
    f23+= speedd;
  }
  if( f23 >=30 & f24<=30){
    servo6.write(90-f24);
    servo12.write(90-f24);
    f24+= speedd;
  }
  if(f24>=30){
    f21=0;f22=0;f23=0;f24=0;
  }
}
void leg13Left(){
  if(f11<30) {
    servo1.write(156-f11);
    servo2.write(156-f11*0.6);
    servo7.write(156-f11);
    servo8.write(161-f11*0.6);
    f11+= speedd;
  }
  if(f11>=30 & f12 <30){
    servo3.write(120-f12);
    servo9.write(120-f12);
    f12+= speedd;
  }
  if(f12>=30 & f13<30){
    servo1.write(126+f13);
    servo2.write(138+f13*0.6);
    servo7.write(126+f13);
    servo8.write(143+f13*0.6);
    f13+= speedd;
    thai2 = HIGH;
  }
  if(f13>=30 & f14<30){
    servo3.write(90+f14);
    servo9.write(90+f14);
    f14+= speedd;
    //thai2 = HIGH;
  }
  if(f14>=30){
   // thai2 = HIGH;
    f11=0;f12=0;f13=0;f14=0;
    
  }
}
void leg24Left() {
  if( f21 <30) {
    servo4.write(24+ f21);
    servo5.write(24+f21*0.6);
    servo10.write(24+f21);
    servo11.write(24+f21*0.6);
    f21+= speedd;
  }
  if( f21 >=30 & f22 <= 30){
    servo6.write(90-f22);
    servo12.write(90-f22);
    f22+= speedd;
  }
  if( f22 >=30 & f23<=30 ){
    servo10.write(54-f23);
    servo11.write(42-f23*0.6);
    servo4.write(54-f23);
    servo5.write(42-f23*0.6);
    f23+= speedd;
  }
  if( f23 >=30 & f24<=30){
    servo6.write(60+f24);
    servo12.write(60+f24);
    f24+= speedd;
  }
  if(f24>=30){
    f21=0;f22=0;f23=0;f24=0;
  }
}
void check(Servo i,int dk,String a){
  goc = i.read();
  if(goc < dk) {
    goc+= speedd;
    i.write(goc);
   // bien = 0;
  }
  else if(goc > dk){
    goc-= speedd;
    i.write(goc);
   // bien = 0;
  }
  if(goc == dk) {
    if(a == "a1") a1 = 1;if(a == "a2") a2 = 1;if(a == "a3") a3 = 1;if(a == "a4") a4 = 1; 
    if(a == "b1") b1 = 1;if(a == "b2") b2 = 1;if(a == "b3") b3 = 1;if(a == "b4") b4 = 1;
    if(a == "c1") c1 = 1;if(a == "c2") c2 = 1;if(a == "c3") c3 = 1;if(a == "c4") c4 = 1;
    if(a == "d1") d1 = 1;if(a == "d2") d2 = 1;if(a == "d3") d3 = 1;if(a == "d4") d4 = 1;
    if(a == "q1") q1 = 1;if(a == "q2") q2 = 1;if(a == "q3") q3 = 1;if(a == "q4") q4 = 1; 
    if(a == "w1") w1 = 1;if(a == "w2") w2 = 1;if(a == "w3") w3 = 1;if(a == "w4") w4 = 1;
    if(a == "e1") e1 = 1;if(a == "e2") e2 = 1;if(a == "e3") e3 = 1;if(a == "e4") e4 = 1;
    if(a == "r1") r1 = 1;if(a == "r2") r2 = 1;if(a == "r3") r3 = 1;if(a == "r4") r4 = 1;
    //Serial.print("DONE");
  }
}
void setup2() {
  if(r < 12 ) {
    check(servo3,90,"a3");
    check(servo12,90,"d3");
    check(servo6,90,"b3");
    check(servo9,90,"c3");
    check(servo1,156,"a1");
    check(servo2,156,"a2");
    check(servo7,156,"c1");
    check(servo8,161,"c2");
    check(servo4,24,"b1");
    check(servo5,24,"b2");
    check(servo10,24,"d1");
    check(servo11,24,"d2");
      r = a1+a2+b1+b2+c1+c2+d1+d2+a3+b3+c3+d3;
    }
    if( r >= 12 ) {
      a1=0;a2=0;b1=0;b2=0;c1=0;c2=0;d1=0;d2=0;a3=0;b3=0;c3=0;d3=0;
      thai3 = HIGH;
    }
}
void leg13moveRight() {
  if(f31 < 30) {
    servo4.write(24+ f31);
   // servo5.write(24+f31*0.6);
    servo10.write(24+f31);
   // servo11.write(24+f31*0.6);
    f31+= speedd;
  }
  if(f31 >= 30 && f32 < 20 ) {
    servo2.write(156+f31);
    servo8.write(161-f31);
    f32+=speedd;
  }
  if(f32 >=20 && f33 < 30 ) {
    servo4.write(54 - f33);
    servo5.write(42-f33*0.6);
    servo10.write(54-f31);
    servo11.write(42-f31*0.6);
    f33+= speedd;
  }
  if( f33 >= 30 && f34 < 20 ) {
    servo1.write(156-f34*1.5);
    servo2.write(176-f34*1.5);
    servo7.write(156-f34*1.5);
    servo8.write(141+f34);
    f34+= speedd;
  }
  if( f34 >=20 && f35 < 20 ) {
    servo5.write(24-f35);
    servo11.write(24+f35);
    f35+= speedd;
  }
  if( f35 >=20 && f36 < 30) {
    servo1.write(126+f34);
    //servo2.write(156+f34*0.666);
    servo7.write(126+f34);
   // servo8.write(161-f34*0.666);
    f36+= speedd;
  }
  if( f36 >=30) {
    f31=0;f32=0;f33=0;f34=0;f35=0;f36=0;
  }
}
