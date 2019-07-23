#define joyX A0
#define joyY A1

int xValue = 0;
int yValue = 0;

void setup() {
  Serial.begin(9600);    
  pinMode(joyX, INPUT);
  pinMode(joyY, INPUT);
}
 
void loop() {
  // put your main code here, to run repeatedly:
  xValue = analogRead(joyX);
  yValue = analogRead(joyY);
 
  //print the values with to plot or view
  Serial.print(xValue);
  Serial.print("\t");
  Serial.println(yValue);
}
