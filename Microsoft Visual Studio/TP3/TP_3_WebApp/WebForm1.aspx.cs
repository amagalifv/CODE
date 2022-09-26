using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace TP_3_WebApp
{
    public partial class WebForm1 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void btnIrA_Click(object sender, EventArgs e)
        {
            Response.Redirect("WebForm2.aspx");
        }

        protected void btnGuardarUsu_Click(object sender, EventArgs e)
        {
            lblGuardado.Text = "";

            lblGuardado.Text = "Bienvenido usuario " + txtUsuario.Text;
            txtUsuario.Text = "";
            txtPass.Text = "";
            txtRepePass.Text = "";
            txtMail.Text = "";
            txtCP.Text = "";
            ddlLocalidades.SelectedIndex = 0;
        }

        protected void btnGuardarLoc_Click(object sender, EventArgs e)
        {
            lblGuardado.Text = "";

            bool bandera = true;

            foreach (ListItem aux in ddlLocalidades.Items)
            {
                if(aux.Text.ToUpper()== txtLocalidad.Text.ToUpper())
                {
                    bandera = false; break;
                }
            }

            if (bandera)
            {
                ddlLocalidades.Items.Add(txtLocalidad.Text);
            }
            txtLocalidad.Text = "";
        }
    }
}