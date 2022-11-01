using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Web;
using System.Data.SqlClient;

namespace TP6_AMFV.Clases
{
    public class GestionProductos
    {
        public GestionProductos(){ }

        private DataTable ObtenerTabla (String nomTabla, String miQuery)
        {
            DataSet tabla = new DataSet ();
            Conexion datos = new Conexion ();
            SqlDataAdapter adapta = datos.ObtenerAdaptador (miQuery);
            adapta.Fill(tabla, nomTabla);

            return tabla.Tables[nomTabla];
        }

        public DataTable obtenerTodosLosProductos ()
        {
            return ObtenerTabla("Productos", "SELECT * FROM Productos");
        }
        private void ArmarParametrosProductosEliminar(ref SqlCommand Comando, Producto producto)
        {
            SqlParameter SqlParametros = new SqlParameter();
            SqlParametros = Comando.Parameters.Add("@IdProducto", SqlDbType.Int);
            SqlParametros.Value = producto.idP;
        }
        
        private void ArmarParametrosProductos(ref SqlCommand Comando, Producto producto)
        {
            SqlParameter SqlParametros = new SqlParameter();
            SqlParametros = Comando.Parameters.Add("@IdProducto", SqlDbType.Int);
            SqlParametros.Value = producto.idP;
            SqlParametros = Comando.Parameters.Add("@NombreProducto", SqlDbType.NVarChar, 40);
            SqlParametros.Value = producto.nombreP;
            SqlParametros = Comando.Parameters.Add("@CantidadPorUnidad", SqlDbType.NVarChar, 20);
            SqlParametros.Value = producto.cantidadXuni;
            SqlParametros = Comando.Parameters.Add("@PrecioUnidad", SqlDbType.Money);
            SqlParametros.Value = producto.precioP;
        }
        
        public bool ActualizarProductos(Producto prod)
        {
            SqlCommand Comando = new SqlCommand();
            ArmarParametrosProductos(ref Comando, prod);
            Conexion ad = new Conexion();
            int FilasInsertadas = ad.EjecutaStoreProced(Comando, "SP_ActualizarProducto");
            
            if (FilasInsertadas == 1)
                return true;
            else
                return false;
        }

        public bool EliminarProductos(Producto prod)
        {
            SqlCommand Comando = new SqlCommand();
            ArmarParametrosProductosEliminar(ref Comando, prod);
            Conexion ad = new Conexion();
            int FilasInsertadas = ad.EjecutaStoreProced(Comando, "SP_EliminarProducto");
            
            if (FilasInsertadas == 1)
                return true;
            else
                return false;
        }
    }
}