
const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin1 =  6; 
const int ledPin2 =  5; 

int activeLed = ledPin1;


// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

void setup(){
  pinMode(buttonPin,INPUT); // what does this do?
  pinMode(ledPin2,OUTPUT);
  pinMode(ledPin1,OUTPUT);
  Serial.begin(9600);
} 


void loop() {
  // read the state of the pushbutton value:
  
  buttonState = digitalRead(buttonPin);
  if (buttonState==HIGH){
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
  delay (100);         // debounce
  }
  
  
  }



