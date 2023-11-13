<h1 align="center">Yggdrasil Robotics 2023/24</h1>
Repositorio del proyecto de robótica del año 2023/24. Aquí podéis ver el código del programa principal del robot 🤖

- Este es el enlace a la página de compra del <a href="https://www.amazon.es/dp/B07474MMB5?ref_=cm_sw_r_apan_dp_4TN2VR2GFVFQT9XKPC3N">kit</a><br/>
- Aquí tenéis los manuales del <a href="https://www.elegoo.com/en-es/blogs/arduino-projects/elegoo-smart-robot-car-kit-v4-0-tutorial">robot</a>

Notas:
Problemas al cargar el programa en una Arduino Mega2560 desde Ubuntu:
- warning: problema con 99-platformio-udev.rules
- solución: https://docs.platformio.org/en/latest/core/installation/udev-rules.html
- warning: *** [upload] could not open port /dev/ttyACM0: [Errno 13] Permission denied: '/dev/ttyACM0'
- solución: sudo chmod 666 /dev/ttyACM0
