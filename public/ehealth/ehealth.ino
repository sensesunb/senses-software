#include < PinChangeInt.h >

const int LED = 13;

void readPulsioximeter(){
	cont++;
	if (cont == 50) { //Get only one 50 measures to reduce the latency
		eHealth.readPulsioximeter();
		cont = 0;
	}
}

void setup()
{
    Serial.begin(9600);
    PCintPort::attachInterrupt(6, readPulsioximeter, RISING);
}

void loop()
{
    int SPO2 = eHealth.getOxygenSaturation()
	int BPM = eHealth.getBPM()
    Serial.println(SPO2);
}
