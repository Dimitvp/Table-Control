//Lamp Light
int lamp1 = 8;
int lamp2 = 13;

//*****Start Buttons*****
//Start button(Old var name - button1)
const int  startButton = 2;
//No Down button(Old var name - button2)
const int noDownButton = 1;

const int buttonLup = 3;
const int buttonLdown = 4;
const int buttonRup = 5;
const int buttonRdown = 6;
//No Up button(Old var name - button3)
const int noUpButton = 7;

int Lup = 9;
int Ldown = 10;
int Rup = 11;
int Rdown = 12;
//*****End Buttons*****

int startButtonState = 0;
int noDownButtonState = 0;
int noUpButtonState = 0;

//Lamps Blinking
bool simulation = false;

bool upPermit = false;
bool downPermit = false;

//Old var name - buttonPoslednoSustoianie
int buttonLastState_1 = LOW;
int buttonLastState_2 = LOW;
int buttonLastState_3 = LOW;
int buttonLastState_4 = LOW;

//Old var name - vremeIzchakvane
long timeDelay  = 500;

//Old var name - poslednoVrermePrevkliuchvane
long lastTimeSwitch_1 = 0;
long lastTimeSwitch_2 = 0;
long lastTimeSwitch_3 = 0;
long lastTimeSwitch_4 = 0;

void setup() {
	pinMode(lamp1, OUTPUT);
	pinMode(lamp2, OUTPUT);
	pinMode(startButton, INPUT);
	pinMode(noDownButton, INPUT);
	pinMode(buttonLup, INPUT);
	pinMode(buttonLdown, INPUT);
	pinMode(buttonRup, INPUT);
	pinMode(buttonRdown, INPUT);
	pinMode(Lup, OUTPUT);
	pinMode(Ldown, OUTPUT);
	pinMode(Rup, OUTPUT);
	pinMode(Rdown, OUTPUT);

	digitalWrite(lamp1, LOW);
	digitalWrite(lamp2, LOW);
	digitalWrite(Lup, HIGH);
	digitalWrite(Ldown, HIGH);
	digitalWrite(Rup, HIGH);
	digitalWrite(Rdown, HIGH);
}

