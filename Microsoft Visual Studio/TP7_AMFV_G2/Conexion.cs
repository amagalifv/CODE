using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Data;
using System.Linq;
using System.Web;

namespace TP7_AMFV_G2
{
    public class Conexion
    {
        private String rutaDB = "Data Source=DESKTOP-7KKQF17\\SQLEXPRESS;Initial Catalog = BDSucursales; Integrated Security = True";

        public Conexion()
        {
            // Constructor
        }

        public SqlConnection EstablecerConexion()
        {
            SqlConnection cnxDB = new SqlConnection(rutaDB);

            try
            {
                cnxDB.Open();
                return cnxDB;
            }
            catch (Exception excp)
            {
                return null;
            }
        }

        public SqlDataAdapter ObtenerAdaptador(String miQuery)
        {
            SqlDataAdapter adaptador;

            try
            {
                adaptador = new SqlDataAdapter(miQuery, EstablecerConexion());
                return adaptador;
            }
            catch (Exception excp)
            {
                return null;
            }
        }

        public DataSet cargarDatosEnDataSet(String miQuery, String nombreTabla)
        {
            DataSet dSet = new DataSet();

            SqlConnection cnxDB = EstablecerConexion();

            SqlDataAdapter adapt = ObtenerAdaptador(miQuery);

            adapt.Fill(dSet, nombreTabla);

            cnxDB.Close();

            return dSet;
        }
    }
}