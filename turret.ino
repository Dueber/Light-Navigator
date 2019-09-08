
  // put your setup code here, to run once:
#include <Servo.h>

#define RHBOUND 45
#define LHBOUND 135
#define STEP 5
#define GREENLED 2 // green pin
#define YELWLED 3 // yellow pin
#define REDLED 4  // red pin
#define PHOTRES A0 // light sensor pin

Servo servo; // create servo object to control a servo

int pos = 90;
int lastPos = 90;
int lastDir = 1;
int dir = 1;
int photVal = 0;

void setup()
{
	Serial.begin(9600);

	//Set pins to outputs
	pinMode(GREENLED, OUTPUT);
	pinMode(YELWLED, OUTPUT);
	pinMode(REDLED,OUTPUT);

	servo.attach(9);  // attaches the servo on pin 9 to the servo object
	servo.write(pos);
}


void loop()
{
	photVal = analogRead(PHOTRES);

// put your main code here, to run repeatedly:
	if(photVal < 50){
		digitalWrite(REDLED, HIGH);
		sweep(&pos, &dir);
		if(dir != lastDir){
			lastDir = dir;
		}
	}
	else if(photVal >=50 && photVal <= 100){
		digitalWrite(YELWLED, HIGH);
	}
	else{
		digitalWrite(GREENLED, HIGH);
	}
	delay(100);
	digitalWrite(GREENLED, LOW);
	digitalWrite(YELWLED, LOW);
	digitalWrite(REDLED, LOW);
//	Serial.println(photVal);
}

void sweep(int *p, int *lastDir)
{
	switch(*lastDir)
	{
		case -1:
			if(*p > RHBOUND){
				*p -= STEP;
			}
			if(*p <= RHBOUND){
				*lastDir *= -1;
			}
			break;
		case 1:
			if(*p < LHBOUND){
				*p += STEP;
			}
			if(*p >= LHBOUND){
				*lastDir *= -1;
			}
			break;
	}
	Serial.println(*lastDir);
	servo.write(*p);
}