void loop() {
	startButtonState = digitalRead(startButton);
	if (startButtonState == HIGH && !simulation) {
		digitalWrite(lamp1, HIGH);
		delay(40);
		digitalWrite(lamp1, LOW);
		delay(1400);
		digitalWrite(lamp1, HIGH);
		digitalWrite(lamp2, HIGH);
		delay(50);
		digitalWrite(lamp1, LOW);
		digitalWrite(lamp2, HIGH);
		delay(500);
		digitalWrite(lamp1, HIGH);
		digitalWrite(lamp2, LOW);
		delay(300);
		digitalWrite(lamp1, LOW);
		digitalWrite(lamp2, HIGH);
		delay(1000);
		digitalWrite(lamp1, HIGH);
		digitalWrite(lamp2, LOW);
		delay(20);
		digitalWrite(lamp1, LOW);
		digitalWrite(lamp2, HIGH);
		delay(200);
		digitalWrite(lamp1, HIGH);
		digitalWrite(lamp2, LOW);
		delay(30);
		digitalWrite(lamp1, LOW);
		digitalWrite(lamp2, HIGH);
		delay(50);
		digitalWrite(lamp1, HIGH);
		digitalWrite(lamp2, LOW);
		delay(300);
		digitalWrite(lamp1, LOW);
		digitalWrite(lamp2, HIGH);
		delay(20);
		digitalWrite(lamp1, HIGH);
		digitalWrite(lamp2, LOW);
		delay(20);
		digitalWrite(lamp1, LOW);
		digitalWrite(lamp2, HIGH);
		delay(200);
		digitalWrite(lamp1, HIGH);
		digitalWrite(lamp2, LOW);
		delay(30);
		digitalWrite(lamp1, LOW);
		digitalWrite(lamp2, HIGH);
		delay(50);
		digitalWrite(lamp1, HIGH);
		digitalWrite(lamp2, LOW);
		delay(300);
		digitalWrite(lamp1, LOW);
		digitalWrite(lamp2, HIGH);
		delay(20);
		digitalWrite(lamp1, HIGH);
		digitalWrite(lamp2, LOW);
		delay(20);
		digitalWrite(lamp1, LOW);
		digitalWrite(lamp2, HIGH);
		delay(200);
		digitalWrite(lamp1, HIGH);
		digitalWrite(lamp2, LOW);
		delay(30);
		digitalWrite(lamp1, LOW);
		digitalWrite(lamp2, HIGH);
		delay(50);
		digitalWrite(lamp1, HIGH);
		digitalWrite(lamp2, LOW);
		delay(300);
		digitalWrite(lamp1, LOW);
		digitalWrite(lamp2, HIGH);
		delay(20);
		digitalWrite(lamp1, HIGH);
		digitalWrite(lamp2, LOW);
		delay(20);
		digitalWrite(lamp1, LOW);
		digitalWrite(lamp2, HIGH);
		delay(200);
		digitalWrite(lamp1, HIGH);
		digitalWrite(lamp2, LOW);
		delay(30);
		digitalWrite(lamp1, LOW);
		digitalWrite(lamp2, HIGH);
		delay(50);
		digitalWrite(lamp1, HIGH);
		digitalWrite(lamp2, LOW);
		delay(300);
		digitalWrite(lamp1, LOW);
		digitalWrite(lamp2, HIGH);
		delay(20);
		digitalWrite(lamp1, HIGH);
		digitalWrite(lamp2, LOW);
		delay(20);
		digitalWrite(lamp1, LOW);
		digitalWrite(lamp2, HIGH);
		delay(200);
		digitalWrite(lamp1, HIGH);
		digitalWrite(lamp2, LOW);
		delay(30);
		digitalWrite(lamp1, LOW);
		digitalWrite(lamp2, HIGH);
		delay(50);
		digitalWrite(lamp1, HIGH);
		digitalWrite(lamp2, LOW);
		delay(300);
		digitalWrite(lamp1, LOW);
		digitalWrite(lamp2, HIGH);
		delay(20);
		digitalWrite(lamp1, HIGH);
		digitalWrite(lamp2, HIGH);
		simulation = true;
		upPermit = false;
		downPermit = true;
	}

	noDownButtonState = digitalRead(noDownButton);
	if (noDownButtonState == HIGH) {
		downPermit = false;
	}
	else {
		downPermit = true;
	}

	noUpButtonState = digitalRead(noUpButton);
	if (noUpButtonState == HIGH) {
		upPermit = false;
	}
	else {
		digitalWrite(lamp1, LOW);
		digitalWrite(lamp2, LOW);
		upPermit = true;
	}

	//Up Permit
	if (upPermit && simulation) {

		//*****Left Lamp UP Begin*****
		//Old var name - reading_1
		int readingButtonLUp = digitalRead(buttonLup);

		if (readingButtonLUp != buttonLastState_1) {
			lastTimeSwitch_1 = millis();
		}
		if ((millis() - lastTimeSwitch_1) > timeDelay ) {
			if (readingButtonLUp == HIGH) {
				digitalWrite(Lup, LOW);
			}
		}
		else {
			digitalWrite(Lup, HIGH);
		}
		buttonLastState_1 = readingButtonLUp;

		//Lamp light
		if (readingButtonLUp == HIGH) {
			digitalWrite(lamp1, LOW);
		}
		else {
			digitalWrite(lamp1, HIGH);
		}
		//*****Left Lamp UP End*****

		//*****Right Lamp UP Begin*****
		//Old var name - reading_3
		int readingButtonRUp = digitalRead(buttonRup);

		if (readingButtonRUp != buttonLastState_3) {
			lastTimeSwitch_3 = millis();
		}
		if ((millis() - lastTimeSwitch_3) > timeDelay ) {
			if (readingButtonRUp == HIGH) {
				digitalWrite(Rup, LOW);
			}
		}
		else {
			digitalWrite(Rup, HIGH);
		}
		buttonLastState_3 = readingButtonRUp;

		//Lamp light
		if (readingButtonRUp == HIGH) {
			digitalWrite(lamp2, LOW);
		}
		else {
			digitalWrite(lamp2, HIGH);
		}
		//*****Right Lamp UP End*****

	}

	//Down Permit
	if (downPermit && simulation) {

		//*****Left Lamp Down Begin*****
		//Old var name - reading_2
		int readingButtonLDown = digitalRead(buttonLdown);

		if (readingButtonLDown != buttonLastState_2) {
			lastTimeSwitch_2 = millis();
		}
		if ((millis() - lastTimeSwitch_2) > timeDelay ) {
			if (readingButtonLDown == HIGH) {
				digitalWrite(Ldown, LOW);
			}
		}
		else {
			digitalWrite(Ldown, HIGH);
		}
		buttonLastState_2 = readingButtonLDown;

		//Lamp light
		if (readingButtonLDown == HIGH) {
			digitalWrite(lamp1, LOW);
		}
		else {
			digitalWrite(lamp1, HIGH);
		}
		//*****Left Lamp Down End*****

		//*****Right Lamp Down Begin*****
		//Old var name - reading_4
		int readingButtonRDown = digitalRead(buttonRdown);

		if (readingButtonRDown != buttonLastState_4) {
			lastTimeSwitch_4 = millis();
		}
		if ((millis() - lastTimeSwitch_4) > timeDelay ) {
			if (readingButtonRDown == HIGH) {
				digitalWrite(Rdown, LOW);
			}
		}
		else {
			digitalWrite(Rdown, HIGH);
		}
		buttonLastState_4 = readingButtonRDown;

		//Lamp light
		if (readingButtonRDown == HIGH) {
			digitalWrite(lamp2, LOW);
		}
		else {
			digitalWrite(lamp2, HIGH);
		}
		//*****Left Lamp Down End*****

	}

	/*noDownButtonState = digitalRead(noDownButton);
	if (noDownButtonState == HIGH) {
		downPermit = false;
	}
	else {
		downPermit = true;
	}

	noUpButtonState = digitalRead(noUpButton);
	if (noUpButtonState == HIGH) {
		upPermit = false;
	}
	else {
		digitalWrite(lamp1, LOW);
		digitalWrite(lamp2, LOW);
		upPermit = true;
	}*/

}

