volatile int pulseCount = 0;
unsigned long lastTime = 0;

void IRAM_ATTR onPulse()
{
    pulseCount++;
}

void setup()
{
    pinMode(18, INPUT);
    attachInterrupt(digitalPinToInterrupt(18), onPulse, RISING);
}

void loop()
{
    if (millis() - lastTime >= 1000)
    {
        int rpm = (pulseCount / 36.0) * 60;
        pulseCount = 0;
        lastTime = millis();
        Serial.println(rpm);
    }
}