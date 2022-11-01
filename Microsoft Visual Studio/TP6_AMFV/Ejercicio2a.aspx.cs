using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using TP6_AMFV.Clases;

namespace TP6_AMFV
{
    public partial class Ejercicio2a : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if (IsPostBack == false)
            {
                cargarGridView();
            }
        }

        public void cargarGridView()
        {
            GestionProductos gestProductos = new GestionProductos();

            gwProductos2.DataSource = gestProductos.obtenerTodosLosProductos();
            gwProductos2.DataBind();
        }

        protected void gwProductos2_SelectedIndexChanging(object sender, GridViewSelectEventArgs e)
        {
            lblMostrarSeleccion.Text = "";

            String sIdProducto = ((Label)gwProductos2.Rows[e.NewSelectedIndex].FindControl("lbl_it_IdProd")).Text;
            String sNomProd = ((Label)gwProductos2.Rows[e.NewSelectedIndex].FindControl("lbl_it_NomProd")).Text;
            String sIdProve = ((Label)gwProductos2.Rows[e.NewSelectedIndex].FindControl("lbl_it_IdProve")).Text;
            String sPrecioxUni = ((Label)gwProductos2.Rows[e.NewSelectedIndex].FindControl("lbl_it_PrecioUni")).Text;

            lblMostrarSeleccion.Text ="Producto Agregado: " + sNomProd;

            if (Session ["Tabla"] == null)
            {
                Session["Tabla"]=crearTabla();
            }
            agregarFila((DataTable)Session["Tabla"], sIdProducto, sNomProd, sIdProve, sPrecioxUni);
        }

        public DataTable crearTabla()
        {
            DataTable dt = new DataTable();
            DataColumn col = new DataColumn("IdProducto", System.Type.GetType("System.String"));
            dt.Columns.Add(col);

            col = new DataColumn("NombreProducto", System.Type.GetType("System.String"));
            dt.Columns.Add(col);

            col = new DataColumn("IdProveedor", System.Type.GetType("System.String"));
            dt.Columns.Add(col);

            col = new DataColumn("PrecioUnitario", System.Type.GetType("System.String"));
            dt.Columns.Add(col);

            return dt;
        }

        public void agregarFila (DataTable tabla, String idProd, String nomProd, String idProv, String precio)
        {
            DataRow dr = tabla.NewRow();
            dr["IdProducto"] = idProd;
            dr["NombreProducto"] = nomProd;
            dr["IdProveedor"] = idProv;
            dr["PrecioUnitario"] = precio;
            tabla.Rows.Add(dr);
        }
    }
}