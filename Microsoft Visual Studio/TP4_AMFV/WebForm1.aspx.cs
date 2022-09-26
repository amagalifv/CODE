using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data.SqlClient;
using System.Data;

namespace TP4_AMFV
{
    public partial class WebForm1 : System.Web.UI.Page
    {
       
        protected void Page_Load(object sender, EventArgs e)
        {
            
            if (IsPostBack == false)
            {
                SqlConnection cnxDB = new SqlConnection("Data Source=DESKTOP-7KKQF17\\SQLEXPRESS;Initial Catalog=Viajes;Integrated Security=True");
                cnxDB.Open();

                DataSet datos = new DataSet();

                //Me traigo toda la tabla PROVINCIAS
                SqlDataAdapter adaptador = new SqlDataAdapter("Select * from Provincias", cnxDB);
                adaptador.Fill(datos, "Tabla Provincias");

                // Me cargo lo que traje en DropDownList de PROVINCIAS DESTINO INICIO
                ddlProvIni.DataSource = datos.Tables["Tabla Provincias"];

                ddlProvIni.DataTextField = "NombreProvincia";
                ddlProvIni.DataValueField = "IdProvincia";
                ddlProvIni.DataBind(); // lo muestra

                cnxDB.Close();
            }
        }

        protected void ddlProvIni_SelectedIndexChanged(object sender, EventArgs e)
        {
            ddlLocIni.Items.Clear();
            ddlProvFin.Items.Clear ();

            SqlConnection cnDB = new SqlConnection("Data Source=DESKTOP-7KKQF17\\SQLEXPRESS;Initial Catalog=Viajes;Integrated Security=True");
            cnDB.Open();

            DataSet datos2 = new DataSet();

            //PARA LOCALIDADES
            //Me traigo toda la tabla LOCALIDADES
            SqlDataAdapter adaptador2 = new SqlDataAdapter("Select * from Localidades", cnDB);
            adaptador2.Fill(datos2, "Tabla Localidades");


            foreach (DataRow aux in datos2.Tables["Tabla Localidades"].Rows)
            {

                if (ddlProvIni.SelectedValue.ToString() == aux["IdProvincia"].ToString())
                {
                    ddlLocIni.Items.Add(aux["NombreLocalidad"].ToString());
                }
            }

            //PARA PROVINCIAS DESTINO

            DataSet datos4 = new DataSet();

            //Me traigo toda la tabla PROVINCIAS
            SqlDataAdapter adaptador4 = new SqlDataAdapter("select * from Provincias", cnDB);
            adaptador4.Fill(datos4, "Tabla Provincias");

            foreach (DataRow aux in datos4.Tables["Tabla Provincias"].Rows)
            {

                if (ddlProvIni.SelectedValue.ToString() != aux["IdProvincia"].ToString())
                {
                    ddlProvFin.Items.Add(aux["NombreProvincia"].ToString());

                    ddlProvFin.DataValueField = aux["idProvincia"].ToString();

                }
            }

            cnDB.Close();
        }

        protected void ddlProvFin_SelectedIndexChanged(object sender, EventArgs e)
        {
            ddlLocFin.Items.Clear();

            SqlConnection cnDB = new SqlConnection("Data Source=DESKTOP-7KKQF17\\SQLEXPRESS;Initial Catalog=Viajes;Integrated Security=True");
            cnDB.Open();

            DataSet datos3 = new DataSet();

            //Me traigo toda la tabla LOCALIDADES
            SqlDataAdapter adaptador2 = new SqlDataAdapter("Select * from Localidades", cnDB);
            adaptador2.Fill(datos3, "Tabla Localidades");


            foreach (DataRow aux in datos3.Tables["Tabla Localidades"].Rows)
            {

                if (ddlProvFin.SelectedValue.ToString() == aux["IdProvincia"].ToString())
                {
                    ddlLocFin.Items.Add(aux["NombreLocalidad"].ToString());
                }
            }

            cnDB.Close();
        }
    }
}