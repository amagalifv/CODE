using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data;
using System.Data.SqlClient;

namespace TP4_AMFV
{
    public partial class WebForm3b : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            String idTema = Request.QueryString["idTe"];

            //gwLibros.DataSource = null;
            //gwLibros.DataBind();

            SqlConnection cnxDB = new SqlConnection();
            cnxDB.ConnectionString = "Data Source=DESKTOP-7KKQF17\\SQLEXPRESS;Initial Catalog=Libreria;Integrated Security=True";
            cnxDB.Open();

            SqlCommand cmd = new SqlCommand("SELECT * FROM Libros WHERE IdTema = "+idTema, cnxDB);

            SqlDataReader datRead = cmd.ExecuteReader();

            gwLibros.DataSource = datRead;
            gwLibros.DataBind();
        }

        protected void LinkButton1_Click(object sender, EventArgs e)
        {
            Response.Redirect("WebForm3.aspx?");
        }
    }
}