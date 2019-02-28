// Chris Wild
// 2019.2.28

// initialize constant variable values (globals)
const int rgbPin[] = { 6, 5, 3 }; // Red = pin D6, Green = pin D5, Blue = pin D3
const int Red = 0;
const int Green = 1;
const int Blue = 2;
const int delayTime = 10; //fading time between colors

void fade(int fromColor, int toColor)
{
  int fromValue = 255;
  int toValue = 0;

  for(int loop = 0; loop < 256; loop++)
  {
    analogWrite(rgbPin[fromColor], fromValue--);
    analogWrite(rgbPin[toColor], toValue++);
    delay(delayTime);
  }
}
void setup() {
  pinMode(rgbPin[Red], OUTPUT);
  pinMode(rgbPin[Green], OUTPUT);
  pinMode(rgbPin[Blue], OUTPUT);

  digitalWrite(Red, HIGH);
  digitalWrite(Green, LOW);
  digitalWrite(Blue, LOW);  
}

void loop() {
  fade(Red, Green);
  fade(Green, Blue);
  fade(Blue, Red);
}
