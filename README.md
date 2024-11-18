# MotorMeshCtrl

**MotorMeshCtrl** es un sistema de control remoto diseñado para gestionar motores eléctricos en vehículos eléctricos. Este proyecto se basa en sistemas embebidos utilizando microcontroladores ESP32 y el protocolo de comunicación inalámbrica **ESP-NOW**. La configuración incluye un controlador maestro con pantalla táctil y múltiples nodos esclavos, diseñados para realizar tareas como encendido, apagado y ajuste de límites de velocidad de los motores.

---

## Características del Proyecto

### Funcionalidades del Sistema
- Control remoto para hasta **20 nodos esclavos**.
- Comunicación inalámbrica con alcance mínimo de **30 metros**.
- Interfaz gráfica en pantalla táctil para monitoreo y ajustes.
- Protocolo de comunicación **ESP-NOW** con comunicación bidireccional.
- Ajustes independientes del límite de velocidad para cada motor.

### Arquitectura del Sistema
- **Controlador Maestro**: WT32-SC01 Plus (pantalla táctil basada en ESP32).
- **Controladores Esclavos**: ESP32 con terminal adapter.
- **Comunicación**: Protocolo ESP-NOW para comandos y retroalimentación.

### Datos Monitoreados
- Estado de cada motor (encendido/apagado).
- Porcentaje del límite de velocidad asignado.
- Velocidad actual del motor basada en la señal del pedal.

---

## Estructura del Proyecto

### Hardware Utilizado
- **WT32-SC01 Plus** (Maestro): Pantalla táctil con ESP32 integrada.
- **ESP32** (Esclavos): Microcontrolador con soporte para ESP-NOW.
- **Fuente de Alimentación**: Power Bank para el maestro, adaptador de corriente para los esclavos.
- **Motores Eléctricos**: Simulados o reales, dependiendo del alcance del proyecto.

### Software
- **Plataforma de Desarrollo**: Arduino IDE.
- **Protocolo de Comunicación**: ESP-NOW.
- **Interfaz Gráfica**: Creada para el WT32-SC01 Plus, diseñada para monitoreo y ajustes.

### Diagrama de Bloques


---

## Instrucciones de Uso

1. **Configuración Inicial**:
   - Conecta el WT32-SC01 Plus a una fuente de alimentación USB.
   - Configura cada nodo esclavo con el ESP32 y su respectivo motor.
   - Carga los programas correspondientes en el maestro y en los esclavos utilizando el Arduino IDE.

2. **Encendido del Sistema**:
   - Inicia el maestro y asegúrate de que detecte los nodos esclavos mediante el protocolo ESP-NOW.
   - Verifica que la pantalla táctil muestre el estado inicial de cada motor.

3. **Control del Sistema**:
   - Utiliza la pantalla táctil para encender/apagar motores y ajustar los límites de velocidad.
   - Monitorea los datos en tiempo real desde el maestro.

4. **Pruebas de Campo**:
   - Asegúrate de que la comunicación funcione correctamente dentro del alcance especificado.
   - Valida que los ajustes realizados desde el maestro se reflejen en los motores.

---

## Resultados Esperados

- Comunicación confiable entre el maestro y los esclavos dentro de un rango de 30 metros.
- Monitoreo en tiempo real del estado de los motores y sus parámetros de velocidad.
- Interfaz intuitiva para el control remoto de los motores.

---

## Contribuciones

Este proyecto es modular y admite mejoras, tales como:
- **Ampliación del Rango**: Uso de antenas externas para mejorar el alcance de la comunicación.
- **Optimización del Código**: Reducción de latencias en la comunicación entre el maestro y los esclavos.
- **Diseño de Enclosures**: Modelos 3D para proteger los dispositivos electrónicos.

---

## Licencia

Este proyecto es propiedad del cliente y está protegido bajo acuerdo de confidencialidad.  
Queda prohibida su distribución, reproducción o modificación sin autorización previa por escrito del cliente.  


---

## Créditos

Desarrollado por [Anthony Porras](https://github.com/AnthonyPorras), con experiencia en diseño de sistemas embebidos, control de motores y comunicación inalámbrica.
