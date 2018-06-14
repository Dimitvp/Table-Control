
int lamp1 = 8;
int lamp2 = 13;

const int button1 = 2;
const int button2 = 1;
const int buttonLup = 3;
const int buttonLdown = 4;
const int buttonRup = 5;
const int buttonRdown = 6;

int button1State = 0;
int button2State = 0;

int Lup = 9;
int Ldown = 10;
int Rup = 11;
int Rdown = 12;

bool simulation = false;
bool uppermit = false;
bool downpermit = false;
bool zaedno = false;
bool stopTime = true;

int buttonPoslednoSustoianie_1 = LOW;
int buttonPoslednoSustoianie_2 = LOW;
int buttonPoslednoSustoianie_3 = LOW;
int buttonPoslednoSustoianie_4 = LOW;

long vremeIzchakvane = 500;
long poslednoVrermePrevkliuchvane_1 = 0;
long poslednoVrermePrevkliuchvane_2 = 0;
long poslednoVrermePrevkliuchvane_3 = 0;
long poslednoVrermePrevkliuchvane_4 = 0;

byte timerRun;
unsigned long startTime;
unsigned long endTime;
unsigned long duration;
unsigned long sumTime = 0;

void setup() {
  pinMode(lamp1, OUTPUT);
  pinMode(lamp2, OUTPUT);
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(buttonLup, INPUT);
  pinMode(buttonLdown, INPUT);
  pinMode(buttonRup, INPUT);
  pinMode(buttonRdown, INPUT);
  pinMode(Lup, OUTPUT);
  pinMode(Ldown, OUTPUT);
  pinMode(Rup, OUTPUT);
  pinMode(Rdown, OUTPUT);

  digitalWrite(lamp1, LOW);
  digitalWrite(lamp2, LOW);
  digitalWrite(Lup, HIGH);
  digitalWrite(Ldown, HIGH);
  digitalWrite(Rup, HIGH);
  digitalWrite(Rdown, HIGH);

  Serial.begin(9600);

}

