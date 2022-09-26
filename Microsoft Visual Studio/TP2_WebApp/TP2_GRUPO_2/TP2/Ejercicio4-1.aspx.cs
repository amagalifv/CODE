using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace TP2
{
    public partial class Ejercicio4_1 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void btnValidar_Click(object sender, EventArgs e)
        {
            if ((txtUsuario.Text == "Claudio") && (txtClave.Text == "Casas"))
            {
                Server.Transfer("Ejercicio4-2.aspx");
            }
            else
            {
                Server.Transfer("Ejercicio4-3.aspx");
            }
        }
    }
}