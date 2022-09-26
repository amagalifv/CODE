using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Web;
using System.Data;
using System.Data.SqlClient;
using System.Web.UI.WebControls;

namespace TP5_AMFV
{
    public class DBConexion
    {
        private String rutaDB = "Data Source=DESKTOP-7KKQF17\\SQLEXPRESS;Initial Catalog=BDSucursales;Integrated Security=True";


        // devuelve la cantidad de filas afectadas
        public int ModificarDB(String consulta)
        {
            SqlConnection cnxDB = new SqlConnection(rutaDB);
            cnxDB.Open();

            SqlCommand cmd = new SqlCommand(consulta, cnxDB);
            
            int filasAfectadas = cmd.ExecuteNonQuery();

            cnxDB.Close();

            return filasAfectadas;
        }

        public void cargarDDL (DropDownList ddl, String tabla, String campoText, String campoValue)
        {
            SqlConnection cnxDB = new SqlConnection(rutaDB);

            SqlCommand cmd = new SqlCommand("Select * from " + tabla, cnxDB);
            cnxDB.Open();

            SqlDataReader datosTraidos = cmd.ExecuteReader();

            ddl.DataSource = datosTraidos;
            ddl.DataTextField = campoText;
            ddl.DataValueField = campoValue;

            ddl.DataBind();

            cnxDB.Close();
        }

        public void cargarGridView(String miQuery, GridView miGV)
        {
            SqlConnection cnxDB = new SqlConnection(rutaDB);
            cnxDB.Open();

            SqlCommand cmd = new SqlCommand(miQuery, cnxDB);

            SqlDataReader datRead = cmd.ExecuteReader();

            miGV.DataSource = datRead;
            miGV.DataBind();

            cnxDB.Close();
        }

    }
}