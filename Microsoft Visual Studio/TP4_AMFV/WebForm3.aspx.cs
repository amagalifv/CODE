using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Data;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace TP4_AMFV
{
    public partial class WebForm3 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if (IsPostBack == false)
            {
                SqlConnection cnxDB = new SqlConnection("Data Source=DESKTOP-7KKQF17\\SQLEXPRESS;Initial Catalog=Libreria;Integrated Security=True");
                cnxDB.Open();

                DataSet datos = new DataSet();

                //Me traigo toda la tabla TEMAS
                SqlDataAdapter adaptador = new SqlDataAdapter("Select * from Temas", cnxDB);
                adaptador.Fill(datos, "Tabla Temas");

                // Me cargo lo que traje en DropDownList
                ddlTemas.DataSource = datos.Tables["Tabla Temas"];

                ddlTemas.DataTextField = "Tema";
                ddlTemas.DataValueField = "IdTema";
                ddlTemas.DataBind(); // lo muestra

                cnxDB.Close();
            }
        }

        protected void LinkButton1_Click(object sender, EventArgs e)
        {
            Response.Redirect("WebForm3b.aspx?idTe=" + ddlTemas.SelectedValue.ToString());
        }
    }
}