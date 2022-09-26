using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace TP2
{
    public partial class Ejercicio4_2 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            string Usuario;
            Usuario = Request["txtUsuario"].ToString();
            lblBienvenida.Text = "Bienvenido a mi página sr/a " + Usuario;
        }
    }
}