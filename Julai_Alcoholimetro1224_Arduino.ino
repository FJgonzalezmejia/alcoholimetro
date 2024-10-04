// Pines
const int sensorPin = A0;  // Pin analógico donde está conectado el sensor MQ
const int ledVerde = 5;    // Pin para el LED verde
const int ledAmarillo = 6; // Pin para el LED amarillo
const int ledRojo = 7;     // Pin para el LED rojo
const int buzzerPin = 9;   // Pin para el zumbador

void setup() {
  Serial.begin(9600);             // Inicializa la comunicación serial
  pinMode(ledVerde, OUTPUT);      // Configura el pin del LED verde como salida
  pinMode(ledAmarillo, OUTPUT);   // Configura el pin del LED amarillo como salida
  pinMode(ledRojo, OUTPUT);       // Configura el pin del LED rojo como salida
  pinMode(buzzerPin, INPUT);     // Configura el pin del zumbador como salida
}

void loop() {
  int sensorValue = analogRead(sensorPin);   // Lee el valor analógico del sensor MQ
  float voltage = sensorValue * (5.0 / 1023.0); // Convierte el valor en voltaje (0-5V)

  // Mostrar valor y voltaje en el monitor serie
  Serial.print("Valor del sensor: ");
  Serial.print(sensorValue);  
  Serial.print("\tVoltaje: ");
  Serial.println(voltage);  // Usa println para añadir el salto de línea
  
  // Clasificación del nivel del sensor en tres niveles (bajo, medio, alto)
  if (sensorValue < 350) {
    // Nivel bajo: Enciende LED verde
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledAmarillo, LOW);
    digitalWrite(ledRojo, LOW);
    noTone(buzzerPin);  // Apaga el buzzer
  } else if (sensorValue >= 350 && sensorValue < 650) {
    // Nivel medio: Enciende LED amarillo
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAmarillo, HIGH);
    digitalWrite(ledRojo, LOW);
    noTone(buzzerPin);  // Apaga el buzzer
  } else {
    // Nivel alto: Enciende LED rojo y suena el buzzer
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAmarillo, LOW);
    digitalWrite(ledRojo, HIGH);
    tone(buzzerPin, 1000);  // Activa el buzzer con una frecuencia de 1000 Hz
  }

  delay(1000); // Espera 1 segundo antes de realizar la siguiente lectura
}

