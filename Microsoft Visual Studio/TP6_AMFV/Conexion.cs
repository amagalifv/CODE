using System;
using System.Collections.Generic;
using System.Data;
using System.Data.SqlClient;
using System.Linq;
using System.Web;

namespace TP6_AMFV.Clases
{
    public class Conexion
    {
        private String rutaDB = "Data Source=DESKTOP-7KKQF17\\SQLEXPRESS;Initial Catalog=Neptuno;Integrated Security=True";

        public Conexion ()
        {
            // Constructor
        }

        public SqlConnection EstablecerConexion ()
        {
            SqlConnection cnxDB = new SqlConnection (rutaDB);

            try
            {
                cnxDB.Open ();
                return cnxDB;
            }
            catch (Exception excp)
            {
                return null;
            }
        }

        public SqlDataAdapter ObtenerAdaptador(String consulta)
        {
            SqlDataAdapter adaptador;

            try
            {
                adaptador = new SqlDataAdapter(consulta, EstablecerConexion());
                return adaptador;
            }
            catch (Exception excp)
            {
                return null;
            }
        }

        public int EjecutaStoreProced (SqlCommand comando, String nombreStoreProced)
        {
            int filasAfectadas;

            SqlConnection cnxDB = EstablecerConexion();
            
            SqlCommand cmd = new SqlCommand();
            cmd = comando;
            cmd.Connection = cnxDB;
            cmd.CommandType = CommandType.StoredProcedure;
            cmd.CommandText = nombreStoreProced;

            filasAfectadas = cmd.ExecuteNonQuery();
            cnxDB.Close();
            
            return filasAfectadas;

        }
    }
}