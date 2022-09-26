using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace TP4_AMFV
{
    public partial class WebForm2 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if (IsPostBack == false)
            {
                SqlConnection cnxDB = new SqlConnection();
                cnxDB.ConnectionString = "Data Source=DESKTOP-7KKQF17\\SQLEXPRESS;Initial Catalog=Neptuno;Integrated Security=True";
                cnxDB.Open();

                SqlCommand cmd = new SqlCommand("SELECT IdProducto, NombreProducto, IdCategoría, CantidadPorUnidad, PrecioUnidad FROM Productos", cnxDB);

                SqlDataReader datRead = cmd.ExecuteReader();

                gwTabla.DataSource = datRead;
                gwTabla.DataBind();
            }

        }

        protected void btnQuitFil_Click(object sender, EventArgs e)
        {
            SqlConnection cnxDB = new SqlConnection();
            cnxDB.ConnectionString = "Data Source=DESKTOP-7KKQF17\\SQLEXPRESS;Initial Catalog=Neptuno;Integrated Security=True";
            cnxDB.Open();

            SqlCommand cmd = new SqlCommand("SELECT IdProducto, NombreProducto, IdCategoría, CantidadPorUnidad, PrecioUnidad FROM Productos", cnxDB);

            SqlDataReader datRead = cmd.ExecuteReader();

            gwTabla.DataSource = datRead;
            gwTabla.DataBind();
        }

        protected void btnFiltrar_Click(object sender, EventArgs e)
        {
            String miQuery = "";
            miQuery= "SELECT IdProducto, NombreProducto, IdCategoría, CantidadPorUnidad, PrecioUnidad FROM Productos";

            if (txtIdProd.Text.Trim().Length != 0 && txtIdCat.Text.Trim().Length != 0)
            {
                miQuery += " WHERE IdProducto " + ddlProducto.SelectedValue.ToString() + " " + txtIdProd.Text.Trim() + " AND IdCategoría " + 
                ddlCategoria.SelectedValue.ToString() + " " + txtIdCat.Text.Trim();
            }
            else
            {
                if (txtIdProd.Text.Trim().Length != 0)
                {
                    miQuery += " WHERE IdProducto " + ddlProducto.SelectedValue.ToString() + " " + txtIdProd.Text.Trim();
                }

                if (txtIdCat.Text.Trim().Length != 0)
                {
                    miQuery += " WHERE IdCategoría " + ddlCategoria.SelectedValue.ToString() + " " + txtIdCat.Text.Trim();
                }
            }


            SqlConnection cnxDB = new SqlConnection("Data Source=DESKTOP-7KKQF17\\SQLEXPRESS;Initial Catalog=Neptuno;Integrated Security=True");
            cnxDB.Open();

            SqlCommand cmd = new SqlCommand(miQuery, cnxDB);

            SqlDataReader datRead = cmd.ExecuteReader();

            gwTabla.DataSource = datRead;
            gwTabla.DataBind();
        }
    }
}