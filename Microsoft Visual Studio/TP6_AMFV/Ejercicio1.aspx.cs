using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using TP6_AMFV.Clases;

namespace TP6_AMFV
{
    public partial class Ejercicio1 : System.Web.UI.Page
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

            gwProductos.DataSource = gestProductos.obtenerTodosLosProductos();
            gwProductos.DataBind();
        }

        protected void gwProductos_RowDeleting(object sender, GridViewDeleteEventArgs e)
        {
            String sIdProducto = ((Label)gwProductos.Rows[e.RowIndex].FindControl("lbl_it_IdProd")).Text;

            Producto prod = new Producto();
            prod.idP = Convert.ToInt32(sIdProducto);

            GestionProductos gProdu = new GestionProductos();
            gProdu.EliminarProductos(prod);

            cargarGridView();
        }

        protected void gwProductos_RowEditing(object sender, GridViewEditEventArgs e)
        {
            gwProductos.EditIndex = e.NewEditIndex;
            cargarGridView();
        }

        protected void gwProductos_RowCancelingEdit(object sender, GridViewCancelEditEventArgs e)
        {
            gwProductos.EditIndex = -1;
            cargarGridView();
        }

        protected void gwProductos_RowUpdating(object sender, GridViewUpdateEventArgs e)
        {
            String sIdProducto = ((Label)gwProductos.Rows[e.RowIndex].FindControl("lbl_eit_IdProd")).Text;
            String sNomProd = ((TextBox)gwProductos.Rows[e.RowIndex].FindControl("txt_eit_NomProd")).Text;
            String sCantxUni = ((TextBox)gwProductos.Rows[e.RowIndex].FindControl("txt_eit_CantxUnidad")).Text;
            String sPrecioxUni = ((TextBox)gwProductos.Rows[e.RowIndex].FindControl("txt_eit_PrecioUni")).Text;

            Producto prod = new Producto();
            prod.idP = Convert.ToInt32(sIdProducto);
            prod.nombreP = sNomProd;
            prod.cantidadXuni = sCantxUni;
            prod.precioP = Convert.ToDecimal(sPrecioxUni);

            GestionProductos gProdu = new GestionProductos();
            gProdu.ActualizarProductos(prod);

            gwProductos.EditIndex = -1;
            cargarGridView();
        }
    }
}