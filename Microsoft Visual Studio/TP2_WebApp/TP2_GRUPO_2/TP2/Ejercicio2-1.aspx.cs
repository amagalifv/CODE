using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace TP2
{
    public partial class Ejercicio2_1 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void btnVerResumen_click(object sender, EventArgs e)
        {
            if (txtNombre.Text.Trim()=="" || txtApellido.Text.Trim()=="" || (clbTemas.SelectedIndex==-1))
            {
                lblMensajeError.Visible = true;
                lblMensajeError.Text = "Debe ingresar datos validos y seleccionar al menos un tema";
                txtNombre.Text = "";
                txtApellido.Text = "";
            }
            else
            {
                Server.Transfer("Ejercicio2-2.aspx");
            } 
        }
    }
}