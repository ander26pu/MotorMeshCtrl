// Valor de porcentaje
const float porcentaje = 100.0;
const int maxPWM = 50 + (255 - 98) * porcentaje / 100.0;

// Configuración del pin ADC
const int pedalPin = 34; // Pin ADC donde está conectado el pedal (cambiar según conexión)
const int adcResolution = 12; // Resolución del ADC en bits (12 bits = 0-4095)

// Configuración del pin de salida PWM
const int pwmPin = 25; // Pin GPIO que genera la señal PWM
const int pwmChannel = 0; // Canal del PWM (0 a 15 en ESP32)
const int pwmFreq = 1000; // Frecuencia del PWM en Hz
const int pwmResolution = 8; // Resolución del PWM en bits (8 bits = 0-255)

// Variables para controlar el valor PWM
int pwmValue = 0; // Valor actual de la señal PWM

void setup() {
  // Configurar la resolución del ADC
  analogReadResolution(adcResolution); // Configuración de resolución en ESP32

  // Configuración del canal PWM
  ledcSetup(pwmChannel, pwmFreq, pwmResolution);
  // Asignar el canal PWM al pin de salida
  ledcAttachPin(pwmPin, pwmChannel);

  // Inicializar comunicación serie para monitorear el estado
  Serial.begin(115200);
  while (!Serial) {
    delay(10); // Esperar hasta que el puerto serie esté listo
  }
  Serial.println("Iniciando acelerador_pedal_test...");
}

void loop() {
  // Leer la señal analógica del pedal
  int pedalValue = analogRead(pedalPin);

  // Mapear el valor del pedal al rango PWM (asegura límites válidos)
  pwmValue = map(pedalValue, 800, 3000, 50, maxPWM);
  pwmValue = constrain(pwmValue, 0, 255); // Asegurar que el PWM esté dentro del rango

  // Asignar el valor PWM al canal
  ledcWrite(pwmChannel, pwmValue);

  // Imprimir el valor al Serial Plotter
  Serial.print("ADC Value: ");
  Serial.println(pedalValue);
  Serial.print("PWM Value: ");
  Serial.println(pwmValue);

  // Retardo para evitar saturar el puerto serie
  delay(10); // 100 Hz de muestreo
}
