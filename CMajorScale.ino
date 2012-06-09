int cPin = 2;
int dPin = 3;
int ePin = 4;
int fPin = 5;
int gPin = 6;
int aPin = 8;
int bPin = 10;
int speakerPin = 13;


void setup( ) {
  pinMode(cPin, INPUT); 
  pinMode(dPin, INPUT); 
  pinMode(ePin, INPUT); 
  pinMode(fPin, INPUT); 
  pinMode(gPin, INPUT); 
  pinMode(aPin, INPUT); 
  pinMode(bPin, INPUT);   
  pinMode(speakerPin, OUTPUT);
}

void loop( ) {
  int state = digitalRead(cPin);
  if (state == HIGH) {     
    playNote( 'c', 100 );
  } 
  
  state = digitalRead(dPin);
  if (state == HIGH) {     
    playNote( 'd', 100 );
  } 

  state = digitalRead(ePin);
  if (state == HIGH) {     
    playNote( 'e', 100 );
  } 

  state = digitalRead(fPin);
  if (state == HIGH) {     
    playNote( 'f', 100 );
  } 

  state = digitalRead(gPin);
  if (state == HIGH) {     
    playNote( 'g', 100 );
  } 

  state = digitalRead(aPin);
  if (state == HIGH) {     
    playNote( 'a', 100 );
  } 

  state = digitalRead(bPin);
  if (state == HIGH) {     
    playNote( 'b', 100 );
  } 

}

void playTone(int tone, int duration) {
  for (long i = 0; i < duration * 1000L; i += tone * 2) {
    digitalWrite(speakerPin, HIGH);
    delayMicroseconds(tone);
    digitalWrite(speakerPin, LOW);
    delayMicroseconds(tone);
  }
}

void playNote(char note, int duration) {
  char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };
  int tones[] = { 1915, 1700, 1519, 1432, 1275, 1136, 1014, 956 };

  // toque o tom correspondente ao nome da nota
  for (int i = 0; i < 8; i++) {
    if (names[i] == note) {
      playTone(tones[i], duration);
    }
  }
}
