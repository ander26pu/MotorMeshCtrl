// Configuración del pin de salida PWM
const int pwmPin = 25; // Pin GPIO que genera la señal PWM
const int pwmChannel = 0; // Canal del PWM (0 a 15 en ESP32)
const int pwmFreq = 1000; // Frecuencia del PWM en Hz
const int pwmResolution = 8; // Resolución del PWM en bits (8 bits = 0-255)

// Variables para controlar el aumento/disminución del valor PWM
int pwmValue = 0; // Valor actual de la señal PWM
int step = 5;     // Incremento/decremento del valor PWM

void setup() {
  // Configuración del canal PWM
  ledcSetup(pwmChannel, pwmFreq, pwmResolution);
  // Asignar el canal PWM al pin de salida
  ledcAttachPin(pwmPin, pwmChannel);

  // Inicializar comunicación serie para monitorear el estado
  Serial.begin(115200);
  Serial.println("Iniciando acelerador_test...");
}

void loop() {
  // Asignar el valor PWM al canal
  ledcWrite(pwmChannel, pwmValue);

  // Imprimir el valor PWM actual para monitoreo
  Serial.println(pwmValue);

  // Incrementar o decrementar el valor PWM
  pwmValue += step;

  // Invertir la dirección si llegamos al límite
  if (pwmValue >= 255 || pwmValue <= 0) {
    step = -step; // Cambia de incremento a decremento, o viceversa
  }

  // Retardo para suavizar el cambio
  delay(50); // Ajusta la velocidad de cambio (50 ms = 20 Hz de actualización)
}
