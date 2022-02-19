//Auto Headlights

// LightThreshold is the brightness level needed to turn the lights off.
// 1000 is the max level and the higher the number is the brighter it must be for the lights to turn off.
// levels below the LightThreshold will turn the lights on, in testing the vf commodore was around 680.
const int LightThreshold = 650; 

// TimeToChange is the amount of time in seconds the light level must be above or below the LightThreshold to turn the lights on or off.
// 10 seconds is a decent amount of time to prevent the lights turning on and off rapidly.
const int TimeToChange = 10;



//--------------------there is no need to change anything below this line-----------------------------------
const int SensorPin = A1;
const int RelayPin = A5;
int lightLevel;
int OnTime;
int Offtime;
bool LightsON;
bool LightsOFF;


void setup() {
    pinMode(RelayPin, OUTPUT);
    lightLevel = analogRead(SensorPin);
    if (lightLevel > LightThreshold)
    {
        digitalWrite(RelayPin, LOW);
    }
    else
    {
        digitalWrite(RelayPin, HIGH);
    } 
}


void loop() {
    lightLevel = analogRead(SensorPin);
    if (lightLevel > LightThreshold)
    {
        Offtime = 0;
        OnTime++;
        if (OnTime > TimeToChange)
        {
            digitalWrite(RelayPin, LOW);
        }   
    }
    else
    {
        OnTime = 0;
        Offtime++;
        if (Offtime > TimeToChange)
        {
            digitalWrite(RelayPin, HIGH);
        }
    }
    delay(1000);
}


