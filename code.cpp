
const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin1 =  6; 
const int ledPin2 =  5; 


int activeLed = ledPin1;


// variables will change:
//int buttonState = 0;         // variable for reading the pushbutton status
  unsigned long pressStartTime;
  unsigned long pressStopTime;
  unsigned long stateStartTime;
  unsigned long buttonHoldTime = 0;
  int lastButtonState = 0;
  int currentButtonState = 0;
  bool onOffState = 0;
  
void setup(){
  pinMode(buttonPin,INPUT); // what does this do?
  pinMode(ledPin2,OUTPUT);
  pinMode(ledPin1,OUTPUT);
  Serial.begin(9600);
} 

// redifined functionality:
// while holding button, time is tracked, if time reaches 2 seconds
// all clocks start or stop

void loop() {
  // read the state of the pushbutton value:

  currentButtonState = digitalRead(buttonPin);
  
  // State detection for button
  if (currentButtonState != lastButtonState) {
    stateStartTime = millis();
    lastButtonState = currentButtonState;
    Serial.println(stateStartTime);
    
    // if currentButtonState == LOW
  }
  
  // keep track of button pressed time
  if (currentButtonState == HIGH){
    buttonHoldTime = millis() - stateStartTime;
    
    Serial.println("Press hold time:");
    Serial.println(buttonHoldTime);
    
    // if button held 3s, blink leds, turn state to "off"
    
    // todo: need more state detection in a separate function. 
    // when turned on or off, what happens to the light or sound
    if (buttonHoldTime > 3000) {
      onOffState = onOff(onOffState);
      Serial.println(onOffState);
      }
      
    }
    // need an on-off state
  } 
//     else {
//    buttonHoldTime=0;
//  }
      
      // if button has been held 3 seconds, start or stop both clocks

 
bool onOff(bool onOffState) {

  for ( int x = 0; x < 3; x++ ) {
    digitalWrite(activeLed, LOW);
    delay(200);
    digitalWrite(activeLed, HIGH);
    delay(500);
    
  onOffState = !onOffState;
  
  return onOffState;
  }
}
  