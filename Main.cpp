const int PIN_LOCK = 13;
const int PIN_OPEN = 12;
const int PIN_LED_G = 11;
const int PIN_LED_B = 10;
const int PIN_LED_R = 9;

const int EnableBridge = 7;
const int MotorF = 6;
const int MotorR = 5;

int Power = 0;
int buttonState = 0; 
bool Open = false;
void setup() {
	//Button
	pinMode(PIN_LOCK, INPUT);
	pinMode(PIN_OPEN, OUTPUT);
	
	//LED
	pinMode(PIN_LED_R, OUTPUT);
	pinMode(PIN_LED_G, OUTPUT);
	pinMode(PIN_LED_B, OUTPUT);
  
	//Morteur
    pinMode(MotorF,OUTPUT);
	pinMode(MotorR,OUTPUT);
	pinMode(EnableBridge,OUTPUT);
  
	displayColor(255, 255, 0);
}

void loop()
{
	Power = analogRead(A0);
	digitalWrite(EnableBridge,HIGH);
	buttonState = digitalRead(PIN_OPEN);
	if (digitalRead(PIN_LOCK) == HIGH){
		displayColor(255, 0, 0);
	}else{
		if (buttonState == HIGH && Open == false){
			analogWrite(MotorF,Power);
			analogWrite(MotorR,0);
			displayColor(0, 255,0);
			delay(15000);
			Open = true;	
		} else if (buttonState == LOW && Open  == true){
			analogWrite(MotorF,0);
			analogWrite(MotorR,Power);
			displayColor(0, 0, 255);
			delay(15000);
			Open = false;
			
		}
		analogWrite(MotorF,0);
		analogWrite(MotorR,0);
		digitalWrite(EnableBridge,LOW);
		displayColor(0, 0, 0);
		delay(1000);
	
	}


}
void displayColor(byte r, byte g, byte b) {
  analogWrite(PIN_LED_R, r);
  analogWrite(PIN_LED_G, g);
  analogWrite(PIN_LED_B, b);
}
