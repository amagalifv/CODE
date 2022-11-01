using CapaNegocio;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace CapaVista
{
    public partial class EliminarSucursales : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void btnAceptar_Click(object sender, EventArgs e)
        {
            Boolean resultado;

            NegocioSucursal ns = new NegocioSucursal();

            resultado=ns.eliminarSucursal(Convert.ToInt32(txtIdSucursal.Text.ToString()));

            if (resultado)
            {
                lblResulEliminar.Text = "Se eliminó la sucursal con éxito";
                lblResulEliminar.ForeColor = System.Drawing.Color.Green;
                txtIdSucursal.Text = "";
            }
            else
            {
                lblResulEliminar.Text = "No se pudo agregas la sucursal";
            }
        }
    }
}