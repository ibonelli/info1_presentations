#define FIFO_IDA fifo_srv_db
#define FIFO_VUELTA fifo_db_srv

typedef enum {
	FALSE = 0,
	TRUE = 1
} boolean;

typedef struct {
	long telefono;
	char nombre[50];
	char direccion[50];
	int cant_pedidos;
} cliente;

typedef enum {
	POLLO,
	CARNE,
	JYQ,
	HUMITA
} sabores;

typedef enum {
	exito,
	fallo,
	consulta,
	escribir,
	actualizar	
} cmdFifo;

typedef struct {
	int empanada[4];
} pedido;

/*
 * Funciones del cliente
 */
long pedirTel(void);
long ingresoUsrTel(void);
cliente ingresoUsr(long tel);
pedido tomarPedido(void);

/*
 * Funciones del servidor
 */
void atenderCliente(void);
cliente consultaTel(long);
boolean guardarCliente(cliente);
boolean actualizarCliente(long,int);

/*
 * Funciones DB
 */
cliente dbConsultaTel(long);
boolean dbGuardarCliente(cliente);
boolean dbActualizarCliente(long,int);
