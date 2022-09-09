
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


void loop() {
  // read the state of the pushbutton value:
  currentButtonState = digitalRead(buttonPin);
  // Serial.println(currentButtonState);
  
  // State detection for button
  if (currentButtonState != lastButtonState && currentButtonState == HIGH) {
    stateStartTime = millis();
    }
  
  // keep track of button pressed time
  if (currentButtonState == HIGH){
    buttonHoldTime = millis() - stateStartTime;
    //Serial.println("Press hold time:");
    //Serial.println(buttonHoldTime);
    
    // if button held 3s, blink leds, turn switch clocks on/off
    if (buttonHoldTime>3000) {
        onOffState = onOff(onOffState);
        Serial.println(onOffState);
        delay(300); // debounce
    }
  }
  if (currentButtonState == 0 && currentButtonState != lastButtonState && buttonHoldTime<3000) {
     Serial.println("switch clock");
    switch (activeLed){
        case ledPin1:
          digitalWrite(activeLed, LOW);
          activeLed = ledPin2;
          digitalWrite(activeLed, HIGH);
          Serial.println("change to pin2");
          break;
        case ledPin2:
          digitalWrite(activeLed, LOW);
          activeLed = ledPin1;
          digitalWrite(activeLed, HIGH); 
          Serial.println("change to pin1");
          break;
      Serial.println("test");
      Serial.println(activeLed);
    }
     delay(200); // debounce
  }

    lastButtonState = currentButtonState;

}


     

// function for turning clock on/off 
bool onOff(bool onOffState) {
  // if clock is off turn on LED
  if (onOffState == 0) {
    for ( int x = 0; x < 3; x++ ) {
      digitalWrite(activeLed, LOW);
      delay(200);
      digitalWrite(activeLed, HIGH);
      delay(500);
      Serial.println("turn on");
    }
  } else { 
    // if clock is on turn off LED
    for ( int x = 0; x < 3; x++ ) {
      digitalWrite(activeLed, HIGH);
      delay(500);
      digitalWrite(activeLed, LOW);
      delay(200);      
      Serial.println("turn off");
      }
    }
  Serial.println(onOffState);
  onOffState = !onOffState;
  Serial.println(onOffState);
  return onOffState;
  
}
  
    
    
