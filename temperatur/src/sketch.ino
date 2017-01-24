int anpin = 0;


int tempr = 0;

int ledpin = 2;

void setup()
{
	Serial.begin(9600);
	pinMode(ledpin, OUTPUT);
}

void loop()
{
	float tempr = 0;
	for(int i=0; i<10; i++){
		tempr = tempr + analogRead(anpin)/31+9;
		delay(100);
	}
	float temp = tempr/10;
	Serial.println(temp);
	if (temp < 18.00){
		digitalWrite(ledpin, HIGH);
	}
	else{
		digitalWrite(ledpin, LOW);
	}
	delay(100);
}
