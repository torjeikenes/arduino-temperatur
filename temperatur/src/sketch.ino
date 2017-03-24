int anpin = 0;
int tempr = 0;
int ledpin = 2;

void setup()
{
	//Setter opp forbindelse med datamaskinen	
	Serial.begin(9600);
	pinMode(ledpin, OUTPUT);
}

void loop()
{
	//setter temperaturen til 0
	float tempr = 0;
	//leser temperaturen 10 ganger
	for(int i=0; i<10; i++){
		tempr = tempr + analogRead(anpin)/31+9; //deler på 31 og plusser på 9 for å få Celsius
		delay(100);
	}
	//deler på 10 for å få gjennomsnitt
	float temp = tempr/10;
	//sender temperaturen til pcen
	Serial.println(temp);

	//skrur på lys om temperaturen er over 18 grader
	if (temp < 18.00){
		digitalWrite(ledpin, HIGH);
	}
	else{
		digitalWrite(ledpin, LOW);
	}
	delay(100);
}
