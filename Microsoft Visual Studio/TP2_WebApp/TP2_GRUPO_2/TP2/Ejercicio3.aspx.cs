using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace TP2
{
    public partial class Ejercicio3 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void lbtnRojo_Click(object sender, EventArgs e)
        {
            lblTexto.ForeColor = System.Drawing.Color.Red;
            lbtnAzul.ForeColor = System.Drawing.Color.Blue;
            lbtnRojo.ForeColor = System.Drawing.Color.DarkMagenta;
            lbtnVerde.ForeColor = System.Drawing.Color.Blue;
        }

        protected void lbtnAzul_Click(object sender, EventArgs e)
        {
            lblTexto.ForeColor = System.Drawing.Color.Blue;
            lbtnAzul.ForeColor = System.Drawing.Color.DarkMagenta;
            lbtnRojo.ForeColor = System.Drawing.Color.Blue;
            lbtnVerde.ForeColor = System.Drawing.Color.Blue;
        }

        protected void lbtnVerde_Click(object sender, EventArgs e)
        {
            lblTexto.ForeColor = System.Drawing.Color.Green;
            lbtnAzul.ForeColor = System.Drawing.Color.Blue;
            lbtnRojo.ForeColor = System.Drawing.Color.Blue;
            lbtnVerde.ForeColor = System.Drawing.Color.DarkMagenta;
        }
    }
}