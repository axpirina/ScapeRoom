int logika = 1;
int aurreko_logika= 1;
int i=0;
int reading_A=0;
int reading_B=0;


void setup() {
  Serial.begin(9600);
  pinMode(2,INPUT_PULLUP);
  pinMode(3,INPUT_PULLUP);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(8,HIGH);
  digitalWrite(9,HIGH);
  digitalWrite(10,HIGH);
  digitalWrite(11,HIGH);
  digitalWrite(12,HIGH);
  digitalWrite(13,HIGH);
}

void loop() {
  reading_A = digitalRead(2);
  reading_B = digitalRead(3);
  reading_A = ! reading_A;
  reading_B = ! reading_B;
  
  Serial.print("A botoia: ");
  Serial.println(reading_A);
  Serial.print("B botoia: ");
  Serial.println(reading_B);
  Serial.println(" ");

  if (reading_A == 0 && reading_B == 0) {logika = 1;}
  if (reading_A == 0 && reading_B == 1) {logika = 2;}
  if (reading_A == 1 && reading_B == 0) {logika = 3;}
  if (reading_A == 1 && reading_B == 1) {logika = 4;}

switch (i) {
  
case 0:
  Serial.println("0 Egoera");
  digitalWrite(13,HIGH);
  if (logika != aurreko_logika) {
     if (logika == 2 || logika == 3) {i++;}
  }
  break;
  
case 1:
  Serial.println("1 Egoera");
  digitalWrite(6,LOW);
  if (logika != aurreko_logika) {
     if (logika == 4) {i++;}
  }
  break;
  
case 2:
  Serial.println("2 Egoera");
  digitalWrite(6,HIGH);
  digitalWrite(7,LOW);
  if (logika != aurreko_logika) {
     if (logika == 2 || logika == 3) {i++;}
  }
  break;
  
case 3:
  Serial.println("3 Egoera");
  digitalWrite(7,HIGH);
  digitalWrite(8,LOW);
  if (logika != aurreko_logika) {
     if (logika == 4) {i++;}
  }
  break;
  
case 4:
  Serial.println("4 Egoera");
  digitalWrite(8,HIGH);
  digitalWrite(9,LOW);
  if (logika != aurreko_logika) {
     if (logika == 2 || logika == 3) {i++;}
  }
  break;
  
case 5:
  Serial.println("5 Egoera");
  digitalWrite(9,HIGH);
  digitalWrite(10,LOW);
  if (logika != aurreko_logika) {
     if (logika == 4) {i++;}
  }
  break;
  
case 6:
  Serial.println("6 Egoera");
  digitalWrite(10,HIGH);
  digitalWrite(11,LOW);
  if (logika != aurreko_logika) {
     if (logika == 2 || logika == 3) {i++;}
  }
  break;
  
case 7:
  Serial.println("7 Egoera");
  digitalWrite(11,HIGH);
  digitalWrite(12,LOW);
  if (logika != aurreko_logika) {
     if (logika == 4) {i++;}
  }
  break;
  
case 8:
  Serial.println("8 Egoera ITXARON");
  digitalWrite(12,HIGH);
  digitalWrite(13,LOW);
  delay(5000);
  i=0;
  break;
  
default:
  Serial.println("Egoera ezezaguna");
  break;
  
}
logika = aurreko_logika;
delay(150);
}
