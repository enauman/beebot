const int mtr1b = A1;
const int mtr1f = A2;
const int mtr2f = A3;
const int mtr2b = A4;
const int speaker = 7;
const int buttonClear = 6;
const int buttonPlay = 9;
const int buttonForward = 10;
const int buttonBack = 8;
const int buttonRight = 11;
const int buttonLeft = 5;
const int ledBlueLeft = 2;
const int ledRedLeft = 4;
const int ledGreenLeft = 3;
const int ledBlueRight = 12;
const int ledRedRight = A0;
const int ledGreenRight = 13;

int program[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int steps = sizeof(program) / sizeof(program[0]);
int currentStep = 0;
boolean playing = false;
void setup() {
  pinMode(mtr1f, OUTPUT);
  pinMode(mtr1b, OUTPUT);
  pinMode(mtr2f, OUTPUT);
  pinMode(mtr2b, OUTPUT);
  pinMode(speaker, OUTPUT);
  pinMode(buttonClear, INPUT_PULLUP);
  pinMode(buttonPlay, INPUT_PULLUP);
  pinMode(buttonForward, INPUT_PULLUP);
  pinMode(buttonBack, INPUT_PULLUP);
  pinMode(buttonRight, INPUT_PULLUP);
  pinMode(buttonLeft, INPUT_PULLUP);
  pinMode(ledBlueLeft, OUTPUT);
  pinMode(ledRedLeft, OUTPUT);
  pinMode(ledGreenLeft, OUTPUT);
  pinMode(ledBlueRight, OUTPUT);
  pinMode(ledRedRight, OUTPUT);
  pinMode(ledGreenRight, OUTPUT);
  Serial.begin(9600);

  redOff();
  greenOff();
  blueOff();

  tone(speaker, 400, 100);
  redOn();
  delay(500);
  greenOn();
  delay(500);
  redOff();
  delay(500);
  blueOn();
  delay(500);
  greenOff();
  delay(500);
  redOn();
  delay(500);
  whiteOn();
  delay(500);
  whiteOff();
  tone(speaker, 400, 100);
}

void loop() {
  buttons();
  play();
}

void forward() {
  whiteOn();
  digitalWrite(mtr1f, HIGH);
  digitalWrite(mtr1b, LOW);
  digitalWrite(mtr2f, HIGH);
  digitalWrite(mtr2b, LOW);
  delay(750);
  whiteOff();
  digitalWrite(mtr1f, LOW);
  digitalWrite(mtr1b, LOW);
  digitalWrite(mtr2f, LOW);
  digitalWrite(mtr2b, LOW);
  delay(500);
}

void back() {
  whiteOn();
  digitalWrite(mtr1f, LOW);
  digitalWrite(mtr1b, HIGH);
  digitalWrite(mtr2f, LOW);
  digitalWrite(mtr2b, HIGH);
  delay(750);
  whiteOff();
  digitalWrite(mtr1f, LOW);
  digitalWrite(mtr1b, LOW);
  digitalWrite(mtr2f, LOW);
  digitalWrite(mtr2b, LOW);
  delay(500);
}

void right() {
  whiteOn();
  digitalWrite(mtr2f, HIGH);
  digitalWrite(mtr2b, LOW);
  digitalWrite(mtr1f, LOW);
  digitalWrite(mtr1b, HIGH);
  delay(350);
  whiteOff();
  digitalWrite(mtr1f, LOW);
  digitalWrite(mtr1b, LOW);
  digitalWrite(mtr2f, LOW);
  digitalWrite(mtr2b, LOW);
  delay(500);
}

void left() {
  whiteOn();
  digitalWrite(mtr2f, LOW);
  digitalWrite(mtr2b, HIGH);
  digitalWrite(mtr1f, HIGH);
  digitalWrite(mtr1b, LOW  );
  delay(350);
  whiteOff();
  digitalWrite(mtr1f, LOW);
  digitalWrite(mtr1b, LOW);
  digitalWrite(mtr2f, LOW);
  digitalWrite(mtr2b, LOW);
  delay(500);
}

void buttons() {
  if (digitalRead(buttonClear) == 0) {
    tone(speaker, 200, 100);
    redOn();
    delay(100);
    tone(speaker, 300, 100);
    currentStep = 0;
    for (int i = 0; i < steps; i++) {
      program[i] = 0;
    }
    delay(500);
    redOff();
    greenOn();
    delay(300);
    greenOff();
  } else if (digitalRead(buttonPlay) == 0) {
    playing = true;
    play();
  } else if (digitalRead(buttonForward) == 0) {
    if (currentStep < steps) {
      tone(speaker, 400, 100);
      program[currentStep] = 1;
      currentStep++;
      whiteOn();
      delay(500);
      whiteOff();
    } else {
      tone(speaker, 200, 300);
      redOn();
      delay(500);
      redOff();
    }
  } else if (digitalRead(buttonBack) == 0) {
    if (currentStep < steps) {
      tone(speaker, 400, 100);
      program[currentStep] = 2;
      currentStep++;
      whiteOn();
      delay(500);
      whiteOff();
    } else {
      tone(speaker, 200, 300);
      redOn();
      delay(500);
      redOff();
    }
  } else if (digitalRead(buttonRight) == 0) {
    if (currentStep < steps) {
      tone(speaker, 400, 100);
      program[currentStep] = 3;
      currentStep++;
      whiteOn();
      delay(500);
      whiteOff();
    } else {
      tone(speaker, 200, 300);
      redOn();
      delay(500);
      redOff();
    }
  } else if (digitalRead(buttonLeft) == 0) {
    if (currentStep < steps) {
      tone(speaker, 400, 100);
      program[currentStep] = 4;
      currentStep++;
      whiteOn();
      delay(500);
      whiteOff();
    } else {
      tone(speaker, 200, 300);
      redOn();
      delay(500);
      redOff();
    }
  }
}

void play() {
  if (playing) {
    for (int i = 0; i < steps; i++) {
      runCommand(program[i]);
      //      Serial.println(program[i]);
    }
    playing = false;
    for (int i = 0; i < 3; i++) {
      whiteOn();
      tone(speaker, 400, 100);
      delay(100);
      whiteOff();
      delay(200);
    }
  }
}

void runCommand(int whichCommand) {
  switch (whichCommand) {
    case 0:
      break;
    case 1:
      forward();
      break;
    case 2:
      back();
      break;
    case 3:
      right();
      break;
    case 4:
      left();
      break;
  }
}

void whiteOn() {
  digitalWrite(ledBlueLeft, LOW);
  digitalWrite(ledGreenLeft, LOW);
  digitalWrite(ledRedLeft, LOW);
  digitalWrite(ledBlueRight, LOW);
  digitalWrite(ledGreenRight, LOW);
  digitalWrite(ledRedRight, LOW);
}

void whiteOff() {
  digitalWrite(ledBlueLeft, HIGH);
  digitalWrite(ledGreenLeft, HIGH);
  digitalWrite(ledRedLeft, HIGH);
  digitalWrite(ledBlueRight, HIGH);
  digitalWrite(ledGreenRight, HIGH);
  digitalWrite(ledRedRight, HIGH);
}

void redOn() {
  digitalWrite(ledRedLeft, LOW);
  digitalWrite(ledRedRight, LOW);
}
void redOff() {
  digitalWrite(ledRedLeft, HIGH);
  digitalWrite(ledRedRight, HIGH);
}

void greenOn() {
  digitalWrite(ledGreenLeft, LOW);
  digitalWrite(ledGreenRight, LOW);
}
void greenOff() {
  digitalWrite(ledGreenLeft, HIGH);
  digitalWrite(ledGreenRight, HIGH);
}

void blueOn() {
  digitalWrite(ledBlueLeft, LOW);
  digitalWrite(ledBlueRight, LOW);
}
void blueOff() {
  digitalWrite(ledBlueLeft, HIGH);
  digitalWrite(ledBlueRight, HIGH);
}
