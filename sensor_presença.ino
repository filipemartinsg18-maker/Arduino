// ================================================
// Sensor de Presença com PIR
// Autor: Filipe Martins
// Detecta movimento e aciona LED por 5s
// ================================================

#include <Arduino.h>

// Variáveis de controle
bool estadoLed = false;
bool estadoSensor;
bool estadoAnterior = false;
unsigned long tempoUltimoMovimento = 0;

void setup()
{
    pinMode(2, INPUT);   // Sensor PIR — pino 2
    pinMode(13, OUTPUT); // LED — pino 13
    Serial.begin(9600);
}

void loop()
{
    estadoSensor = digitalRead(2); // Lê o estado do sensor

    // Detectou novo movimento (detecção de borda)
    if (estadoSensor && !estadoAnterior)
    {
        tempoUltimoMovimento = millis(); // Marca o tempo do movimento
        Serial.println("Movimento detectado!");
    }

    // Mantém o LED ligado por 5 segundos após o último movimento
    if (millis() - tempoUltimoMovimento < 5000)
    {
        digitalWrite(13, HIGH);
        estadoLed = true;
    }
    else
    {
        digitalWrite(13, LOW);
        estadoLed = false;
    }

    estadoAnterior = estadoSensor; // Atualiza o estado anterior
}
