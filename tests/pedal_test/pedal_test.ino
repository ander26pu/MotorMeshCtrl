// Configuración del pin ADC
const int pedalPin = 34; // Pin ADC donde está conectado el pedal (cambiar según conexión)
const int adcResolution = 12; // Resolución del ADC en bits (12 bits = 0-4095)

void setup() {
  // Configurar la resolución del ADC
  analogReadResolution(adcResolution); // Configuración de resolución en ESP32
  
  // Inicializar comunicación serie
  Serial.begin(115200); // Velocidad de comunicación con el PC
  while (!Serial) {
    delay(10); // Esperar hasta que el puerto serie esté listo
  }
  Serial.println("Iniciando pedal_test...");
}

void loop() {
  // Leer la señal analógica del pedal
  int pedalValue = analogRead(pedalPin);
  
  // Imprimir el valor al Serial Plotter
  Serial.println(pedalValue);
  
  // Retardo para evitar saturar el puerto serie
  delay(10); // 100 Hz de muestreo
}