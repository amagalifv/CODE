using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace TP2
{
    public partial class Ejercicio5 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void btnCalcularPrecio_Click(object sender, EventArgs e)
        {
            lblPrecioFinal.Text = "";
            double total = 0;
            total += double.Parse(ddlMemoria.SelectedValue);

            foreach (ListItem item in clbAccesorios.Items)
            {
                if(item.Selected)
                {
                    total += double.Parse(item.Value);
                }
            }
            
            lblPrecioFinal.Text = "EL PRECIO FINAL ES $" + total;
        }
    }
}