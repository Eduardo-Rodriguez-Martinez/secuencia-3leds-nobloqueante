
#define led5seg 12
#define led3seg 13
#define led1seg 15

long timeNow, timeLast;
int segundos = 0;
bool ledStatus[3] = {false, false, false};

bool toggleLed(byte,bool);

void setup() {
  pinMode(led5seg,OUTPUT);
  pinMode(led3seg,OUTPUT);
  pinMode(led1seg,OUTPUT);
  digitalWrite(led5seg,LOW);
  digitalWrite(led3seg, LOW);
  digitalWrite(led1seg,LOW);
  timeLast = millis();
}

void loop() {
  timeNow = millis();
  if(timeNow - timeLast > 1000){
    segundos++;
    if(segundos%5==0){
      ledStatus[0] = toggleLed(led5seg,ledStatus[0]);
    }
    if(segundos%3==0){
      ledStatus[1] = toggleLed(led3seg,ledStatus[1]);
    }
    ledStatus[2] = toggleLed(led1seg,ledStatus[2]);
    timeLast = millis();
  }
}

bool toggleLed(byte pinLed, bool estado){
  digitalWrite(pinLed,!estado);
  return(!estado);
}