void loop() {

  button1State = digitalRead(button1);
  if (button1State == HIGH && !simulation) {
    digitalWrite(lamp1, HIGH);
    delay(40);
    digitalWrite(lamp1, LOW);
    delay(1400);
    digitalWrite(lamp1, HIGH);
    digitalWrite(lamp2, HIGH);
    delay(50);
    digitalWrite(lamp1, LOW);
    digitalWrite(lamp2, HIGH);
    delay(500);
    digitalWrite(lamp1, HIGH);
    digitalWrite(lamp2, LOW);
    delay(300);
    digitalWrite(lamp1, LOW);
    digitalWrite(lamp2, HIGH);
    delay(1000);
    digitalWrite(lamp1, HIGH);
    digitalWrite(lamp2, LOW);
    delay(20);
    digitalWrite(lamp1, LOW);
    digitalWrite(lamp2, HIGH);
    delay(200);
    digitalWrite(lamp1, HIGH);
    digitalWrite(lamp2, LOW);
    delay(30);
    digitalWrite(lamp1, LOW);
    digitalWrite(lamp2, HIGH);
    delay(50);
    digitalWrite(lamp1, HIGH);
    digitalWrite(lamp2, LOW);
    delay(300);
    digitalWrite(lamp1, LOW);
    digitalWrite(lamp2, HIGH);
    delay(20);
    digitalWrite(lamp1, HIGH);
    digitalWrite(lamp2, LOW);
    delay(20);
    digitalWrite(lamp1, LOW);
    digitalWrite(lamp2, HIGH);
    delay(200);
    digitalWrite(lamp1, HIGH);
    digitalWrite(lamp2, LOW);
    delay(30);
    digitalWrite(lamp1, LOW);
    digitalWrite(lamp2, HIGH);
    delay(50);
    digitalWrite(lamp1, HIGH);
    digitalWrite(lamp2, LOW);
    delay(300);
    digitalWrite(lamp1, LOW);
    digitalWrite(lamp2, HIGH);
    delay(20);
    digitalWrite(lamp1, HIGH);
    digitalWrite(lamp2, LOW);
    delay(20);
    digitalWrite(lamp1, LOW);
    digitalWrite(lamp2, HIGH);
    delay(200);
    digitalWrite(lamp1, HIGH);
    digitalWrite(lamp2, LOW);
    delay(30);
    digitalWrite(lamp1, LOW);
    digitalWrite(lamp2, HIGH);
    delay(50);
    digitalWrite(lamp1, HIGH);
    digitalWrite(lamp2, LOW);
    delay(300);
    digitalWrite(lamp1, LOW);
    digitalWrite(lamp2, HIGH);
    delay(20);
    digitalWrite(lamp1, HIGH);
    digitalWrite(lamp2, LOW);
    delay(20);
    digitalWrite(lamp1, LOW);
    digitalWrite(lamp2, HIGH);
    delay(200);
    digitalWrite(lamp1, HIGH);
    digitalWrite(lamp2, LOW);
    delay(30);
    digitalWrite(lamp1, LOW);
    digitalWrite(lamp2, HIGH);
    delay(50);
    digitalWrite(lamp1, HIGH);
    digitalWrite(lamp2, LOW);
    delay(300);
    digitalWrite(lamp1, LOW);
    digitalWrite(lamp2, HIGH);
    delay(20);
    digitalWrite(lamp1, HIGH);
    digitalWrite(lamp2, LOW);
    delay(20);
    digitalWrite(lamp1, LOW);
    digitalWrite(lamp2, HIGH);
    delay(200);
    digitalWrite(lamp1, HIGH);
    digitalWrite(lamp2, LOW);
    delay(30);
    digitalWrite(lamp1, LOW);
    digitalWrite(lamp2, HIGH);
    delay(50);
    digitalWrite(lamp1, HIGH);
    digitalWrite(lamp2, LOW);
    delay(300);
    digitalWrite(lamp1, LOW);
    digitalWrite(lamp2, HIGH);
    delay(20);
    digitalWrite(lamp1, HIGH);
    digitalWrite(lamp2, HIGH);
    simulation = true;
    uppermit = false;
    downpermit = true;
    }

    int reading_1 = digitalRead(buttonLup);
    int reading_2 = digitalRead(buttonLdown);
    int reading_3 = digitalRead(buttonRup);
    int reading_4 = digitalRead(buttonRdown);

  if (timerRun == 0 && reading_2 == HIGH && reading_4 == HIGH && simulation) {
    startTime = millis();
    timerRun = 1;
    zaedno = true;
  }
  if (timerRun == 1 && reading_2 == LOW && reading_4 == LOW && simulation && stopTime) {
    endTime = millis();
    timerRun = 0;
    digitalWrite(Rdown, HIGH);
    digitalWrite(lamp2, HIGH);
    digitalWrite(Ldown, HIGH);
    digitalWrite(lamp1, HIGH);
    zaedno = false;
  duration = endTime - startTime;
  sumTime = sumTime + duration;
  Serial.print ("duration:");
  Serial.println (duration);
  Serial.print ("Time:");
  Serial.println (sumTime);
  if (sumTime > 10000) {
    uppermit = true;
    zaedno = true;
    stopTime = false;
  }
  }

  
  if (uppermit && simulation) {
    int reading_1 = digitalRead(buttonLup);
    if (reading_1 != buttonPoslednoSustoianie_1){
      poslednoVrermePrevkliuchvane_1 = millis();
    }
    if ((millis() - poslednoVrermePrevkliuchvane_1) > vremeIzchakvane) {
      if (reading_1 == HIGH) {
           digitalWrite(Lup, LOW);   
      }
    }else {
      digitalWrite(Lup, HIGH);
         } 
    buttonPoslednoSustoianie_1 = reading_1;
    
    if (reading_1 == HIGH) {
           digitalWrite(lamp1, LOW);
        } else {
      digitalWrite(lamp1, HIGH);
    }
    
    int reading_3 = digitalRead(buttonRup);
    if (reading_3 != buttonPoslednoSustoianie_3){
      poslednoVrermePrevkliuchvane_3 = millis();
    }
    if ((millis() - poslednoVrermePrevkliuchvane_3) > vremeIzchakvane) {
      if (reading_3 == HIGH) {
           digitalWrite(Rup, LOW);   
      }
    }else {
      digitalWrite(Rup, HIGH);
         } 
    buttonPoslednoSustoianie_3 = reading_3;
    
    if (reading_3 == HIGH) {
           digitalWrite(lamp2, LOW);
        } else {
      digitalWrite(lamp2, HIGH);
    }
} 

  if (downpermit && simulation && zaedno) {
    int reading_2 = digitalRead(buttonLdown);
    if (reading_2 != buttonPoslednoSustoianie_2){
      poslednoVrermePrevkliuchvane_2 = millis();
    }
    if ((millis() - poslednoVrermePrevkliuchvane_2) > vremeIzchakvane) {
      if (reading_2 == HIGH) {
           digitalWrite(Ldown, LOW);   
      }
    }else {
      digitalWrite(Ldown, HIGH);
         } 
    buttonPoslednoSustoianie_2 = reading_2;
    
    if (reading_2 == HIGH) {
           digitalWrite(lamp1, LOW);
        } else {
      digitalWrite(lamp1, HIGH);
    }
    
    int reading_4 = digitalRead(buttonRdown);
    if (reading_4 != buttonPoslednoSustoianie_4){
      poslednoVrermePrevkliuchvane_4 = millis();
    }
    if ((millis() - poslednoVrermePrevkliuchvane_4) > vremeIzchakvane) {
      if (reading_4 == HIGH) {
           digitalWrite(Rdown, LOW);   
      }
    }else {
      digitalWrite(Rdown, HIGH);
         } 
    buttonPoslednoSustoianie_4 = reading_4;
    
    if (reading_4 == HIGH) {
           digitalWrite(lamp2, LOW);
        } else {
      digitalWrite(lamp2, HIGH);
    }
  }

  button2State = digitalRead(button2);
  if (button2State == HIGH) {
    downpermit = false;
  }else {
    downpermit = true;
  }


  }
  
