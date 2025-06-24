so_long

Mini‑juego en C desarrollado con la biblioteca gráfica MiniLibX (usada en 42), donde el jugador debe recoger todos los elementos del mapa y llegar a la salida en el mínimo de movimientos.
🧩 Características

    Renderizado en 2D con sprites (.xpm) y ventana gráfica.

    Movimiento del jugador con flechas o WASD.

    Contador de movimientos visible en consola o ventana.

    Validación de mapas .ber:

        Forma rectangular y rodeados de paredes (1).

        Contienen exactamente un jugador (P), al menos una salida (E) y uno o más coleccionables (C).

        Conexión válida: existe ruta hacia todos los coleccionables y la salida.

    Manejo de errores con mensajes descriptivos y salida limpia.

    Escape con tecla ESC o botón de cerrar ventana.


📘 Estructura del repositorio

src/                # Código fuente en C
include/            # Archivos `.h`
assets/             # Sprites `.xpm`
maps/               # Mapas ejemplo `.ber`
Makefile            # Reglas para compilar (all, bonus, clean, fclean, re)
get_next_line/      # Utilidad de lectura de líneas
mlx/                # MiniLibX (o clonado automáticamente)

🚀 Instalación y ejecución

    Clona el repositorio:

git clone https://github.com/Albertiito13/so_long
cd so_long

Asegúrate de tener instalada MiniLibX:

    En Linux: git clone https://github.com/42Paris/minilibx-linux.git mlx

Compila el ejecutable:

make   

Juega con un mapa .ber:

    ./so_long maps/mi_mapa.ber

🛠 Controles

    W, A, S, D : mover jugador.

    ESC: cerrar el juego / ventana.

🗺 Reglas de creación de mapas .ber

    Deben contener únicamente los caracteres 1, 0, C, E, P (y X para enemigos en bonus).

    Ser completamente rodeados por muros.

    Tener al menos un coleccionable y una salida, y exactamente un jugador.

    Ser planos (rectangulares) con rutas válidas.

    En caso de error, se imprime "Error\n" seguido de una descripción.
    

✅ Buenas prácticas

    Gestiona errores de forma clara.

    Evita fugas de memoria (usa free y mlx_destroy_*).

    Testea tus mapas con valgrind o herramientas similares.

🧠 Qué aprendí

    Uso de MiniLibX: creación de ventanas, detección de eventos, render de sprites.

    Parsing de mapas, structuras de datos (char **, flood‑fill).

    Manejo de memoria, Makefile modular.
