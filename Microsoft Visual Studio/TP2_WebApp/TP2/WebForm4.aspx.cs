using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace TP2
{
    public partial class WebForm4 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void btnValidar_Click1(object sender, EventArgs e)
        {
            if (txtUsuario.Text.ToUpper() == "CLAUDIO" && txtPass.Text == "Casas")
            {
                Response.Redirect("WebForm4_Valido.aspx?usu="+txtUsuario.Text);
            }
            else
            {
                Response.Redirect("WebForm4_Invalido.aspx");
            }
        }
    }
}