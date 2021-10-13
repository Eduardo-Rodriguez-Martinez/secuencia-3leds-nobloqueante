
#define led5seg 12
#define led3seg 13
#define led1seg 15

long timeNow, timeLast;
int segundos = 0;
char flag;
// led5seg led3aeg led1seg flag
// 0       0       0       0
// 0       0       1       1
// 0       1       0       2
// 0       1       1       3
// 1       0       0       4
// 1       0       1       5
// 1       1       0       6
// 1       1       1       7

void setup() {
  pinMode(led5seg,OUTPUT);
  pinMode(led3seg,OUTPUT);
  pinMode(led1seg,OUTPUT);
  digitalWrite(led5seg,HIGH);
  digitalWrite(led3seg, HIGH);
  digitalWrite(led1seg,HIGH);
  flag = 0b00000011;
  timeLast = millis();
}

void loop() {
  timeNow = millis();
  if(timeNow - timeLast > 1000){
    segundos++;
    if(segundos%5==0){
      if(flag>3){
        digitalWrite(led5seg,LOW);
        flag = flag & 0b00000011;
      }
      else{
        digitalWrite(led5seg,HIGH);
        flag = flag | 0b00000100;
      }
    }
    if(segundos%3==0){
      if(flag & 0b00000010){
        digitalWrite(led3seg,LOW);
        flag = flag & 0b00000101;
      }
      else{
        digitalWrite(led3seg,HIGH);
        flag = flag | 0b00000010;
      }
    }
    if(flag & 0b00000001){
      digitalWrite(led1seg,LOW);
      flag = flag & 0b00000110;
    }
    else{
      digitalWrite(led1seg,HIGH);
      flag = flag | 0b00000001;
    }
    timeLast = millis();
  }
}
