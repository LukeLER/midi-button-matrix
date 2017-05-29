/*
 * MIDI Controller Button Matrix
 * Lukas Lauer
 * 21.05.2017
 *
 * For use as lightning controller for MAdot2 or similar.
*/

int ON = 100;
int OFF = 0;
int CMD =0x90;

//Define Midi Notes
int notes[] = {128, 127, 126, 125, 124, 123, 122, 121, 120, 119, 118};
int pressed[] = {0,0,0,0,0,0,0,0,0,0,0};

void setup() {
  //Set MIDI baud rate:
  Serial.begin(31250);

  //Buttons
  pinMode(8, INPUT);           
  digitalWrite(8, HIGH);       
  pinMode(9, INPUT);           
  digitalWrite(9, HIGH); 
}

void loop() {
//================================
  if(digitalRead(8) == LOW)
  {
    if(pressed[1] == 0)
    {
      noteOn(CMD, notes[1], ON);
      pressed[1] = 1;
    }
  }
  else
  {
    if(pressed[1] == 1)
    {
      noteOn(CMD, notes[1], OFF);
      pressed[1] = 0;
    }
  }
//================================

//================================
  if(digitalRead(9) == LOW)
  {
    if(pressed[2] == 0)
    {
      noteOn(CMD, notes[2], ON);
      pressed[2] = 1;
    }
  }
  else
  {
    if(pressed[2] == 1)
    {
      noteOn(CMD, notes[2], OFF);
      pressed[2] = 0;
    }
  }
//================================
}

//Play a MIDI note

void noteOn(int cmd, int pitch, int velocity) {
  Serial.write(cmd);
  Serial.write(pitch);
  Serial.write(velocity);
}
