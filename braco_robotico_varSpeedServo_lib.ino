#include <VarSpeedServo.h>

#define ANGULO_INICIAL_MOTOR 90
#define VELOCIDADE_MOTOR 50

int auxBase = ANGULO_INICIAL_MOTOR;
int auxBraco1 = ANGULO_INICIAL_MOTOR;
int auxBraco2 = ANGULO_INICIAL_MOTOR;
int auxGarra = ANGULO_INICIAL_MOTOR;

// --- Mapeamento dos Joysticks ---
#define joystick1X A4
#define joystick1Y A5
#define joystick2X A2
#define joystick2Y A3

// --- Mapeamento dos Servos ---
VarSpeedServo motorBase;
VarSpeedServo motorBraco1;
VarSpeedServo motorBraco2;
VarSpeedServo motorGarra;

// --- Inicialização ---
void setup() {
  Serial.begin(9600);
  mapearPinosDosMotores();
  inicializarAngulosDosMotores();
  mapearJoystickComoInput();
}

// --- Loop Infinito ---
void loop() {
  moverBase();
  moverBraco1();
  moverBraco2();
  moverGarra();
  delay(100);
}

// --- FUNÇÕES AUXILIARES ---

// --- Mapear Pinos dos Servo Motores ---

void mapearPinosDosMotores() {
  motorBase.attach(5);
  motorBraco1.attach(6);
  motorBraco2.attach(9);
  motorGarra.attach(10);  // entradas com PWM
}

// --- Inicializar Ângulos Iniciais dos Motores ---
void inicializarAngulosDosMotores() {
  motorBase.write(ANGULO_INICIAL_MOTOR);
  motorBraco1.write(ANGULO_INICIAL_MOTOR);
  motorBraco2.write(60);
  motorGarra.write(60);
}

// --- Mapear Pinos do Joystick como Input ---
void mapearJoystickComoInput() {
  pinMode(joystick1X, INPUT);
  pinMode(joystick1Y, INPUT);
  pinMode(joystick2X, INPUT);
  pinMode(joystick2Y, INPUT);
}

// --- Mover Base ---
void moverBase() {
  int pos1X = analogRead(joystick1X);
  pos1X = map(pos1X, 0, 1023, 0, 180);
  if (pos1X > 100) {
    auxBase += 10;
    motorBase.write(auxBase, VELOCIDADE_MOTOR);
  } else if (pos1X < 80) {
    auxBase -= 10;
    motorBase.write(auxBase, VELOCIDADE_MOTOR);
  }
}

// --- Mover Braco 1 ---
void moverBraco1() {
  int pos1Y = analogRead(joystick1Y);
  pos1Y = map(pos1Y, 0, 1023, 45, 135);
  if (pos1Y > 100) {
    auxBraco1 += 10;
    motorBraco1.write(auxBraco1, VELOCIDADE_MOTOR);
  } else if (pos1Y < 80) {
    auxBraco1 -= 10;
    motorBraco1.write(auxBraco1, VELOCIDADE_MOTOR);
  }
}

// --- Mover Braco 2 ---
void moverBraco2() {
  int pos2X = analogRead(joystick2X);
  pos2X = map(pos2X, 0, 1023, 0, 180);
  if (pos2X > 100) {
    auxBraco2 += 10;
    motorBraco2.write(auxBraco2, VELOCIDADE_MOTOR);
  } else if (pos2X < 80) {
    auxBraco2 -= 10;
    motorBraco2.write(auxBraco2, VELOCIDADE_MOTOR);
  }
}

// --- Mover Garra ---
void moverGarra() {
  int pos2Y = analogRead(joystick2Y);
  pos2Y = map(pos2Y, 0, 1023, 0, 180);
  if (pos2Y > 100) {
    auxGarra += 10;
    motorGarra.write(auxGarra, VELOCIDADE_MOTOR);
  } else if (pos2Y < 80) {
    auxGarra -= 10;
    motorGarra.write(auxGarra, VELOCIDADE_MOTOR);
  }
}
