#include <Servo.h>

#define ANGULO_INICIAL_MOTOR 90

// --- Mapeamento dos Joysticks ---
#define joystick1X A4
#define joystick1Y A5
#define joystick2X A2
#define joystick2Y A3

// --- Mapeamento dos Servos ---
Servo motorBase;
Servo motorBraco1;
Servo motorBraco2;
Servo motorGarra;

// --- Inicialização ---
void setup() {
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
  motorBraco2.write(ANGULO_INICIAL_MOTOR);
  motorGarra.write(ANGULO_INICIAL_MOTOR);
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
  motorBase.write(pos1X);
}

// --- Mover Braco 1 ---
void moverBraco1() {
  int pos1Y = analogRead(joystick1Y);
  pos1Y = map(pos1Y, 0, 1023, 45, 135);
  motorBraco1.write(pos1Y);
}

// --- Mover Braco 2 ---
void moverBraco2() {
  int pos2X = analogRead(joystick2X);
  pos2X = map(pos2X, 0, 1023, 50, 90);
  motorBraco2.write(pos2X);
}

// --- Mover Garra ---
void moverGarra() {
  int pos2Y = analogRead(joystick2Y);
  pos2Y = map(pos2Y, 0, 1023, 90, 130);
  motorGarra.write(pos2Y);
}
