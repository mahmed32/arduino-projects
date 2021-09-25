#define GREEN_PIN 3
#define BLUE_PIN 5
#define RED_PIN 6
#define DELAY_TIME 1 //ms
#define COLOR_LIMIT 254
#define COLOR_STEP 50

short GREEN_COLOR_COUNTER = 0;
short BLUE_COLOR_COUNTER = 0;
short RED_COLOR_COUNTER = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  pinMode(RED_PIN, OUTPUT);
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(BLUE_PIN, LOW);
  digitalWrite(RED_PIN, LOW);
}

void loop()
{
  
  GREEN_COLOR_COUNTER = 0;
  while(GREEN_COLOR_COUNTER < COLOR_LIMIT)
  {
    BLUE_COLOR_COUNTER = 0;
    while(BLUE_COLOR_COUNTER < COLOR_LIMIT)
    {
      RED_COLOR_COUNTER = 0;
      while(RED_COLOR_COUNTER < COLOR_LIMIT)
      {
        analogWrite(GREEN_PIN, GREEN_COLOR_COUNTER);
        analogWrite(BLUE_PIN, BLUE_COLOR_COUNTER);
        analogWrite(RED_PIN, RED_COLOR_COUNTER);
        
        Serial.print("G: ");
        Serial.print(GREEN_COLOR_COUNTER);
        Serial.print(", B: ");
        Serial.print(BLUE_COLOR_COUNTER);
        Serial.print(", R: ");
        Serial.print(RED_COLOR_COUNTER);
        Serial.print('\n');
        
        delay(DELAY_TIME);
       	
        RED_COLOR_COUNTER += COLOR_STEP;
      }
      BLUE_COLOR_COUNTER += COLOR_STEP;
    }
    GREEN_COLOR_COUNTER += COLOR_STEP;
  }
}
