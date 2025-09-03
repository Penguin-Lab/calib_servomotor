#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <DabbleESP32.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

struct Pata {
  Adafruit_PWMServoDriver* pwm;
  int pinOmbro;
  int pinFemur;
  int pinTibia;
  int angOmbro;
  int angFemur;
  int angTibia;
  float angOmbro_rad;
  float angFemur_rad;
  float angTibia_rad;
  int OMIN;
  int OMAX;
  int FMIN;
  int FMAX;
  int TMIN;
  int TMAX;

  Pata(Adafruit_PWMServoDriver* pwm, int pinOmbro, int pinFemur, int pinTibia, int OMIN, int OMAX, int FMIN, int FMAX, int TMIN, int TMAX) {
    this->pwm = pwm;
    this->pinOmbro = pinOmbro;
    this->pinFemur = pinFemur;
    this->pinTibia = pinTibia;
    this->angOmbro = -1;
    this->angFemur = -1;
    this->angTibia = -1;
    this->OMIN = OMIN;
    this->OMAX = OMAX;
    this->FMIN = FMIN;
    this->FMAX = FMAX;
    this->TMIN = TMIN;
    this->TMAX = TMAX;
  }
  
  void moverPata(int angOmbro, int angFemur, int angTibia) {
    if (this->angOmbro != angOmbro) {
      this->angOmbro = angOmbro;
      int pulso = map(this->angOmbro, 0, 180, OMIN, OMAX);
      pwm->setPWM(this->pinOmbro, 0, pulso);
    }
    if (this->angFemur != angFemur) {
      this->angFemur = angFemur;
      int pulso = map(this->angFemur, 0, 180, FMIN, FMAX);
      pwm->setPWM(this->pinFemur, 0, pulso);
    }
    if (this->angTibia != angTibia) {
      this->angTibia = angTibia;
      int pulso = map(this->angTibia, 0, 180, TMIN, TMAX);
      pwm->setPWM(this->pinTibia, 0, pulso);
    }
    Serial.print("Ombro " + String(this->angOmbro));
    Serial.print(" Femur " + String(this->angFemur));
    Serial.println(" Tibia " + String(this->angTibia));
  }
};

int angOmbro = 0;
int angFemur = 0;
int angTibia = 0;

// Pata EsqF = {&pwm, 0, 1, 2, 292, 718, 306, 727, 135, -298};
Pata EsqF = {&pwm, 0, 1, 2, 292, 718, 306, 727, 141, -277};

void setup() {
  Serial.begin(115200);
  Dabble.begin("Pata");
  Serial.println("Teste de pata!");

  pwm.begin();
  pwm.setPWMFreq(50);

  delay(2000);

}

bool cima = 0;
bool baixo = 0;
void loop(){
  Dabble.processInput();
  if (GamePad.isUpPressed()){
    EsqF.moverPata(angOmbro,angFemur,angTibia);
  }

  if (GamePad.isLeftPressed()){
    EsqF.moverPata(45,45,-45);
  }
  
  delay(200);
}
