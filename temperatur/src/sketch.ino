int anpin = 0;


int tempr = 0;

void setup()
{
	Serial.begin(9600);
}

void loop()
{
	float tempr = 0;
	for(int i=0; i<10; i++){
		tempr = tempr + analogRead(anpin)/31+9;
		delay(100);
	}
	Serial.println(tempr/10);
	delay(100);
}
