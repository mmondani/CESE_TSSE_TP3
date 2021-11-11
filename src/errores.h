//void RegistrarMensaje (int gravedad, const char* funcion, int linea, const char* mensaje);

typedef void (* logger_t) (int gravedad, const char* funcion, int linea, const char* mensaje);