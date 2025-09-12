# Tarea 1 - Sistemas Operativos 2025-2

<p align="left">
<img src="https://img.shields.io/badge/STATUS-COMPLETADO-green">
<img src="https://img.shields.io/badge/Platform-Linux-blue">
<img src="https://img.shields.io/badge/Language-C-orange">
</p>

## 📋 Descripción

Este proyecto implementa un **sistema de chat básico** desarrollado en C para sistemas Unix/Linux. El sistema consta de 3 procesos principales que se comunican entre sí mediante **pipes con nombre (FIFOs)**:

- **Cliente**: Interfaz para enviar mensajes y comandos
- **Log**: Sistema de registro que captura todos los mensajes
- **Reports**: Sistema de reportes para gestionar usuarios problemáticos

## ⚠️ Requisitos del Sistema

- **Sistema Operativo**: Linux (probado en Ubuntu)
- **Compilador**: GCC
- **Entorno Gráfico**: GNOME (para la funcionalidad de clonación)
- **Librerías**: Librerías estándar de C

> **Nota**: La funcionalidad de clonación de clientes solo funciona en distribuciones con GNOME instalado.

## 🚀 Instalación y Configuración

### 1. Clonar el repositorio
```bash
git clone https://github.com/TioSaturno/Tarea1-SO.git
cd Tarea1-SO
```

### 2. Compilar los programas
```bash
gcc client.c -o client
gcc log.c -o log
gcc reports.c -o reports
```

## 🔧 Instrucciones de Uso

### Paso 1: Abrir terminales
Abra **mínimo 4 terminales** y navegue a la carpeta del proyecto en cada una:
```bash
cd /ruta/hacia/el/proyecto
```

### Paso 2: Ejecutar los procesos
En **terminales separadas**, ejecute los siguientes comandos:

**Terminal 1 - Sistema de Log:**
```bash
./log
```

**Terminal 2 - Sistema de Reportes:**
```bash
./reports
```

**Terminal 3 y 4 - Clientes:**
```bash
./client
```

## 📖 Comandos Disponibles

Una vez ejecutando los clientes, puede usar los siguientes comandos:

| Comando | Descripción |
|---------|-------------|
| `mensaje` | Envía un mensaje normal al chat |
| `Reportar <PID>` | Reporta a un usuario específico por su PID |
| `Clonar` | Crea un nuevo cliente en una ventana separada |
| `Salir` | Desconecta el cliente del chat |

### Ejemplos de uso:
```
Hola a todos!
Reportar 1234
Clonar
Salir
```

## 🏗️ Arquitectura del Sistema

```
┌─────────────┐    FIFO: fifo_path    ┌─────────────┐
│   Cliente   │ ─────────────────────→ │     Log     │
│             │                       │             │
└─────────────┘                       └─────────────┘
       │
       │ FIFO: fifo_path_reports
       ↓
┌─────────────┐
│   Reports   │
│             │
└─────────────┘
```

## 🔄 Flujo de Funcionamiento

1. **Inicio**: Los procesos `log` y `reports` deben iniciarse primero
2. **Conexión**: Los clientes se conectan y pueden enviar mensajes
3. **Comunicación**: 
   - Mensajes normales → `log`
   - Comandos de reporte → `reports`
4. **Gestión de reportes**: Usuarios con 2+ reportes son automáticamente expulsados

## 🐛 Características del Sistema de Reportes

- Cada reporte se registra por PID del usuario
- Al alcanzar **2 reportes**, el usuario es automáticamente bloqueado
- El sistema mantiene un contador de reportes por usuario
- Los reportes se procesan en tiempo real

## 📁 Estructura de Archivos

```
Tarea1-SO/
├── client.c          # Código fuente del cliente
├── log.c             # Código fuente del sistema de log
├── reports.c         # Código fuente del sistema de reportes
├── README.md         # Este archivo
├── client            # Ejecutable del cliente (después de compilar)
├── log               # Ejecutable del log (después de compilar)
├── reports           # Ejecutable de reportes (después de compilar)
├── fifo_path         # FIFO para mensajes normales (se crea automáticamente)
└── fifo_path_reports # FIFO para reportes (se crea automáticamente)
```

## 🤝 Contribuciones

Este proyecto fue desarrollado como parte de la Tarea 1 del curso de Sistemas Operativos 2025-2.

---

**¡Gracias por su atención! 😊**