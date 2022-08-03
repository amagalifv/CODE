#ifndef PROTOTIPOS_H_INCLUDED
#define PROTOTIPOS_H_INCLUDED

const char *AR_CLIENTES="Datos/clientes.dat";
const char *AR_ARTICULOS="Datos/articulos.dat";
const char *AR_VENTAS="Datos/ventas.dat";

const char *BK_CLIENTES="Datos/clientes.bkp";
const char *BK_ARTICULOS="Datos/articulos.bkp";
const char *BK_VENTAS="Datos/ventas.bkp";

const char *INI_CLIENTES="Datos/clientes.ini";
const char *INI_ARTICULOS="Datos/articulos.ini";
const char *INI_VENTAS="Datos/ventas.ini";

void cargarCadena(char *pal, int tam);

// clientes
void listarClientes();
int buscarPosDni(int dni);
int darDeBaja (int dni);
int cambiarFecha(int dni);
void restaurarEliminados();

int menuClientes();

//Articulos

int buscarPosArt(const char *cod);
void listarArticulos();
int cambiarPrecio(const char *cod);
int darDeBajaArt(char cod[5]);
bool siStock(int stockVendido, int pos);
void actualizarStock( int cant, int pos);
float modificarStockEnArt(int cantAnterior, const char *codigoArt, int cantActualizar);

int menuArtuculos();

//Ventas

float calcularImporte(int cant, char *cod);
int buscarPosVent(int ide);
void listarVentas();
int cambiarStockEnVenta( int cantActualizar, int id);

int menuVentas();

// Configuracion

bool moverArchivoObjClientes(const char*origen, const char*destino);
bool moverArchivoObjArticulos(const char*origen, const char*destino);
bool moverArchivoObjVentas(const char*origen, const char*destino);

int menuConfiguracion ();

#endif // PROTOTIPOS_H_INCLUDED

