/*varaible for use in 'for' loops*/
int index;
#define BUTTON_PIN 7
  
/*byte instead of #define to work with library functions*/
const byte ROWS = 4;
const byte COLS = 4;

const char keypadArray[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[] = {19,18,17,16};
byte colPins[] = {15,14,12,13};

/*shift register constants*/
#define DATA_PIN 2
#define STORAGE_CLOCK 3
#define SHIFT_CLOCK 4
#define PULSE_DELAY 5

/*seven segment display constants*/
const int sevenSeg[] = {126,48,109,121,51,91,95,112,127,115};
const byte displayOff = 128;
#define DISPLAY_DELAY 495

/*password tracking variables and constants*/
#define PASSWORD_LENGTH 4
const char password[] = "2552";

/*pin location on shift register outputs*/
/*SEG_1 0
  PIN_A 1
  PIN_B 2
  PIN_C 3
  PIN_D 4
  PIN_E 5
  PIN_F 6
  PIN_G 7*/

/*constants for LEDs*/
#define RED_LED 10
#define GREEN_LED 9
#define LED_DELAY 250
#define LED_ROTATIONS 3

/*including header files*/
#include <Keypad.h>

/*setting up objects*/
Keypad keypadInput = Keypad( makeKeymap(keypadArray), rowPins, colPins, ROWS, COLS);

/*-----------------------------------------------------------------------------------*/

/*main setup function*/
void setup() {

  /*initializing shift register / display pins*/
  pinMode(DATA_PIN,OUTPUT);
  pinMode(SHIFT_CLOCK,OUTPUT);
  pinMode(STORAGE_CLOCK,OUTPUT);
  pinMode(BUTTON_PIN,INPUT);

  /*initializing light pins*/
  pinMode(RED_LED,OUTPUT);
  pinMode(GREEN_LED,OUTPUT);

  /*initializing serial communication*/
  Serial.begin(9600);
}

/*-----------------------------------------------------------------------------------*/

/*function for displaying characters*/
void displayCharacter(char character);
/*function for pulsing shift register pins*/
void pulsePin(int pin);
/*function for clearing displays*/
void clearDisplay(void);
/*function for blinking correct LEDs*/
void blinkLed(int led);
/*function for turning on LEDs*/
void runPasswordCheck(void);

/*-----------------------------------------------------------------------------------*/

/*main loop function*/
char passwordCheck[PASSWORD_LENGTH+1];
char keyCharacter;

void loop(){
  runPasswordCheck();
}

/*-----------------------------------------------------------------------------------*/

/*function for running main password checking functionality*/
void runPasswordCheck(void){
  if(digitalRead(BUTTON_PIN) == HIGH){
    index = 0;
    Serial.println("yes");
    while( index < PASSWORD_LENGTH ){
      keyCharacter = keypadInput.getKey();
      if(keyCharacter){
        Serial.println(keyCharacter);
        displayCharacter(keyCharacter); 
        passwordCheck[index] = keyCharacter;
        index++;      
      }
    }
    if(strcmp(passwordCheck, password) == 0){
      blinkLed(GREEN_LED);
    }
    else{
      blinkLed(RED_LED);
    }    
  }
}

/*-----------------------------------------------------------------------------------*/

/*function for displaying number on the 7-segment display*/
void displayCharacter(char character){ 

  byte number;

  /*displaying "0"*/
  if(character == '0'){
    number = sevenSeg[0];
    Serial.println(number);
    shiftOut(DATA_PIN, SHIFT_CLOCK, LSBFIRST, number);
    pulsePin(STORAGE_CLOCK);
    delay(DISPLAY_DELAY);
    clearDisplay();
  }

  /*displaying "1"*/
  if(character == '1'){
    number = sevenSeg[1];
    Serial.println(number);
    shiftOut(DATA_PIN, SHIFT_CLOCK, LSBFIRST, number);
    pulsePin(STORAGE_CLOCK);
    delay(DISPLAY_DELAY);
    clearDisplay();
  }

  /*displaying "2"*/
  if(character == '2'){
    number = sevenSeg[2];
    Serial.println(number);
    shiftOut(DATA_PIN, SHIFT_CLOCK, LSBFIRST, number);
    pulsePin(STORAGE_CLOCK);
    delay(DISPLAY_DELAY);
    clearDisplay();
  }

  /*displaying "3"*/
  if(character == '3'){
    number = sevenSeg[3];
    Serial.println(number);
    shiftOut(DATA_PIN, SHIFT_CLOCK, LSBFIRST, number);
    pulsePin(STORAGE_CLOCK);
    delay(DISPLAY_DELAY);
    clearDisplay();
  }

  /*displaying "4"*/
  if(character == '4'){
    number = sevenSeg[4];
    Serial.println(number);
    shiftOut(DATA_PIN, SHIFT_CLOCK, LSBFIRST, number);
    pulsePin(STORAGE_CLOCK);
    delay(DISPLAY_DELAY);
    clearDisplay();
  }

  /*displaying "5"*/
  if(character == '5'){
    number = sevenSeg[5];
    Serial.println(number);
    shiftOut(DATA_PIN, SHIFT_CLOCK, LSBFIRST, number);
    pulsePin(STORAGE_CLOCK);
    delay(DISPLAY_DELAY);
    clearDisplay();
  }

  /*displaying "6"*/
  if(character == '6'){
    number = sevenSeg[6];
    Serial.println(number);
    shiftOut(DATA_PIN, SHIFT_CLOCK, LSBFIRST, number);
    pulsePin(STORAGE_CLOCK);
    delay(DISPLAY_DELAY);
    clearDisplay();
  }

  /*displaying "7"*/
  if(character == '7'){
    number = sevenSeg[7];
    Serial.println(number);
    shiftOut(DATA_PIN, SHIFT_CLOCK, LSBFIRST, number);
    pulsePin(STORAGE_CLOCK);
    delay(DISPLAY_DELAY);
    clearDisplay();    
  }

  /*displaying "8"*/
  if(character == '8'){
    number = sevenSeg[8];
    Serial.println(number);
    shiftOut(DATA_PIN, SHIFT_CLOCK, LSBFIRST, number);
    pulsePin(STORAGE_CLOCK);
    delay(DISPLAY_DELAY);
    clearDisplay();    
  }

  /*displaying "9"*/
  if(character == '9'){
    number = sevenSeg[9];
    Serial.println(number);
    shiftOut(DATA_PIN, SHIFT_CLOCK, LSBFIRST, number);
    pulsePin(STORAGE_CLOCK);
    delay(DISPLAY_DELAY);
    clearDisplay();    
  }
}

/*-----------------------------------------------------------------------------------*/

/*function for pulsing shift register pins*/
void pulsePin(int pin){
  digitalWrite(pin,HIGH);
  delay(PULSE_DELAY);
  digitalWrite(pin,LOW);    
}

/*-----------------------------------------------------------------------------------*/

/*function for clearing display*/
void clearDisplay(void){
  shiftOut(DATA_PIN,SHIFT_CLOCK,LSBFIRST,displayOff);
  pulsePin(STORAGE_CLOCK);
}

/*-----------------------------------------------------------------------------------*/

/*function for blinking correct LEDs*/
void blinkLed(int led){
  
  for(index = 0; index < LED_ROTATIONS; index++){
    digitalWrite(led,HIGH);
    delay(LED_DELAY);
    digitalWrite(led,LOW);
  }
}
