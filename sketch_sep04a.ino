int konum;
int hiz;
String motorMsg[]= {"Motor 1'in konumu ve hizi: ",
         "Motor 2'in konumu ve hizi: ",
         "Motor 3'in konumu ve hizi: ",
         "Motor 4'in konumu ve hizi: "};
String motor1;
String motor2;
String motor3;
String motor4;

void setup() {
  Serial.begin(9600); //Başlangıç için bit hızını seçtim
  randomSeed(analogRead(A0)); //Her başlatılmada aynı sayıları vermemesi için boş girişi seçtim
}

void loop() {
  for (int i = 0; i < 4; i++) {
   konum = random(2);
   String motorKonum = String(konum);
   hiz = random(256);
   String motorHizi;
       if (hiz < 100) {
        String hizV = String(hiz);
          motorHizi = String("0" + hizV);
          }
        if (hiz < 10){
         String hizV = String(hiz);
         motorHizi = String("00" + hizV);
          }
      if (hiz >= 100) {
         motorHizi = String(hiz);
          }
 Serial.println(motorMsg[i] + motorKonum + " ve " + motorHizi);
  
delay(3000);

    if (i == 0){
       motor1 = motorKonum + motorHizi;
      }
    if (i == 1){
       motor2 = motorKonum + motorHizi;
      }
    if (i == 2){
       motor3 = motorKonum + motorHizi;
      }
    if (i == 3){
       motor4 = motorKonum + motorHizi;
      }
     
     
  }
  
String veriGrubu = String("S" + motor1 + motor2 + motor3 + motor4 + "F");
  Serial.println("Olusan veri grubu: " + veriGrubu);
  delay(7000);
    Serial.println("");

}
