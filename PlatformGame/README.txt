Asunciones importantes del "motor":

- Por cómo se implementan algunos aspectos del juego (especialmente el tema de las colisiones), se asume que la posición X e Y de cualquier objeto en el juego es la esquina superior izquierda del objeto. Por tanto, para obtener la base (bottom) de un objeto, hay que hacer: position.getY() + size.getY().

Idea de colisiones y frames

El tema de las colisiones se puede resolver de dos formas:

1) (Como está ahora) 
En cada frame, PRIMERO se actualizan los objetos de juego, luego se detectan colisiones y se resuelven (ej. evitar superposiciones) y se dibujan.

2) (Como se podría cambiar)
En cada frame, PRIMERO se detectan colisiones, y esa información se usa para actualizar convenientemente los objetos de juego, y se dibujan.

1) parece más fácil en principio, porque 2) requeriría añadir un CollisionResolver al que se le pasara alguna estructura Contact. Seguramente sería más escalable, pero en principio 1) me va mejor porque es más simple. 

Hay información en los dos sentidos:

1) Sistema de colisión (onCollision) al update del siguiente frame
Esta información (ej. onStair) ha de ponerse a su valor por defecto al finalizar el update y será el sistema de colisión el que lo cambie (si es preciso) para el frame siguiente.

2) Update a sistema de colisión
Esta información (ej. goingDown) estará en su valor por defecto al inicio del update, el update la cambiará (si es preciso) y el sistema de colisión la usará para saber si tiene que hacer algo especial. 

Algo que me ha costado un poco: hacer que la velocidad del jugador vaya en relación con la velocidad de las plataformas móviles. La mejor solución sería hacer una estructura de árbol en la que cada entidad está jerarquizada y por tanto hereda la velocidad y aceleración de sus padres. Pero como ya no lo he hecho así de primera hora, he tenido que arreglármelas de otra forma. Lo que hago es que el jugador (player) tiene un objeto moving platform que se asigna cuando se detecta una colisión con un moving platform. Entonces

