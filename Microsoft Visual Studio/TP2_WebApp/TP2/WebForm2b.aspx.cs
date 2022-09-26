using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace TP2
{
    public partial class WebForm2b : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            String nombre;
            String apellido;
            String ciudad;
            CheckBoxList temas;

            nombre = Request["txtNombre"].ToString().Trim();
            apellido = Request["txtApellido"].ToString().Trim();
            ciudad = Request["ddlCiudad"].ToString().Trim();
            temas = (CheckBoxList)PreviousPage.FindControl("cblTemas");

            if (nombre.Length !=0)
            {
                lblMensaje.Text += "<br/><b>•<u>Nombre:</u></b> " + nombre;
            }

            if (apellido.Length != 0)
            {
                lblMensaje.Text += "<br/><br/><b>•<u>Apellido:</u></b> " + apellido;
            }

            lblMensaje.Text += "<br/><br/><b>•<u>Ciudad:</u></b> " + ciudad;

            lblMensaje.Text += "<br/><br/><b>•<u>Los temas elegidos son:</u></b><br/>";
            foreach (ListItem aux in temas.Items)
            {
                if (aux.Selected==true)
                {
                    lblMensaje.Text += "&nbsp;&nbsp;&nbsp;&nbsp;" + aux.Text + "<br/>";
                }
            }
        }
    }
}