#ifndef PROTOTIPOS_H_INCLUDED
#define PROTOTIPOS_H_INCLUDED

const char *AR_CLIENTES="clientes.dat";
const char *AR_ARTICULOS="articulos.dat";
const char *AR_VENTAS="ventas.dat";

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
bool modificarStockEnArt(int cantAnterior, const char *codigoArt, int cantActualizar);

int menuArtuculos();

//Ventas

float calcularImporte(int cant, int pos);
int buscarPosVent(int ide);
void listarVentas();
int cambiarStockEnVenta( int cantActualizar, int id);

int menuVentas();

#endif // PROTOTIPOS_H_INCLUDED

