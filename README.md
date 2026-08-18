# Algoritmos 2-26


Para darte cuenta de cuándo conviene usar un mapa en lugar de recorrer listas o vectores, hay tres señales clave que debes buscar en cualquier problema:
1. La pregunta central es sobre frecuencias, no sobre posiciones
   * Tu enfoque: Pensó en las listas como secuencias indexadas (posición `0`, posición `1`, etc.) e intentó "tachar" elementos por su índice (`usado1`, `usado2`).
   * La naturaleza del problema: Al problema no le importa dónde está el número ni en qué orden aparece. Solo importa: _"¿Cuántas veces aparece el número X en la lista A frente a la lista B?"_. Cuando el orden no influye y solo importan las repeticiones de cada valor, la estructura ideal es una tabla de conteo/frecuencias (`map` o `unordered_map` ).
     
2. El análisis de complejidad temporal (O(N . M) vs. O(N + M))
   * Tu código: Por cada uno de los $N$ elementos de `lista1`, ejecutas `std::find()` sobre `lista2`, que en el peor caso revisa sus M elementos. Esto da un costo de tiempo de O(N . M). Si N, M $\approx$ $10^5$, harías alrededor de $10^{10}$ operaciones (el límite estándar por segundo en jueces online suele ser  $\approx 10^8$, lo que causará Time Limit Exceeded).
   * Con `unordered_map`: Insertar y consultar toma tiempo promedio O(1). Procesar ambas listas requiere recorrerlas una sola vez: O(N + M) ($\approx$ 2 $\cdot$ $10^5$ operaciones), resolviéndose en milisegundos.
     
3. El rango de los valores (¿Array de frecuencias vs. Mapa?)
   * Si los valores de entrada fueran pequeños (por ejemplo, enteros entre 0 y 1000), un simple vector o array `vector<int> freq(1001)` sería suficiente y aún más rápido.
   * Si los valores pueden ser grandes (hasta $10^9$ o negativos), no puedes declarar un vector de ese tamaño en memoria. El `unordered_map` solo guarda memoria para los números que realmente aparecen.
   
Regla práctica para futuros problemas:

> _Si un ejercicio te pide comparar elementos compartidos, contar repeticiones o calcular intersecciones/diferencias entre colecciones sin importar el orden, usa un `unordered_map` (o std :: sort con técnica de dos punteros si prefieres evitar mapas)._
