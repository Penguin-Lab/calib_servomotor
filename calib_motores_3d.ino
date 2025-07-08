#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <DabbleESP32.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
int PULSO_MIN = 100;
int PULSO_MAX = 540;
int pulso = (PULSO_MAX-PULSO_MIN)/2;
int passinho = 5;
#define TEMPO 10


void setup() {
  Serial.begin(115200);
  Dabble.begin("Motor");
  Serial.println("Calibração de motores!");
  pinMode(0,INPUT_PULLUP);
  pinMode(16,INPUT_PULLUP);

  pwm.begin();
  pwm.setPWMFreq(50);  // This is the maximum PWM frequency

  pwm.setPWM(0, 0, pulso);
  Serial.println("Pulso: " + String(pulso));
  delay(2000);

}

bool cima = 0;
bool baixo = 0;
void loop(){
  // Serial.print(digitalRead(0));
  // Serial.println(digitalRead(16));
  Dabble.processInput();
  if (GamePad.isUpPressed()&&!cima){
    pulso+=passinho;
    pwm.setPWM(0, 0, pulso);
    Serial.println("Pulso: " + String(pulso));
    cima = !cima;
  }

  if (GamePad.isRightPressed()&&cima){
    pulso+=passinho;
    pwm.setPWM(0, 0, pulso);
    Serial.println("Pulso: " + String(pulso));
    cima = !cima;
  }

  if (GamePad.isDownPressed()&&!baixo){
    pulso-=passinho;
    pwm.setPWM(0, 0, pulso);
    Serial.println("Pulso: " + String(pulso));
    baixo = !baixo;
  }

  if (GamePad.isLeftPressed()&&baixo){
    pulso-=passinho;
    pwm.setPWM(0, 0, pulso);
    Serial.println("Pulso: " + String(pulso));
    baixo = !baixo;
  }

  if (GamePad.isSquarePressed()){
    while(true){
      pulso++;
      pwm.setPWM(0, 0, pulso);
      Serial.println("Pulso: " + String(pulso));
      delay(TEMPO);
      if (!digitalRead(16)){
        break;
      }
    }
    pulso-=2;
    pwm.setPWM(0, 0, pulso);
    PULSO_MAX = pulso;
    Serial.println("Pulso máximo: " + String(PULSO_MAX));
  }
  if (GamePad.isCirclePressed()){
    while(true){
      pulso--;
      pwm.setPWM(0, 0, pulso);
      Serial.println("Pulso: " + String(pulso));
      delay(TEMPO);
      if (!digitalRead(0)){
        break;
      }
    }
    pulso+=2;
    pwm.setPWM(0, 0, pulso);
    PULSO_MIN = pulso;
    Serial.println("Pulso minimo: " + String(PULSO_MIN));
  }
  if (GamePad.isTrianglePressed()){
    Serial.println("Faixa: " + String(PULSO_MIN) + " a " + String(PULSO_MAX));
  }
  if (GamePad.isCrossPressed()){
    pulso = int((PULSO_MAX+PULSO_MIN)/2);
    pwm.setPWM(0, 0, pulso);
    Serial.println("Valor: " + String(pulso));
  }
  delay(200);
}
